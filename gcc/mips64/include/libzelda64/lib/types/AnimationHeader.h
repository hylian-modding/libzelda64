#ifndef ANIMATIONHEADER_TYPE_H
#define ANIMATIONHEADER_TYPE_H

#include "AnimationHeaderCommon.h"
#include <inttypes.h>

typedef struct AnimationHeader {
    /* 0x00 */ AnimationHeaderCommon common;
    /* 0x04 */ int16_t* frameData;         // "tbl"
    /* 0x08 */ struct JointIndex* jointIndices; // "ref_tbl"
    /* 0x0C */ uint16_t staticIndexMax;
} AnimationHeader; /* sizeof = 0x10 */

#endif

