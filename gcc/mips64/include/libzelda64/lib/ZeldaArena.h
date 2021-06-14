#ifndef ZELDAARENA_FUNC_H
#define ZELDAARENA_FUNC_H

#include <inttypes.h>

typedef enum {
    /* 0 */ ALLOCTYPE_NORMAL,
    /* 1 */ ALLOCTYPE_ABSOLUTE,
    /* 2 */ ALLOCTYPE_PERMANENT
} AllocType;

extern void* ZeldaArena_Malloc(uint32_t size);
asm("ZeldaArena_Malloc = 0x80066C10");

extern void* ZeldaArena_MallocR(uint32_t size);
asm("ZeldaArena_MallocR = 0x80066C38");

extern void* ZeldaArena_Free(void* addr);
asm("ZeldaArena_Free = 0x80066C90");

extern void Overlay_Relocate(void* allocatedVRamAddress, struct OverlayRelocationSection* overlayInfo, void* vRamAddress);
asm("Overlay_Relocate = 0x800CC8F0");

extern int32_t Overlay_Load(uint32_t vRomStart, uint32_t vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
asm("Overlay_Load = 0x800CCBB8");

#endif

