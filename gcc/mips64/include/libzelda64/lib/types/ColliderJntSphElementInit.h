#ifndef COLLIDERJNTSPHELEMENTINIT_TYPE_H
#define COLLIDERJNTSPHELEMENTINIT_TYPE_H

#include "ColliderInfoInit.h"
#include "ColliderJntSphElementDimInit.h"

typedef struct {
    /* 0x00 */ ColliderInfoInit info;
    /* 0x18 */ ColliderJntSphElementDimInit dim;
} ColliderJntSphElementInit; /* sizeof = 0x24 */

#endif

