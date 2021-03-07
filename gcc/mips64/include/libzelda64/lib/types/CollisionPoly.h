#ifndef COLLISIONPOLY_TYPE_H
#define COLLISIONPOLY_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct CollisionPoly {
    /* 0x00 */ uint16_t type;

    union {
        /* 0x00 */ uint16_t vtxData[3];
        struct {
            /* 0x02 */ uint16_t flags_vIA;  // 0xE000 is poly exclusion flags (xpFlags), 0x1FFF is vtxI
            /* 0x04 */ uint16_t flags_vIB;  // 0xE000 is flags, 0x1FFF is vtxId
                                            // 0x2000 = poly IsConveyor surface
            /* 0x06 */ uint16_t vIC;
        };
    };

    /*0x08 */ Vec3s normal; // Unit normal vector
                            // Value ranges from -0x7FFF to 0x7FFF, representing -1.0 to 1.0; 0x8000 is invalid

    /*0x0E */ int16_t dist; // Plane distance from origin along the normal
} CollisionPoly; /* sizeof = 0x10 */

#endif

