#ifndef ANIMATIONHEADERCOMMON_TYPE_H
#define ANIMATIONHEADERCOMMON_TYPE_H

#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct AnimationHeaderCommon {
    /* 0x00 */ int16_t frameCount;
} AnimationHeaderCommon; /* sizeof = 0x02 */

#else /* GAME_VERSION_1_0 */
#warning "AnimationHeaderCommon is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ int16_t frameCount;
    /* 0x02 */ int16_t unk02;
} AnimationHeaderCommon; /* sizeof = 0x04 */
#endif                /* GAME_MM */

#endif
