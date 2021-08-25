#ifndef CYLINDER16_TYPE_H
#define CYLINDER16_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct Cylinder16 {
    /* 0x00 */ int16_t radius;
    /* 0x02 */ int16_t height;
    /* 0x04 */ int16_t yShift;
    /* 0x06 */ Vec3s pos;
} Cylinder16; /* sizeof = 0x0C */

#endif
