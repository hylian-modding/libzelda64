#ifndef DMAMGR_FUNC_H
#define DMAMGR_FUNC_H

#include "inttypes.h"

extern int32_t DmaMgr_SendRequest0(uint32_t ram, uint32_t vrom, uint32_t size);
asm("DmaMgr_SendRequest0 = 0x80000DF0");

#endif

