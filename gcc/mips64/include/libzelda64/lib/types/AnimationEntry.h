#ifndef ANIMATIONENTRY_TYPE_H
#define ANIMATIONENTRY_TYPE_H

#include "AnimationEntryData.h"
#include <inttypes.h>

typedef enum {
    ANIMENTRY_LOADFRAME,
    ANIMENTRY_COPYALL,
    ANIMENTRY_INTERP,
    ANIMENTRY_COPYTRUE,
    ANIMENTRY_COPYFALSE,
    ANIMENTRY_MOVEACTOR
} AnimationType;

typedef struct AnimationEntry {
    /* 0x00 */ uint8_t type;
    /* 0x04 */ AnimationEntryData data;
} AnimationEntry; /* sizeof = 0x40 */


#endif

