#ifndef POSROT_TYPE_H
#define POSROT_TYPE_H

#include "Vec3f.h"
#include "Vec3s.h"

typedef struct PosRot {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3s rot;
    // /* 0x12 */ short _pad;
} PosRot; /* sizeof = 0x14 */


#endif
