#ifndef COLLIDERJNTSPHELEMENTDIMINIT_TYPE_H
#define COLLIDERJNTSPHELEMENTDIMINIT_TYPE_H

#include "Sphere16.h"
#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint8_t limb; // attached limb
    /* 0x02 */ Sphere16 modelSphere; // model space sphere
    /* 0x0A */ int16_t scale; // world space sphere = model * scale * 0.01
} ColliderJntSphElementDimInit; /* sizeof = 0x0C */

#endif

