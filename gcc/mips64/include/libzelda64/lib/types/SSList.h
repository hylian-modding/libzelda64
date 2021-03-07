#ifndef SSLIST_TYPE_H
#define SSLIST_TYPE_H

#include <inttypes.h>

typedef struct SSList {
    /* 0x00 */ uint16_t head; // first SSNode index
} SSList; /* sizeof = 0x2 */


#endif

