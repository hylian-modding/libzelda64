#ifndef LIGHTINFO_TYPE_H
#define LIGHTINFO_TYPE_H

#include "LightParams.h"
#include <inttypes.h>

typedef struct LightInfo {
    /* 0x00 */ uint8_t type;
    /* 0x02 */ LightParams params;
} LightInfo; /* sizeof = 0xE */

#endif
