#ifndef COLLIDERJNTSPHELEMENTDIM_TYPE_H
#define COLLIDERJNTSPHELEMENTDIM_TYPE_H

#include "Sphere16.h"
#include <inttypes.h>

typedef struct {
    /* 0x00 */ Sphere16 modelSphere; // model space sphere
    /* 0x08 */ Sphere16 worldSphere; // world space sphere
    /* 0x10 */ float scale;          // world space sphere = model * scale * 0.01
    /* 0x14 */ uint8_t limb;         // attached limb
} ColliderJntSphElementDim; /* sizeof = 0x18 */

#endif

