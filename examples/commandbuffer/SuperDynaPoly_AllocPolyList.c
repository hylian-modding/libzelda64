#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/CollisionPoly.h>
#include <libzelda64/lib/types/Vec3s.h>

extern volatile CollisionPoly* gPolyList;
asm("gPolyList = 0x12345678");

#ifdef GAME_OOT
void SuperDynaPoly_AllocPolyList(GlobalContext* globalCtx, CollisionPoly** polyList, int32_t numPolys) {
    *polyList = gPolyList;
}
#elif defined GAME_MM
// TODO?
void SuperDynaPoly_AllocPolyList(GlobalContext* globalCtx, CollisionPoly** polyList, int32_t numPolys) {}
#endif

