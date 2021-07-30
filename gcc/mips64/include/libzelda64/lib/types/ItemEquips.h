#ifndef ITEMEQUIPS_TYPE_H
#define ITEMEQUIPS_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint8_t buttonItems[4];
    /* 0x04 */ uint8_t cButtonSlots[3];
    /* 0x08 */ uint16_t equipment;
} ItemEquips; /* sizeof = 0x0A */

#endif

