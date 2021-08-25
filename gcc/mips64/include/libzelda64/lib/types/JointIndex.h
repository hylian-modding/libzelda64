#ifndef JOINTINDEX_TYPE_H
#define JOINTINDEX_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint16_t x;
    /* 0x02 */ uint16_t y;
    /* 0x04 */ uint16_t z;
} JointIndex; /* sizeof = 0x06 */

#endif
