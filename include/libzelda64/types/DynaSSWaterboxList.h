#ifndef DYNASSWATERBOXLIST_TYPE_H
#define DYNASSWATERBOXLIST_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x0 */ uint8_t pad0[0x4];
    /* 0x4 */ struct WaterBox* boxes;
} DynaSSWaterboxList; /* sizeof = 0x08 */

#endif
