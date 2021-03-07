#ifndef TARGETCONTEXTENTRY_TYPE_H
#define TARGETCONTEXTENTRY_TYPE_H

#include "Vec3f.h"
#include "Color_RGB8.h"

typedef struct TargetContextEntry {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ float radius;
    /* 0x10 */ Color_RGB8 color;
} TargetContextEntry; // sizeof = 0x13 */

#endif

