#ifndef COLLIDERINIT_TYPE_H
#define COLLIDERINIT_TYPE_H

#include <inttypes.h>

typedef struct ColliderInit {
    /* 0x00 */ uint8_t colType; // Determines hitmarks and sound effects during AC collisions.
    /* 0x01 */ uint8_t atFlags; // Information flags for AT collisions.
    /* 0x02 */ uint8_t acFlags; // Information flags for OC collisions.
    /* 0x03 */ uint8_t ocFlags1; // Information flags for OC collisions.
    /* 0x04 */ uint8_t ocFlags2; // Flags related to which colliders it can OC collide with.
    /* 0x05 */ uint8_t shape; // JntSph, Cylinder, Tris, or Quad
} ColliderInit; /* sizeof = 0x06 */

#endif

