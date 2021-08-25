#ifndef ANIMATIONHEADERCOMMON_TYPE_H
#define ANIMATIONHEADERCOMMON_TYPE_H

#include "../zelda64_version.h"
#include <inttypes.h>
#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

typedef struct AnimationHeaderCommon {
    /* 0x00 */ int16_t frameCount;
} AnimationHeaderCommon; /* sizeof = 0x02 */

#else /* GAME_VERSION_1_0 */
#warning "AnimationEntry is not defined for this game version!"

#endif
#elif defined GAME_MM /* GAME_OOT */

typedef struct {
    /* 0x000 */ int16_t frameCount;
    /* 0x002 */ int16_t unk02;
} AnimationHeaderCommon; // size = 0x4

#endif /* GAME_MM */

#endif
