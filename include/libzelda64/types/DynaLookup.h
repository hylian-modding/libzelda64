#ifndef DYNALOOKUP_TYPE_H
#define DYNALOOKUP_TYPE_H

#include "SSList.h"
#include <inttypes.h>

typedef struct DynaLookup {
    /* 0x00 */ uint16_t polyStartIndex;
    /* 0x02 */ SSList ceiling;
    /* 0x04 */ SSList wall;
    /* 0x06 */ SSList floor;
} DynaLookup; /* sizeof = 0x08 */

#endif
