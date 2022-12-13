#ifndef ANIMATIONCONTEXT_TYPE_H
#define ANIMATIONCONTEXT_TYPE_H

#include "AnimationEntry.h"
#include <inttypes.h>
#define ANIMATION_ENTRY_MAX 50

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct AnimationContext {
    /* 0x00 */ int16_t animationCount;
    /* 0x04 */ AnimationEntry entires[ANIMATION_ENTRY_MAX];
} AnimationContext; /* 0xC84 */

#else /* GAME_VERSION_1_0 */
#warning "AnimationContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct AnimationContext {
    /* 0x000 */ int16_t animationCount;
    /* 0x002 */ char unk02[2];
    /* 0x004 */ AnimationEntry entries[ANIMATION_ENTRY_MAX];
} AnimationContext; /* size = 0xC84 */
#endif                /* GAME_MM */

#endif
