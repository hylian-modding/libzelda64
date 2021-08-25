#ifndef WATERBOX_TYPE_H
#define WATERBOX_TYPE_H

#include <inttypes.h>

// 0x0008_0000 = ?
// 0x0007_E000 = Room Index, 0x3F = all rooms
// 0x0000_1F00 = Lighting Settings Index
// 0x0000_00FF = CamData index

typedef struct WaterBox {
    /* 0x00 */ int16_t xMin;
    /* 0x02 */ int16_t ySurface;
    /* 0x04 */ int16_t zMin;
    /* 0x06 */ int16_t xLength;
    /* 0x08 */ int16_t zLength;
    /* 0x0C */ uint32_t properties;
} WaterBox; /* sizeof = 0x10 */

#endif
