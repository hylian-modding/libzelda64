#ifndef SPHERE16_TYPE_H
#define SPHERE16_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct Sphere16 {
    /* 0x00 */ Vec3s center;
    /* 0x06 */ int16_t radius;
} Sphere16; /* sizeof = 0x08 */

#endif
