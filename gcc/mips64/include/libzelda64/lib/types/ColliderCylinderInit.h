#ifndef COLLIDERCYLINDERINIT_TYPE_H
#define COLLIDERCYLINDERINIT_TYPE_H

#include "ColliderInit.h"
#include "ColliderInfoInit.h"
#include "Cylinder16.h"

typedef struct ColliderCylinderInit {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ Cylinder16 dim;
} ColliderCylinderInit; /* sizeof = 0x2C */

#endif

