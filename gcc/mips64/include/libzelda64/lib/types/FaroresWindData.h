#ifndef FARORESWINDDATA_TYPE_H
#define FARORESWINDDATA_TYPE_H

#include "Vec3i.h"
#include <inttypes.h>

typedef struct FaroresWindData {
    /* 0x00 */ Vec3i pos;
    /* 0x0C */ int32_t yaw;
    /* 0x10 */ int32_t playerParams;
    /* 0x14 */ int32_t entranceIndex;
    /* 0x18 */ int32_t roomIndex;
    /* 0x1C */ int32_t set;
    /* 0x20 */ int32_t tempSwchFlags;
    /* 0x24 */ int32_t tempCollectFlags;
} FaroresWindData; /* sizeof = 0x28 */

#endif
