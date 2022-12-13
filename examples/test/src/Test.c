#include "Test.h"

void EnTest_Construct(EnTest* thisx, PlayState* play) {
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
    .id = 1,
    .category = ACTORCAT_NPC,
    .flags = ACTOR_FLAG_4,
    .objectId = 1,
    .instanceSize = sizeof(EnTest),
    .init = EnTest_Construct,
    .destroy = EnTest_Deconstruct,
    .update = EnTest_Update,
    .draw = EnTest_Draw
};

