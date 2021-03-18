#ifndef HELPERS_FUNCS_H
#define HELPERS_FUNCS_H

#include "MagicNumbers.h"
#include <libzelda64/lib/Macros.h>
#include <libzelda64/lib/Math.h>
#include <inttypes.h>

static inline uint32_t Seg2Ram(uint32_t addr) {
    return (AVAL((RAM_SEGMENT_TABLE + (addr >> 22)), uint32_t, 0) + (addr & 0x00FFFFFF)) | 0x80000000;
}

static inline unsigned char Helper_EyeBlink(int16_t* frame) {
    if (*frame == 0) {
        *frame = Math_Rand_S16Offset(30, 30);
    }

    *frame -= 1;

    if (*frame > 1) {
        return 0;
    }

    return 2 - *frame;
}

#endif