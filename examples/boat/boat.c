#include "boat.h"
#include <libzelda64/lib/types/ActorInit.h>

void init(En_Boat* this, GlobalContext* globalCtx) {
    CollisionHeader* colHeader;
    this->dyna.actor.room = 0xFF;

    DynaPolyActor_Init(&this->dyna, DPM_PLAYER);
    //CollisionHeader_GetVirtual(0, &colHeader); // I dont think we need this?
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->actor, colHeader);

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &colliderInit);

    Actor_SetScale(this, 0.5f);

    this->tAccel = Vec3f_Zero;
    this->rAccel = Vec3f_Zero;
    this->waterAccel = Vec3f_Zero;
    this->windAccel = Vec3f_Zero;
}

void destroy(En_Boat* this, GlobalContext* globalCtx) {

}

void update(En_Boat* this, GlobalContext* globalCtx) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    float currentTime = ((float)globalCtx->gameplayFrames) * 0.05f;
    float tAccel;
    float rAccel;
    float tSpeed;
    float rSpeed;
    Vec3f right;
    Vec3f up;
    Vec3f forward;
    Vec3f focus;
    Vec3f orbit;
    Vec3f temp;

    up = Vec3f_New(0, 1, 0);

    forward = Vec3f_New(
        Math_CosS(this->actor.world.rot.x) * Math_SinS(this->actor.world.rot.y),
        Math_SinS(this->actor.world.rot.x),
        Math_CosS(this->actor.world.rot.x) * Math_CosS(this->actor.world.rot.y)
    );

    Math3D_Vec3f_Cross(&forward, &up, &right);

    if ((globalCtx->game.input[0].cur.button & (1 << BUT_IDX_RT)) != 0) {
        player->stateFlags1 = 0x20000000;
        globalCtx->mainCamera.mode = CAM_MODE_STILL;
        globalCtx->mainCamera.setting = CAM_SET_FREE0;

        temp = Vec3f_New(0, ((float)globalCtx->game.input[0].cur.stick_x / 80.0f) / 0.5235f, 0);
        Math3D_Vec3f_AddV(&this->rVel, &temp, &this->rVel);

        rSpeed = Math3D_Vec3fMagnitudeSq(&this->rVel);
        Math3D_Vec3f_DivF(&this->rVel, rSpeed, &this->rVel);

        rSpeed -= (10.0f / 80.0f) / 0.5235f;

        if (rSpeed > 1.0f / SQ(0.5235f)) rSpeed = 1.0f / SQ(0.5235f);

        Math3D_Vec3f_MulF(&this->rVel, rSpeed, &this->rVel);

        tAccel = Math3D_Vec3fMagnitudeSq(&this->tAccel);
        rAccel = Math3D_Vec3fMagnitudeSq(&this->rAccel);

        if (tAccel < SQ(MAX_ACCEL_UNSCALED)) {
            tAccel += MAX_ACCEL_UNSCALED / MAX_SPEED_UNSCALED;
        }
        else {
            tAccel = SQ(MAX_ACCEL_UNSCALED);
        }

        Math3D_Vec3f_MulF(&forward, tAccel, &this->tAccel);
        Math3D_Vec3f_AddV(&this->tVel, &this->tAccel, &this->tVel);

        tSpeed = Math3D_Vec3fMagnitudeSq(&this->tVel);

        // limit speed, apply "friction"
        if (tSpeed > 0) tSpeed -= MAX_FRICT_UNSCALED;
        if (tSpeed < 0) tSpeed = 0;
        if (tSpeed > SQ(MAX_SPEED_UNSCALED)) tSpeed = MAX_SPEED_UNSCALED;

        Math3D_Vec3f_MulF(&this->tVel, tSpeed, &this->tVel);

        Math3D_Vec3f_AddV(&this->actor.world.pos, &this->tVel, &this->actor.world.pos);
        this->actor.world.rot.y += (int16_t)(this->rVel.y * (32768.0f / 3.141592f));

        temp = Vec3f_New(0, 50.0f, 0);
        Math3D_Vec3f_AddV(&this->actor.world.pos, &temp, &focus);

        Math3D_Vec3f_MulF(&forward, -MAX_ORBIT_DIST, &orbit);
        Math3D_Vec3f_AddV(&orbit, &temp, &orbit);

        globalCtx->mainCamera.at = focus;
        globalCtx->mainCamera.eye = orbit;
    }
    else if (player->stateFlags1 == 0x20000000) {
        globalCtx->mainCamera.mode = CAM_MODE_NORMAL;
        globalCtx->mainCamera.setting = CAM_SET_NORMAL0;
        player->stateFlags1 = 0;
    }
}

void draw(En_Boat* this, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, Rope_Seg);
    Gfx_DrawDListOpa(globalCtx, Ship_Seg);
    Gfx_DrawDListOpa(globalCtx, Ladder_Seg);
    Gfx_DrawDListOpa(globalCtx, Extra_Seg);
}


const ActorInit initVars = {
    .id = 1,
    .category = ACTORLIST_CATEGORY_NPC,
    .flags = 0x00000010,
    .objectId = 1,
    .instanceSize = sizeof(En_Boat),
    .init = init,
    .destroy = destroy,
    .update = update,
    .draw = draw
};
