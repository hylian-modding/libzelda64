#ifndef ROMFILE_TYPE_H
#define ROMFILE_TYPE_H

#include <inttypes.h>

typedef struct RomFile {
    /* 0x00 */ uint32_t vromStart;
    /* 0x04 */ uint32_t vromEnd;
} RomFile;


#endif