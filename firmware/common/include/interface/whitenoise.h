// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      whitenoise.h
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      12th August 2024
//      Reviewed :  No
//      Purpose :   White noise data (actually the Vic 20)
//					Not part of common.h as it's constant data for white noise.
//
// ***************************************************************************************
// ***************************************************************************************

#ifndef _WNOISE_H
#define _WNOISE_H

#define NOISE_SIZE 	(1024)

static const uint8_t noisepattern[NOISE_SIZE] = {
      7, 30, 30, 28, 28, 62, 60, 56,120,248,124, 30, 31,143,  7,  7,193,192,224,
    241,224,240,227,225,192,224,120,126, 60, 56,224,225,195,195,135,199,  7, 30,
     28, 31, 14, 14, 30, 14, 15, 15,195,195,241,225,227,193,227,195,195,252, 60,
     30, 15,131,195,193,193,195,195,199,135,135,199, 15, 14, 60,124,120, 60, 60,
     60, 56, 62, 28,124, 30, 60, 15, 14, 62,120,240,240,224,225,241,193,195,199,
    195,225,241,224,225,240,241,227,192,240,224,248,112,227,135,135,192,240,224,
    241,225,225,199,131,135,131,143,135,135,199,131,195,131,195,241,225,195,199,
    129,207,135,  3,135,199,199,135,131,225,195,  7,195,135,135,  7,135,195,135,
    131,225,195,199,195,135,135,143, 15,135,135, 15,207, 31,135,142, 14,  7,129,
    195,227,193,224,240,224,227,131,135,  7,135,142, 30, 15,  7,135,143, 31,  7,
    135,193,240,225,225,227,199, 15,  3,143,135, 14, 30, 30, 15,135,135, 15,135,
     31, 15,195,195,240,248,240,112,241,240,240,225,240,224,120,124,120,124,112,
    113,225,225,195,195,199,135, 28, 60, 60, 28, 60,124, 30, 30, 30, 28, 60,120,
    248,248,225,195,135, 30, 30, 60, 62, 15, 15,135, 31,142, 15, 15,142, 30, 30,
     30, 30, 15, 15,143,135,135,195,131,193,225,195,193,195,199,143, 15, 15, 15,
     15,131,199,195,193,225,224,248, 62, 60, 60, 60, 60, 60,120, 62, 30, 30, 30,
     15, 15, 15, 30, 14, 30, 30, 15, 15,135, 31,135,135, 28, 62, 31, 15, 15,142,
     62, 14, 62, 30, 28, 60,124,252, 56,120,120, 56,120,112,248,124, 30, 60, 60,
     48,241,240,112,112,224,248,240,248,120,120,113,225,240,227,193,240,113,227,
    199,135,142, 62, 14, 30, 62, 15,  7,135, 12, 62, 15,135, 15, 30, 60, 60, 56,
    120,241,231,195,195,199,142, 60, 56,240,224,126, 30, 62, 14, 15, 15, 15,  3,
    195,195,199,135, 31, 14, 30, 28, 60, 60, 15,  7,  7,199,199,135,135,143, 15,
    192,240,248, 96,240,240,225,227,227,195,195,195,135, 15,135,142, 30, 30, 63,
     30, 14, 28, 60,126, 30, 60, 56,120,120,120, 56,120, 60,225,227,143, 31, 28,
    120,112,126, 15,135,  7,195,199, 15, 30, 60, 14, 15, 14, 30,  3,240,240,241,
    227,193,199,192,225,225,225,225,224,112,225,240,120,112,227,199, 15,193,225,
    227,195,192,240,252, 28, 60,112,248,112,248,120, 60,112,240,120,112,124,124,
     60, 56, 30, 62, 60,126,  7,131,199,193,193,225,195,195,195,225,225,240,120,
    124, 62, 15, 31,  7,143, 15,131,135,193,227,227,195,195,225,240,248,240, 60,
    124, 60, 15,142, 14, 31, 31, 14, 60, 56,120,112,112,240,240,248,112,112,120,
     56, 60,112,224,240,120,241,240,120, 62, 60, 15,  7, 14, 62, 30, 63, 30, 14,
     15,135,135,  7, 15,  7,199,143, 15,135, 30, 30, 31, 30, 30, 60, 30, 28, 62,
     15,  3,195,129,224,240,252, 56, 60, 62, 14, 30, 28,124, 30, 31, 14, 62, 28,
    120,120,124, 30, 62, 30, 60, 31, 15, 31, 15, 15,143, 28, 60,120,248,240,248,
    112,240,120,120, 60, 60,120, 60, 31, 15,  7,134, 28, 30, 28, 30, 30, 31,  3,
    195,199,142, 60, 60, 28, 24,240,225,195,225,193,225,227,195,195,227,195,131,
    135,131,135, 15,  7,  7,225,225,224,124,120, 56,120,120, 60, 31, 15,143, 14,
      7, 15,  7,131,195,195,129,240,248,241,224,227,199, 28, 62, 30, 15, 15,195,
    240,240,227,131,195,199,  7, 15, 15, 15, 15, 15,  7,135, 15, 15, 14, 15, 15,
     30, 15, 15,135,135,135,143,199,199,131,131,195,199,143,135,  7,195,142, 30,
     56, 62, 60, 56,124, 31, 28, 56, 60,120,124, 30, 28, 60, 63, 30, 14, 62, 28,
     60, 31, 15,  7,195,227,131,135,129,193,227,207, 14, 15, 30, 62, 30, 31, 15,
    143,195,135, 14,  3,240,240,112,224,225,225,199,142, 15, 15, 30, 14, 30, 31,
     28,120,240,241,241,224,241,225,225,224,224,241,193,240,113,225,195,131,199,
    131,225,225,248,112,240,240,240,240,240,112,248,112,112, 97,224,240,225,224,
    120,113,224,240,248, 56, 30, 28, 56,112,248, 96,120, 56, 60, 63, 31, 15, 31,
     15, 31,135,135,131,135,131,225,225,240,120,241,240,112, 56, 56,112,224,227,
    192,224,248,120,120,248, 56,241,225,225,195,135,135, 14, 30, 31, 14, 14, 15,
     15,135,195,135,  7,131,192,240, 56, 60, 60, 56,240,252, 62, 30, 28, 28, 56,
    112,240,241,224,240,224,224,241,227,224,225,240,240,120,124,120, 60,120,120,
     56,120,120,120,120,112,227,131,131,224,195,193,225,193,193,193,227,195,199,
     30, 14, 31, 30, 30, 15, 15, 14, 14, 14,  7,131,135,135, 14,  7,143, 15, 15,
     15, 14, 28,112,225,224,113,193,131,131,135, 15, 30, 24,120,120,124, 62, 28,
     56,240,225,224,120,112, 56, 60, 62, 30, 60, 30, 28,112, 60, 56, 63
};

#endif

// ***************************************************************************************
//
//		Date 		Revision
//		==== 		========
//
// ***************************************************************************************
