#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/CollisionPoly.h>
#include <libzelda64/lib/types/DynaSSNodeList.h>
#include <libzelda64/lib/types/Vec3s.h>

extern volatile DynaSSNodeList* gNodeList;
asm("gNodeList = 0x12345678");

extern volatile uint32_t* gNodeListMax;
asm("gNodeListMax = 0x43215678");

#ifdef GAME_OOT
void SuperDynaSSNodeList_Alloc(GlobalContext* globalCtx, DynaSSNodeList* nodeList, int32_t max) {
    nodeList->tbl = gNodeList;
    nodeList->max = *gNodeListMax;
    nodeList->count = 0;
}
#elif defined GAME_MM
// TODO?
void SuperDynaSSNodeList_Alloc(GlobalContext* globalCtx, DynaSSNodeList* nodeList, int32_t max) {}
#endif

