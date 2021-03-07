#ifndef COLOR_RGBA8_U32_TYPE_H
#define COLOR_RGBA8_U32_TYPE_H

#include <inttypes.h>

typedef union {
    struct {
        /* 0x00 */ uint8_t r;
        /* 0x01 */ uint8_t g;
        /* 0x02 */ uint8_t b;
        /* 0x03 */ uint8_t a;
    };

    /* 0x00 */ uint32_t rgba;
} Color_RGBA8_u32; /* sizeof = 0x04 */

#endif

