#ifndef LIBC_FUNC_H
#define LIBC_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>

extern int32_t sprintf(char* dst, const char* fmt, ...);
SYMBOL_VERSION_CONFIG(sprintf, 0x800CE7B4, 0x800878A4);

extern void* memcpy(void* dest, void* src, uint32_t length);
SYMBOL_VERSION_CONFIG(memcpy, 0x800D2350, 0x8008F208);

extern void Lib_MemSet(uint8_t* dest, uint32_t size, uint8_t val);
SYMBOL_VERSION_CONFIG(Lib_MemSet, 0x80063630, 0x800FECC0);

extern void bzero(void* begin, int32_t length);
SYMBOL_VERSION_CONFIG(bzero, 0x80000180, 0x80089630);

#endif
