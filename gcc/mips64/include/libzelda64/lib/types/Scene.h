#ifndef SCENE_TYPE_H
#define SCENE_TYPE_H

#include "RomFile.h"
#include <inttypes.h>

typedef struct Scene {
    /* 0x00 */ RomFile sceneFile;
    /* 0x08 */ RomFile titleFile;
    /* 0x10 */ uint8_t unk_0x10;
    /* 0x11 */ uint8_t config;
    /* 0x12 */ uint8_t unk_0x12;
    /* 0x13 */ uint8_t unk_0x13;
} Scene; /* sizeof = 0x14 */

#endif
