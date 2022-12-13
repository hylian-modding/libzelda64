#ifndef DMAMGR_FUNC_H
#define DMAMGR_FUNC_H

#include "types/DmaRequest.h"
#include "zelda64_version.h"
#include <inttypes.h>
#include <ultra64.h>

extern int32_t DmaMgr_SendRequest0(uint32_t ram, uint32_t vrom, uint32_t size);
SYMBOL_VERSION_CONFIG(DmaMgr_SendRequest0, 0x80000DF0, 0x80000180);

extern int32_t DmaMgr_SendRequestImpl(DmaRequest* req, uint32_t ram, uint32_t vrom, uint32_t size, uint32_t unk, OSMesgQueue* queue, OSMesg msg);
SYMBOL_VERSION_CONFIG(DmaMgr_SendRequestImpl, 0x80000D28, 0x80000180);

#endif
