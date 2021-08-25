#ifndef LIGHTCONTEXT_TYPE_H
#define LIGHTCONTEXT_TYPE_H

#include "../zelda64_version.h"
#include "Color_RGB8.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

typedef struct LightContext {
    /* 0x00 */ struct LightNode* listHead;
    /* 0x04 */ Color_RGB8 ambient;
    /* 0x07 */ Color_RGB8 fog;
    /* 0x0A */ int16_t fogNear;
    /* 0x0C */ int16_t fogFar;
    // int16_t pad
} LightContext; /* sizeof = 0x0E */

#else /* GAME_VERSION_1_0 */
#warning "STRUCT is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct LightContext {
    /* 0x0 */ struct LightNode* listHead;
    /* 0x4 */ Color_RGB8 ambient;
    /* 0x7 */ Color_RGB8 fog;
    /* 0x8 */ uint8_t unk8;
    /* 0x9 */ uint8_t unk9;
    /* 0xA */ int16_t fogNear;
    /* 0xC */ int16_t fogFar;
} LightContext; /* sizeof = 0x10 */
#endif                /* GAME_MM */

#endif
