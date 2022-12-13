#ifndef SCENE_TYPE_H
#define SCENE_TYPE_H

#include "RomFile.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct Scene {
    /* 0x00 */ RomFile sceneFile;
    /* 0x08 */ RomFile titleFile;
    /* 0x10 */ uint8_t unk_0x10;
    /* 0x11 */ uint8_t config;
    /* 0x12 */ uint8_t unk_0x12;
    /* 0x13 */ uint8_t unk_0x13;
} Scene; /* sizeof = 0x14 */

#else /* GAME_VERSION_1_0 */
#warning "GlobalContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct Scene {
    /* 0x00 */ RomFile segment;
    /* 0x08 */ uint16_t titleTextId;
    /* 0x0A */ uint8_t unk_A;
    /* 0x0B */ uint8_t drawConfig;
    /* 0x0C */ uint8_t unk_C;
} Scene; /* sizeof = 0x10 */
#endif

#endif
