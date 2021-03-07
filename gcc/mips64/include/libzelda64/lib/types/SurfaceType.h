#ifndef SURFACETYPE_TYPE_H
#define SURFACETYPE_TYPE_H

#include <inttypes.h>

// Type 1
// 0x0800_0000 = wall damage

typedef struct SurfaceType {
    /* 0x00 */ uint32_t data[2];
} SurfaceType; /* sizeof = 0x08 */

#endif