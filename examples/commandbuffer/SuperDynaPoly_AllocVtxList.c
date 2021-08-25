#include <libzelda64/types/GlobalContext.h>
#include <libzelda64/types/CollisionPoly.h>
#include <libzelda64/types/Vec3s.h>

extern volatile Vec3s* gVtxList;
asm("gVtxList = 0x12345678");

#ifdef GAME_OOT
void SuperDynaPoly_AllocVtxList(GlobalContext* globalCtx, Vec3s** vtxList, int32_t numVtx) {
    *vtxList = gVtxList;
}
#elif defined GAME_MM
// TODO?
void SuperDynaPoly_AllocVtxList(GlobalContext* globalCtx, Vec3s** vtxList, int32_t numVtx) {}
#endif

