#ifndef VEC3S_TYPE_H
#define VEC3S_TYPE_H

#include <inttypes.h>

typedef struct Vec3s {
    /* 0x00 */ int16_t x;
    /* 0x02 */ int16_t y;
    /* 0x04 */ int16_t z;
} Vec3s, vec3s_t; /* sizeof = 0x06 */

typedef struct Vec3us {
    /* 0x00 */ uint16_t x;
    /* 0x02 */ uint16_t y;
    /* 0x04 */ uint16_t z;
} Vec3us; /* sizeof = 0x06 */

#endif

