#ifndef LIBZELDA64_COMMON_STRING_H
#define LIBZELDA64_COMMON_STRING_H

#include "inttypes.h"
#include "typegenerator.h"

// handwritten
EXPORT(void, memset_fast_8, void* dest, u8 value, SIZE_TYPE length);
EXPORT(void, memset_fast_16, void* dest, u16 value, SIZE_TYPE length);
EXPORT(void, memset_fast_32, void* dest, u32 value, SIZE_TYPE length);
EXPORT(void, memset_fast_64, void* dest, u64 value, SIZE_TYPE length);

// compiled
EXPORT(s32, memcmp, const u8* lhs, const u8* rhs, SIZE_TYPE length);
EXPORT(s32, strncmp, const u8* lhs, const u8* rhs, SIZE_TYPE length);
EXPORT(s32, atoi, const char* str);
EXPORT(s64, atol, const char* str);


#endif

