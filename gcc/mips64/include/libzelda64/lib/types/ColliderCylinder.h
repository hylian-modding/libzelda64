#ifndef COLLIDERCYLINDER_TYPE_H
#define COLLIDERCYLINDER_TYPE_H

#include "Collider.h"
#include "ColliderInfo.h"
#include "Cylinder16.h"

typedef struct ColliderCylinder {
    /* 0x00 */ Collider base;
    /* 0x18 */ ColliderInfo info;
    /* 0x40 */ Cylinder16 dim;
} ColliderCylinder; /* size = 0x4C */

#endif

