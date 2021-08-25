#ifndef COLLIDERJNTSPHELEMENT_TYPE_H
#define COLLIDERJNTSPHELEMENT_TYPE_H

#include "ColliderInfo.h"
#include "ColliderJntSphElementDim.h"

typedef struct {
    /* 0x00 */ ColliderInfo info;
    /* 0x28 */ ColliderJntSphElementDim dim;
} ColliderJntSphElement; /* sizeof = 0x40 */

#endif
