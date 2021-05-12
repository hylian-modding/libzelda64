#ifndef CLIB_FUNC_H
#define CLIB_FUNC_H

#include <inttypes.h>

extern int32_t sprintf(char* dst, const char* fmt, ...);
asm("sprintf = 0x800CE7B4");

#endif