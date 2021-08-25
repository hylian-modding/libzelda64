#ifndef ANIMATEDMATERIAL_TYPE_H
#define ANIMATEDMATERIAL_TYPE_H

#include <inttypes.h>

// Might have a oot alternative
typedef struct {
    /* 0x0 */ int8_t segment;
    /* 0x2 */ int16_t type;
    /* 0x4 */ void* params;
} AnimatedMaterial; /* sizeof = 0x08 */

#endif
