#ifndef LIGHTCONTEXT_TYPE_H
#define LIGHTCONTEXT_TYPE_H

#include "Color_RGB8.h"
#include <inttypes.h>

typedef struct LightContext {
    /* 0x00 */ struct LightNode* listHead;
    /* 0x04 */ Color_RGB8 ambient;
    /* 0x07 */ Color_RGB8 fog;
    /* 0x0A */ int16_t fogNear;
    /* 0x0C */ int16_t fogFar;
    // int16_t pad
} LightContext; /* sizeof = 0x0E */

#endif

