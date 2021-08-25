#ifndef VIEWPORT_TYPE_H
#define VIEWPORT_TYPE_H

#include <inttypes.h>

typedef struct Viewport {
    /* 0x00 */ int32_t topY;
    /* 0x04 */ int32_t bottomY;
    /* 0x08 */ int32_t leftX;
    /* 0x0C */ int32_t rightX;
} Viewport; /* sizeof = 0x10 */

#endif
