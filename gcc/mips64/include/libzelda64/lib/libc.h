#ifndef LIBC_FUNC_H
#define LIBC_FUNC_H

#include <inttypes.h>

extern int32_t sprintf(char* dst, const char* fmt, ...);
asm("sprintf = 0x800CE7B4");

extern void* memcpy(void* dest, void* src, uint32_t length);
asm("memcpy = 0x800D2350");

extern void Lib_MemSet(uint8_t* dest, uint32_t size, uint8_t val);
asm("Lib_MemSet = 0x80063630");

#endif

