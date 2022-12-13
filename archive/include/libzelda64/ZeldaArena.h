#ifndef ZELDAARENA_FUNC_H
#define ZELDAARENA_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>

typedef enum {
    /* 0 */ ALLOCTYPE_NORMAL,
    /* 1 */ ALLOCTYPE_ABSOLUTE,
    /* 2 */ ALLOCTYPE_PERMANENT
} AllocType;

extern void* ZeldaArena_Malloc(uint32_t size);
SYMBOL_VERSION_CONFIG(ZeldaArena_Malloc, 0x80066C10, 0x80102C60);

extern void* ZeldaArena_MallocR(uint32_t size);
SYMBOL_VERSION_CONFIG(ZeldaArena_MallocR, 0x80066C38, 0x80102C88);

extern void* ZeldaArena_Free(void* addr);
SYMBOL_VERSION_CONFIG(ZeldaArena_Free, 0x80066C90, 0x80102CE0);

extern void Overlay_Relocate(void* allocatedVRamAddress, struct OverlayRelocationSection* overlayInfo, void* vRamAddress);
SYMBOL_VERSION_CONFIG(Overlay_Relocate, 0x800CC8F0, 0x800849A0);

extern int32_t Overlay_Load(uint32_t vRomStart, uint32_t vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
SYMBOL_VERSION_CONFIG(Overlay_Load, 0x800CCBB8, 0x800BACD4);

#endif
