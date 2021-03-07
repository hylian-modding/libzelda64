#ifndef ENVIRONMENTLIGHTDATA_TYPE_H
#define ENVIRONMENTLIGHTDATA_TYPE_H

#include "LightParams.h"
#include <inttypes.h>

typedef struct EnvironmentLightData {
    /* 0x00 */ int8_t type;
    /* 0x01 */ LightParams status;
} EnvironmentLightData; /* sizeof = 0x0E */

#endif

