#include "zelda64_common/common_library.h"

const LibZelda64_Common_Imports gImports = (LibZelda64_Common_Imports){
    0xDEADBEEF,

    memset_fast_8,
    memset_fast_16,
    memset_fast_32,
    memset_fast_64,
    memcmp,
    strncmp,
    atoi,
    atol,

    0xBEEFDEAD
};

