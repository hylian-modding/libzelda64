#ifndef SCALEROTPOS_TYPE_H
#define SCALEROTPOS_TYPE_H

#include "Vec3f.h"
#include "Vec3s.h"

typedef struct ScaleRotPos {
    /* 0x00 */ Vec3f scale;
    /* 0x0C */ Vec3s rot;
    /* 0x10 */ Vec3f pos;
} ScaleRotPos; /* sizeof = 0x1C */

#endif

