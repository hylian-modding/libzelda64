#ifndef LIBULTRA_FUNC_H
#define LIBULTRA_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>
#include <libultra/ultra64.h>

// extern void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, int32_t count);
SYMBOL_VERSION_CONFIG(osCreateMesgQueue, 0x80004220, 0x80000180);

// extern int32_t osRecvMesg(OSMesgQueue* mq, OSMesg* msg, int32_t flag);
SYMBOL_VERSION_CONFIG(osRecvMesg, 0x80002030, 0x80000180);

#endif
