#ifndef COLLISIONCHECKINFOINIT2_TYPE_H
#define COLLISIONCHECKINFOINIT2_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint8_t health;
    /* 0x02 */ int16_t cylRadius;
    /* 0x04 */ int16_t cylHeight;
    /* 0x06 */ int16_t cylYShift;
    /* 0x08 */ uint8_t mass;
} CollisionCheckInfoInit2; /* sizeof = 0x09 */

#endif
