#ifndef ANIMATIONCONTEXT_TYPE_H
#define ANIMATIONCONTEXT_TYPE_H

#include "AnimationEntry.h"
#include <inttypes.h>

#define ANIMATION_ENTRY_MAX 50

typedef struct AnimationContext {
    /* 0x00 */ int16_t animationCount;
    /* 0x04 */ AnimationEntry entires[ANIMATION_ENTRY_MAX];
} AnimationContext; /* 0xC84 */

#endif

