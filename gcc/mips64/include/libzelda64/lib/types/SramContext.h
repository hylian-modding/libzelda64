#ifndef SRAMCONTEXT_TYPE_H
#define SRAMCONTEXT_TYPE_H

#include <inttypes.h>

typedef struct SramContext {
    /* 0x00 */ uint8_t readBuff;
} SramContext; /* sizeof = 0x04 */

#endif

