#ifndef SAVEDSCENEFLAGS_TYPE_H
#define SAVEDSCENEFLAGS_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint32_t chest;
    /* 0x04 */ uint32_t swch;
    /* 0x08 */ uint32_t clear;
    /* 0x0C */ uint32_t collect;
    /* 0x10 */ uint32_t unk;
    /* 0x14 */ uint32_t rooms;
    /* 0x18 */ uint32_t floors;
} SavedSceneFlags; /* sizeof = 0x1C */

#endif

