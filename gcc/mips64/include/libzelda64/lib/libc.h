#ifndef LIBC_FUNC_H
#define LIBC_FUNC_H

#include <inttypes.h>

extern void* memcpy(void* dest, void* src, uint32_t length);
asm("memcpy = 0x800D2350");

#endif

