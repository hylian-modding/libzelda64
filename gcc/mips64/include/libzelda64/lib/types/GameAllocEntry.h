#ifndef GAMEALLOCENTRY_TYPE_H
#define GAMEALLOCENTRY_TYPE_H

#include <inttypes.h>

typedef struct GameAllocEntry {
    /* 0x00 */ struct GameAllocEntry* next;
    /* 0x04 */ struct GameAllocEntry* prev;
    /* 0x08 */ uint32_t size;
    /* 0x0C */ uint32_t dummy;
} GameAllocEntry; /* sizeof = 0x10 */

#endif
