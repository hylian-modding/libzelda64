#ifndef RESPAWNDATA_TYPE_H
#define RESPAWNDATA_TYPE_H

#include "../zelda64_version.h"
#include "Vec3f.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ int16_t yaw;
    /* 0x0E */ int16_t playerParams;
    /* 0x10 */ int16_t entranceIndex;
    /* 0x12 */ uint8_t roomIndex;
    /* 0x13 */ int8_t data;
    /* 0x14 */ uint32_t tempSwchFlags;
    /* 0x18 */ uint32_t tempCollectFlags;
} RespawnData; /* sizeof = 0x1C */

#else /* GAME_VERSION_1_0 */
#warning "Actor is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ int16_t yaw;
    /* 0x0E */ int16_t playerParams;
    /* 0x10 */ int16_t entranceIndex;
    /* 0x12 */ uint8_t roomIndex;
    /* 0x13 */ int8_t data;
    /* 0x14 */ uint32_t tempSwchFlags;
    /* 0x18 */ uint32_t unk_18;
    /* 0x1C */ uint32_t tempCollectFlags;
} RespawnData; /* sizeof = 0x20 */
#endif                /* GAME_MM */


#endif
