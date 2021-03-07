#ifndef LINEF_TYPE_H
#define LINEF_TYPE_H

#include "Vec3f.h"

typedef struct Linef {
    /* 0x00 */ Vec3f a;
    /* 0x0C */ Vec3f b;
} Linef; /* sizeof = 0x18 */


#endif

