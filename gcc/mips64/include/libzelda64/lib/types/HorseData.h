#ifndef HORSEDATA_TYPE_H
#define HORSEDATA_TYPE_H

#include <inttypes.h>
#include "Vec3s.h"

typedef struct {
    /* 0x00 */ int16_t scene;
    /* 0x02 */ Vec3s pos;
    /* 0x08 */ int16_t angle;
} HorseData; /* sizeof = 0x0A */

#endif

