#ifndef ANIMATIONENTRY_TYPE_H
#define ANIMATIONENTRY_TYPE_H

#include "../zelda64_version.h"
#include "AnimationEntryData.h"
#include <inttypes.h>
typedef enum { ANIMENTRY_LOADFRAME, ANIMENTRY_COPYALL, ANIMENTRY_INTERP, ANIMENTRY_COPYTRUE, ANIMENTRY_COPYFALSE, ANIMENTRY_MOVEACTOR } AnimationType;

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

typedef struct AnimationEntry {
    /* 0x00 */ uint8_t type;
    /* 0x04 */ AnimationEntryData data;
} AnimationEntry; /* sizeof = 0x40 */

#else /* GAME_VERSION_1_0 */
#warning "AnimationEntry is not defined for this game version!"

#endif
#elif defined GAME_MM /* GAME_OOT */

typedef struct {
    /* 0x000 */ uint8_t type;
    /* 0x001 */ uint8_t unk01;
    /* 0x004 */ AnimationEntryData types;
} AnimationEntry; // size = 0x40

#endif /* GAME_MM */

#endif
