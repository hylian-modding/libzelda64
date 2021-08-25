#ifdef F3DEX_GBI_2
#undef F3DEX_GBI_2
#endif
#define F3DEX_GBI
#include <libultra/PR/gbi.h>

extern Gfx* gDListHead;
asm("gDListHead = 0x8012A670");

extern Gfx dlToBranchTo;
asm("dlToBranchTo = 0x81C00000");

void TestFunc3(void) {
    gSPDisplayList(gDListHead++, &dlToBranchTo);
}