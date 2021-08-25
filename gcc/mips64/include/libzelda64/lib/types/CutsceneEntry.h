#ifndef CUTSCENEENTRY_TYPE_H
#define CUTSCENEENTRY_TYPE_H

#include "../zelda64_version.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

#else /* GAME_VERSION_1_0 */
#warning "CutsceneEntry is not defined for this game version!"

#endif
#elif defined GAME_MM /* GAME_OOT */


typedef struct {
    /* 0x0 */ uint32_t data;
    /* 0x4 */ int16_t unk4;
    /* 0x6 */ uint8_t unk6;
    /* 0x7 */ uint8_t unk7;
} CutsceneEntry; // size = 0x8

#endif /* GAME_MM */

#endif