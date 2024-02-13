 	 // ***************************************************************************************
// ***************************************************************************************
//
//      Name :      sprites.cpp
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      4th January 2024
//      Reviewed :  No
//      Purpose :   Sprite drawing code.
//
// ***************************************************************************************
// ***************************************************************************************

#include "common.h"

static int16_t spriteVisibleCount; 												// How many currently visible ?
static int16_t turtleSpriteID = -1; 											// Sprite allocated to rotation
static int16_t turtleRotation = 0; 												// Rotation of turtle.
static int16_t turtleColour = 7; 												// Turtle drawing colour.

// ***************************************************************************************
//
//									Sprite data
//
// ***************************************************************************************

static SPRITE_INTERNAL sprites[MAX_SPRITES];
static uint8_t turtleImage[16*16/2];

// ***************************************************************************************
//
//								 Anchor positions
//
// ***************************************************************************************

static const int16_t anchorX[] = { 	1,
	0,1,2,
	0,1,2,
	0,1,2,
};

static const int16_t anchorY[] = { 	1,
	2,2,2,
	1,1,1,
	0,0,0
};

// ***************************************************************************************
//
//								 Triangle bitmap data
//
// ***************************************************************************************

#include "data/triangle.h"

// ***************************************************************************************
//
//										Reset a sprites
//
// ***************************************************************************************

static void _SPRResetSprite(int n) {
	SPRITE_INTERNAL *p = &sprites[n];  											// Set everything to default values.
	p->isDrawn = p->isVisible = false;
	p->xc = p->yc = p->x = p->y = -1;
	p->imageSize = 0xFF;
	p->anchor = p->flip = 0;
	p->xSize = p->ySize = 0;	
}

// ***************************************************************************************
//
//									Reset all sprites
//
// ***************************************************************************************

bool SPRSpritesInUse(void) {
	return spriteVisibleCount > 0;
}

// ***************************************************************************************
//
//									Reset all sprites
//
// ***************************************************************************************

void SPRResetAll(void) {
	for (int i = 0;i < MAX_SPRITES;i++) {  										// Reset all sprites.
		_SPRResetSprite(i);
	}
	turtleSpriteID = -1;turtleRotation = 0;turtleColour = 7; 					// Reset turtle setup
}

// ***************************************************************************************
//
//							Reset all sprites and clear display
//
// ***************************************************************************************

void SPRReset(void) {
	spriteVisibleCount = 0;
	SPRResetAll();  	
	for (int i = 0;i < gMode.xGSize * gMode.yGSize;i++) {  						// Clear the sprite layer
		gMode.graphicsMemory[i] &= 0x0F;  										// top 4 bits og graphics memory.
	}
}

// ***************************************************************************************
//
//				Set the current sprite, rotation and colour for the turtle
//
// ***************************************************************************************

void SPRSetTurtleSprite(int16_t spriteID,int16_t rotation,int16_t colour) {
	turtleSpriteID = spriteID;
	while (rotation < 0) rotation += 360;
	turtleRotation = rotation % 360;
	turtleColour = colour & 0xF;
}

// ***************************************************************************************
//
//						Set up structure for sprite action
//
// ***************************************************************************************

static void SPRSetupAction(SPRITE_ACTION *sa,SPRITE_INTERNAL *p) {
	sa->display = gMode.graphicsMemory + p->x + p->y*gMode.xGSize; 				// Work out the draw address top left of sprite.
	sa->image = p->imageAddress; 												// Where graphic data comes from.
	sa->x = p->x;sa->y = p->y;  												// Coordinates
	sa->xSize = p->xSize;sa->ySize = p->ySize;  								// Size and flip.
	sa->flip = p->flip;
}

// ***************************************************************************************
//
//									Hide a sprite
//
// ***************************************************************************************

static SPRITE_ACTION saHide;

void SPRHide(uint8_t *paramData) {
	int spriteID = *paramData;  												// Sprite ID
	if (spriteID < MAX_SPRITES) {  												// Legit ?
		SPRITE_INTERNAL *s = &sprites[spriteID];
		if (s->isDrawn) {  														// If drawn, erase it and mark not drawn.
			SPRSetupAction(&saHide,s);
			SPRPHYErase(&saHide);
			sprites[spriteID].isDrawn = false;
			spriteVisibleCount--;
		}
		sprites[spriteID].isVisible = false;  									// Mark not visible.
	}
}

// ***************************************************************************************
//
//								Get sprite position.
//
// ***************************************************************************************

uint8_t SPRGetSpriteData(uint8_t *param) {
	if (*param >= MAX_SPRITES) return 1; 										// Bad sprite #
	SPRITE_INTERNAL *p = &sprites[*param];										// Sprite structure
	param[1] = p->xc & 0xFF;param[2] = p->xc >> 8;
	param[3] = p->yc & 0xFF;param[4] = p->yc >> 8;
	return 0;
}

// ***************************************************************************************
//
//					 Unpack turtle graphic for given angle
//
// ***************************************************************************************

