#ifndef PATH_TYPE_H
#define PATH_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct Path {
    /* 0x00 */ uint8_t count;
    /* 0x01 */ uint8_t _pad[3];
    /* 0x04 */ struct Vec3s* points;
} Path; /* sizeof = 0x08 */


#endif

