// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      dispatch.h
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      22nd November 2023
//      Reviewed :  No
//      Purpose :   Message dispatcher
//
// ***************************************************************************************
// ***************************************************************************************

#ifndef _DISPATCH_H
#define _DISPATCH_H

#ifdef PICO
#define WARN_GROUP(group,func) {}
#else
#define WARN_GROUP(group,func) DSPWarnHandler(group,func)
#endif

void DSPHandler(uint8_t *cBlock,uint8_t *memory);
void DSPSync(void);
void DSPReset(void);
char *DSPGetString(uint8_t *command,uint8_t paramOffset);
std::string DSPGetStdString(uint8_t *command,uint8_t paramOffset);
void DSPSetStdString(uint8_t *command,uint8_t paramOffset, const std::string& value);
uint16_t DSPGetInt16(uint8_t *command,uint8_t paramOffset);
uint32_t DSPGetInt32(uint8_t *command,uint8_t paramOffset);
void DSPSetInt16(uint8_t *command,uint8_t paramOffset,uint16_t value);
void DSPSetInt32(uint8_t *command,uint8_t paramOffset,uint32_t value);
void DSPWarnHandler(uint8_t group,uint8_t func);

#endif

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//
// ***************************************************************************************
