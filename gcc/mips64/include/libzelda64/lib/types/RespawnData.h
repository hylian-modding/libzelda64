#ifndef RESPAWNDATA_TYPE_H
#define RESPAWNDATA_TYPE_H

#include <inttypes.h>
#include "Vec3f.h"

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

#endif

