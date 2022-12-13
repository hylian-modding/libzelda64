#include "shop.h"

void init(entity_t* this, GlobalContext* globalCtx) {
    this->shop.start = 0xBEEFDEAD;

    this->actor.room = 0xFF;
    this->shop.shopStatus = 0x1;

    Actor_SetScale(this, 0.01f);
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, this, &colliderInit);
    this->collider.dim.radius = 12;

    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.y = 0;
    this->actor.shape.rot.z = 0;

    this->actor.flags |= 0x0E000075;
    
    this->shop.end = 0xDEADBEEF;
}

void update(entity_t* this, GlobalContext* globalCtx) {
    Collider_UpdateCylinder(this, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
    Actor_UpdateBgCheckInfo(globalCtx, this, 26.0f, ageProperties_38[1], ageProperties_00[1], 5);

    this->actor.focus.pos = this->actor.world.pos;
    this->actor.focus.rot = this->actor.world.rot;

    if (this->shop.changeToPending){
        this->shop.base = this->shop.changeToPending;
        this->shop.changeToPending = 0;
        SkelAnime_InitLink_Custom(globalCtx, &this->skelAnime.skeleton,
            baseToPointerSkel2(this, 0x500C),
            0,
            9, /* initflags */
            this->skelAnime.jointTable, this->skelAnime.morphTable, PLAYER_LIMB_MAX
        );
    }else if (this->shop.shopStatus){
        switch(this->shop.shopStatus){
            case 0:
                
                break;
            case 1:
                this->shop.base = baseToPointer(this, 0);
                SkelAnime_InitLink_Custom(globalCtx, &this->skelAnime.skeleton,
                    baseToPointerSkel2(this, 0x500C),
                    0,
                    9, /* initflags */
                    this->skelAnime.jointTable, this->skelAnime.morphTable, PLAYER_LIMB_MAX
                );
                memcpy(&this->skelAnime.jointTable, &__tpose_anim, __tpose_anim_size);
                break;
        }
        this->shop.shopStatus = 0;
    }
}

int32_t AnimateCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3f* pos, Vec3s* rot, entity_t* this) {
    return 0;
}

int32_t FaceCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, entity_t* this) {
    
    gSPSegment(POLY_OPA_DISP++, 8, baseToPointer2(this, 0x0));
    gSPSegment(POLY_OPA_DISP++, 9, baseToPointer2(this, 0x00004000));
    return 1;
}

void draw(entity_t* this, GlobalContext* globalCtx) {
    switch(this->shop.shopMode){
        case 0:
            gDPSetEnvColor(globalCtx->game.gfxCtx->polyOpa.p++, this->shop.colorTunic.r, this->shop.colorTunic.g, this->shop.colorTunic.b, this->shop.colorTunic.a);
            SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime.skeleton.skeleton, this->skelAnime.jointTable, this->skelAnime.skeleton.dListCount, &AnimateCallback, &FaceCallback, this);
        break;
    }
}

void destroy(entity_t* this, GlobalContext* globalCtx) {
    this->shop.start = 0x0;
    this->shop.end = 0x0;
}

const ActorInit initVars = {
    .id = 5,
    .category = ACTORLIST_CATEGORY_NPC,
    .flags = 0x00002431,
    .objectId = 1,
    .instanceSize = sizeof(entity_t),
    .init = init,
    .destroy = destroy,
    .update = update,
    .draw = draw
};
// 👌