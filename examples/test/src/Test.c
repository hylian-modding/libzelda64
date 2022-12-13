#include "Test.h"
#include <zelda64_common/common_library.h>

__attribute__((section(".data"))) char tag[0xC] = "z64common";
__attribute__((section(".data"))) LibZelda64_Common_Imports* common = NULL;

void EnTest_Construct(EnTest* thisx, PlayState* play) {
    common->memset_fast_8(thisx, 0, sizeof(EnTest));
    thisx->deadbeef = 0xDEADBEEF;
    thisx->timer = 0;
    thisx->foodbad = 0xF00D0BAD;
}

void EnTest_Deconstruct(EnTest* thisx, PlayState* play) {
}

void EnTest_Update(EnTest* thisx, PlayState* play) {
    thisx->timer++;
}

void EnTest_Draw(EnTest* thisx, PlayState* play) {
}

const ActorInit gENTEST_INIT = {
    /* id       */ 1,
    /* category */ ACTORCAT_NPC,
    /* flags    */ ACTOR_FLAG_4,
    /* obj id   */ 1,
    /* size     */ sizeof(EnTest),
    /* init     */ EnTest_Construct,
    /* destroy  */ EnTest_Deconstruct,
    /* update   */ EnTest_Update,
    /* draw     */ EnTest_Draw
};

