#ifndef ENTRANCEENTRY_TYPE_H
#define ENTRANCEENTRY_TYPE_H

#include <inttypes.h>

typedef struct EntranceEntry {
    /* 0x00 */ uint8_t spawn;
    /* 0x01 */ uint8_t room;
} EntranceEntry; /* sizeof = 0x02 */

#endif
