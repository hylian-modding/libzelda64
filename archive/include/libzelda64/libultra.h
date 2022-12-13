#ifndef LIBULTRA_FUNC_H
#define LIBULTRA_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>
#include <ultra64.h>

// extern void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, int32_t count);
SYMBOL_VERSION_CONFIG(osCreateMesgQueue, 0x80004220, 0x80000180);

// extern int32_t osRecvMesg(OSMesgQueue* mq, OSMesg* msg, int32_t flag);
SYMBOL_VERSION_CONFIG(osRecvMesg, 0x80002030, 0x80000180);

extern void guMtxIdentF(float mf[4][4]);
SYMBOL_VERSION_CONFIG(guMtxIdentF, 0x800D0830, 0x8008B600);

extern void guMtxIdent(Mtx* m);
SYMBOL_VERSION_CONFIG(guMtxIdent, 0x800D08B8, 0x8008FA60);

extern void guTranslate(Mtx* m, float x, float y, float z);
SYMBOL_VERSION_CONFIG(guTranslate, 0x800D3338, 0x80093CC0);

#endif
