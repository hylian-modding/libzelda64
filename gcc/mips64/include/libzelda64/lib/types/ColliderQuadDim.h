#ifndef COLLIDERQUADDIM_TYPE_H
#define COLLIDERQUADDIM_TYPE_H

#include "Vec3f.h"
#include "Vec3s.h"

typedef struct ColliderQuadDim {
    /* 0x00 */ Vec3f quad[4];
    /* 0x30 */ Vec3s dcMid; // midpoint of vectors d, c
    /* 0x36 */ Vec3s baMid; // midpoint of vectors b, a
    /* 0x3C */ float acDist; // distance to nearest AC collision this frame.
} ColliderQuadDim; /* sizeof = 0x40 */

#endif

