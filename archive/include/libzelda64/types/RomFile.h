#ifndef ROMFILE_TYPE_H
#define ROMFILE_TYPE_H

#include "../zelda64_version.h"
#include <inttypes.h>

typedef struct RomFile {
    /* 0x00 */ uint32_t vromStart;
    /* 0x04 */ uint32_t vromEnd;
} RomFile;

extern RomFile gObjectTable[];
SYMBOL_VERSION_CONFIG(gObjectTable, 0x800F8FF0, 0x801C2740);

#endif