#ifndef LIBZELDA64_COMMON_INTTYPES_H
#define LIBZELDA64_COMMON_INTTYPES_H

#include <z64version.h>

#if TARGET_GAME==Z64GAME_OOT
#include <ultra64/ultratypes.h>
#elif TARGET_GAME==Z64GAME_MM
#include <PR/ultratypes.h>
#endif

typedef u32 SIZE_TYPE;

#endif

