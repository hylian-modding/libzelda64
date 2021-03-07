#ifndef COLLIDERQUAD_TYPE_H
#define COLLIDERQUAD_TYPE_H

#include "Collider.h"
#include "ColliderInfo.h"
#include "ColliderQuadDim.h"

typedef struct ColliderQuad {
    /* 0x00 */ Collider base;
    /* 0x18 */ ColliderInfo info;
    /* 0x40 */ ColliderQuadDim dim;
} ColliderQuad; /* sizeof = 0x80 */

#endif

