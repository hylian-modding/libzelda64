#ifndef LIGHTS_TYPE_H
#define LIGHTS_TYPE_H

#include <inttypes.h>
#include <PR/gbi.h>

typedef struct Lights {
    /* 0x00 */ uint8_t numLights;
    /* 0x08 */ Lightsn l;
} Lights; /* sizeof = 0x80 */

#endif
