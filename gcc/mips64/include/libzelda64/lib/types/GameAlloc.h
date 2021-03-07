#ifndef GAMEALLOC_TYPE_H
#define GAMEALLOC_TYPE_H

#include "GameAllocEntry.h"

typedef struct GameAlloc {
    /* 0x00 */ GameAllocEntry base;
    /* 0x10 */ GameAllocEntry* head;
} GameAlloc; /* sizeof = 0x14 */

#endif

