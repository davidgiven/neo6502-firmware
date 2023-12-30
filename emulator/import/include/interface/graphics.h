// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      graphics.h
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      21st November 2023
//      Reviewed :  No
//      Purpose :   Graphics mode manager include
//
// ***************************************************************************************
// ***************************************************************************************

#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#define MAXCONSOLEWIDTH  	(80) 	 											// Max console size 
#define MAXCONSOLEHEIGHT  	(31)
#define MAXGRAPHICSMEMORY 	(320 * 240)  										// Max byte memory , graphics
#define MAXCONSOLEMEMORY 	(MAXCONSOLEWIDTH * (MAXCONSOLEHEIGHT+1))			// Max byte memory, console text.
																				// (extra line for scrolling.)
struct GraphicsMode {
	uint16_t xCSize,yCSize;														// Size of console (chars)
	uint16_t xGSize,yGSize;														// Size of console (pixels) [0,0 = no graphics]
	uint8_t  fontWidth,fontHeight;  											// Font size in pixels.
	uint8_t  xCursor,yCursor;  													// Cursor position
	uint8_t  foreCol,backCol;  													// Current colours
	uint8_t *graphicsMemory,*consoleMemory;  									// Graphics & text memory.
	uint8_t  isExtLine[MAXCONSOLEHEIGHT]; 										// True if console is extended line.

	void  (*setPalette)(uint8_t,uint8_t,uint8_t,uint8_t); 						// Set the palette
	void  (*startMode)(struct GraphicsMode *); 									// Start up the mode.
};

void RNDSetPalette(uint8_t colour,uint8_t r,uint8_t g,uint8_t b); 				// Implementation specific.
void RNDStartMode0(struct GraphicsMode *gMode);

void GFXSetMode(int Mode);
void GFXResetDefaults(void);
void GFXSetDefaults(uint8_t *cmd);
void GFXFastLine(struct GraphicsMode *gMode,int x, int y, int x2, int y2);
void inline GFXPlotPixel(struct GraphicsMode *gMode,int x,int y);

#endif

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//
// ***************************************************************************************
