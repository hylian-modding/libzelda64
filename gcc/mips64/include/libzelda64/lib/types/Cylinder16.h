#ifndef CYLINDER16_TYPE_H
#define CYLINDER16_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct Cylinder16 {
    /* 0x0000 */ int16_t radius;
    /* 0x0002 */ int16_t height;
    /* 0x0004 */ int16_t yShift;
    /* 0x0006 */ Vec3s pos;
} Cylinder16; /* sizeof = 0x0C */

#endif