static uint8_t *SPRUnpackTurtleGraphic(uint16_t angle) {
	uint8_t *gfx = turtleImage;
	for (int i = 0;i < 16;i++) {  												// One 16 bit bitmap at a time.
		uint16_t bits = triangleBitData[angle * 16 + i];  						// Get bit pattern
		for (int j = 0;j < 8;j++) {  											// 2 colours per pixel
			uint8_t b = 0;
			if (bits & 0x8000) b |= (turtleColour << 4);
			if (bits & 0x4000) b |= (turtleColour & 0x0F);
			*gfx++ = b;
			bits = bits << 2;
		}
	}
	return turtleImage;
}
// ***************************************************************************************
//
//								Update a sprite
//
// ***************************************************************************************

static SPRITE_ACTION saRemove,saDraw;

int SPRUpdate(uint8_t *paramData) {

	uint8_t spriteID = paramData[0];  											// Sprite ID
	if (spriteID >= MAX_SPRITES) return 1;  									// Invalid

	uint16_t x = paramData[1] + (paramData[2] << 8);  							// Extract new data.
	uint16_t y = paramData[3] + (paramData[4] << 8);
	uint8_t  imageSize = paramData[5];
	uint8_t flip = paramData[6];
	uint8_t anchor = paramData[7];
	
	SPRITE_INTERNAL *p = &sprites[spriteID];  									// Pointer to sprite structures

	bool xyChanged = ((x & 0xFF00) != 0x8000) && (p->x != x || p->y != y); 		// Check to see if elements changed.
	bool isChanged = (imageSize != 0x80) && (imageSize != p->imageSize);
	bool flipChanged = (flip != 0x80) && (flip != p->flip);
	bool anchorChanged = (anchor != 0x80) && (anchor != p->anchor);
	bool isTurtle = (spriteID == turtleSpriteID);

	//printf("Sprite #%d to (%d,%d) ImSize:%x Flip:%x Anchor:%d %d %d %d %d @ %d,%d %d:%d\n",
	// 	*paramData,x,y,paramData[5],paramData[6],paramData[7],xyChanged,isChanged,flipChanged,anchorChanged,p->x,p->y,p->isVisible,p->isDrawn);

	if (xyChanged || isChanged || flipChanged || anchorChanged || isTurtle) {  	// Some change made.
		if (p->isDrawn) {  														// Erase if currently drawn
			SPRSetupAction(&saRemove,p);
			SPRPHYErase(&saRemove);
			spriteVisibleCount--;
			p->isDrawn = false;
		}

		if (flipChanged) { 														// Flip has changed
			p->flip = flip; 
		}									

		if (anchorChanged) {  													// Anchor has changed.
			if (anchor > 9) return 1;  											// Bad anchor.
			p->anchor = anchor;
		}

		if (isChanged != 0 && isTurtle == 0) {  								// Image or size changed, not turtle
			p->imageSize = imageSize;  											// Update image size.
			p->xSize = p->ySize = (imageSize & 0x40) ? 32:16;   				// Size of image.
			int img = GFXFindImage((p->xSize == 16) ? 1 : 2,imageSize & 0x3F);	// Address of image (offset in gfx memory)													
			if (img < 0) return 2;   											// Bad image number
			p->imageAddress = gfxMemory + img;  								// Physical address
		}

		if (isTurtle) {  														// If the turtle sprite
			p->imageSize = p->xSize = p->ySize = 16;   							// Set up as the correct size.
			p->imageAddress = SPRUnpackTurtleGraphic(turtleRotation);
		}

		if (xyChanged) {  														// Positions changed.
			p->x = x - anchorX[p->anchor] * p->xSize / 2;   					// Initially anchor point is centre.
			p->y = y - anchorY[p->anchor] * p->ySize / 2;
			p->xc = x;p->yc = y;  												// Remember centre position
			p->isVisible = true;
			//printf("changed %d %d %d\n",p->x,p->y,p->isVisible);
		}

		if (p->isVisible) {  													// Redraw if possible.
			SPRSetupAction(&saDraw,p);
			SPRPHYDraw(&saDraw);
			spriteVisibleCount++;
			p->isDrawn = true;  												// And mark as drawn.
		}
	}

	return 0; 
}

// ***************************************************************************************
//
//								Collision check
//
// ***************************************************************************************

uint8_t SPRCollisionCheck(uint8_t *error,uint8_t s1,uint8_t s2,uint8_t distance) {
	if (s1 >= MAX_SPRITES || s2 >= MAX_SPRITES) { 								// Validate parameters
		*error = 1;
		return 0;
	}
	SPRITE_INTERNAL *p1 = &sprites[s1],*p2 = &sprites[s2]; 						// Structure pointers.
	int sdist = (p1->xc-p2->xc)*(p1->xc-p2->xc)+(p1->yc-p2->yc)*(p1->yc-p2->yc);// Square of distance
	return sdist <= distance*distance;
}

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//		12-01-24	Changed initial image size to $FF as not picked up if sprite initialise to $80
//		15/01/24 	Fixes for better sprite clipping
//					Not setting x,y on saRemove caused issues.
//		16/01/24 	Added SpriteVisibleCount functionality.
//		23/01/24 	Rationalised SPRITE_ACTION initialisation code.
//					Added turtle rendering on demand code.
//
// ***************************************************************************************
