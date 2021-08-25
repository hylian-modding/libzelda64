#ifndef WEAPONINFO_TYPE_H
#define WEAPONINFO_TYPE_H

#include "Vec3f.h"
#include <inttypes.h>

typedef struct WeaponInfo {
    /* 0x00 */ int32_t active;
    /* 0x04 */ Vec3f tip;
    /* 0x10 */ Vec3f base;
} WeaponInfo; /* sizeof = 0x1C */

#endif
