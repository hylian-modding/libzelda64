#ifndef COLLIDERINITTOACTOR_TYPE_H
#define COLLIDERINITTOACTOR_TYPE_H

#include <inttypes.h>

typedef struct ColliderInitToActor {
    /* 0x00 */ struct Actor* actor;
    /* 0x04 */ uint8_t atFlags; // Information flags for AT collisions.
    /* 0x05 */ uint8_t acFlags; // Information flags for AC collisions.
    /* 0x06 */ uint8_t ocFlags1; // Information flags for OC collisions.
    /* 0x07 */ uint8_t shape;   // JntSph, Cylinder, Tris, or Quad
} ColliderInitToActor; /* sizeof = 0x08 */

#endif

