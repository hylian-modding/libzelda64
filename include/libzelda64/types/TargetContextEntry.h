#ifndef TARGETCONTEXTENTRY_TYPE_H
#define TARGETCONTEXTENTRY_TYPE_H

#include "Color_RGBA8_u32.h"
#include "Vec3f.h"

typedef struct TargetContextEntry {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ float radius;
    /* 0x10 */ Color_RGBA8 color;
} TargetContextEntry; /* sizeof = 0x14 */

#endif
