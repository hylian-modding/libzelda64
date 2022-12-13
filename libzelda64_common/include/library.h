#ifndef LIBZELDA64_COMMON_LIBRARY_H
#define LIBZELDA64_COMMON_LIBRARY_H

#include "string.h"

typedef struct {
    u32 header;

    pfn_memset_fast_8 memset_fast_8;
    pfn_memset_fast_16 memset_fast_16;
    pfn_memset_fast_32 memset_fast_32;
    pfn_memset_fast_64 memset_fast_64;
    pfn_memcmp memcmp;
    pfn_strncmp strncmp;
    pfn_atoi atoi;
    pfn_atol atol;

    u32 footer;
} LibZelda64_Common_Imports;

extern const LibZelda64_Common_Imports gImports;

#endif

