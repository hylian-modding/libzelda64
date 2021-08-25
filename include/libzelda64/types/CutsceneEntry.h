#ifndef CUTSCENEENTRY_TYPE_H
#define CUTSCENEENTRY_TYPE_H

#include <inttypes.h>

#ifdef GAME_OOT
#warning "CutsceneEntry is not defined for this game version!"
#elif defined GAME_MM /* GAME_OOT */
typedef struct CutsceneEntry {
    /* 0x00 */ uint32_t data;
    /* 0x04 */ int16_t unk4;
    /* 0x06 */ uint8_t unk6;
    /* 0x07 */ uint8_t unk7;
} CutsceneEntry; /* sizeof = 0x08 */
#endif                /* GAME_MM */

#endif