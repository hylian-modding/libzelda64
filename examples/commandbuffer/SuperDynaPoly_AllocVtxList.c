#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/CollisionPoly.h>
#include <libzelda64/lib/types/Vec3s.h>

extern volatile Vec3s* gVtxList;
asm("gVtxList = 0x12345678");

__attribute__ ((aligned (0x20)))
void SuperDynaPoly_AllocVtxList(GlobalContext* globalCtx, Vec3s** vtxList, int32_t numVtx) {
    *vtxList = gVtxList;
}

