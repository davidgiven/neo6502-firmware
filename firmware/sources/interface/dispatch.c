// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      dispatch.c
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      22nd November 2023
//      Reviewed :  No
//      Purpose :   Message dispatcher
//
// ***************************************************************************************
// ***************************************************************************************

#include "common.h"
#include "data/prompt.h"

#define DCOMMAND    (cBlock+0)
#define DFUNCTION   (cBlock+1)
#define DERROR      (cBlock+2)
#define DSTATUS     (cBlock+3)
#define DPARAMS     (cBlock+4)

#define float_abs(n) (((n) < 0.0) ? -(n):(n))

// ***************************************************************************************
//
//							Handle commands sent by message
//
// ***************************************************************************************

void __time_critical_func(DSPHandler)(uint8_t *cBlock, uint8_t *memory) {
    float f1,f2;
    int i1,i2;
    uint32_t u1;
    *DERROR = 0;                                                                // Clear error state.
    #include "data/dispatch_code.h"  
    *DCOMMAND = 0;					     										// Clear the message indicating completion.
}

// ***************************************************************************************
//
//     	  Polling code. Called at low repeat rate. About every 64k cycles is right.
//
// ***************************************************************************************

void __time_critical_func(DSPSync)(void) {
    KBDSync();
}

// ***************************************************************************************
//
//     	  		Reset interfaces. Called at start, and also on command 0,0
//
// ***************************************************************************************

void DSPReset(void) {
    const char bootString[] = PROMPT;
    MEMInitialiseMemory();                                                      // Set up memory, load kernel ROM
    GFXSetMode(0);                                                              // Initialise graphics
    const char *c = bootString;
    while (*c != '\0') CONWrite(*c++);	
    KBDInitialise();                                                            // Initialise keyboard & USB system.
    KBDEvent(0,0xFF,0);                                                         // Reset the keyboard manager
    SNDInitialise();                                                            // Initialise sound
}

// ***************************************************************************************
//
//      Date        Revision
//      ====        ========
//
// ***************************************************************************************
