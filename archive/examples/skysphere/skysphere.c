#include "skysphere.h"
#include "skysphereobj.h"

void init(En_Skysphere* this, GlobalContext* globalCtx) {
    this->actor.room = 0xFF;
    this->scale = 2.0f;
    Actor_SetScale(this, this->scale);
    this->mode = (uint32_t)(*((uint8_t*)&this->actor.home.rot));
    this->rotationSpeed = 0.04f;
    this->rotationSpeedInner = 0.08f;
    this->rotationSpeedOuter = 0.06f;
    this->cloudsLayerTopSpeed = 0.007f;
    this->cloudsLayerBottomSpeed = 0.014f;
    this->rotationInner = 0.0f;
    this->rotationOuter = 0.0f;

    for (int32_t index = 0; index < CLOUDCOUNT; index++) {
        float percent = index / (float)CLOUDCOUNT;
        ResetCloud(this, index, CLOUDLAYER_TOP);
        this->cloudsLayerTop[index] = percent;

        ResetCloud(this, index, CLOUDLAYER_BOTTOM);
        this->cloudsLayerBottom[index] = percent;
    }

    this->actor.world.pos = Vec3f_Zero;
}

void destroy(En_Skysphere* this, GlobalContext* globalCtx) {}

void update(En_Skysphere* this, GlobalContext* globalCtx) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    float dir = this->mode == SKYMODE_SPHERECLOCKWISE ? 1.0f : -1.0f;

    Actor_SetScale(this, this->scale);

    this->actor.world.rot.y += (short)((this->rotationSpeed * dir) * DEG2S);
    this->actor.shape.rot.y = this->actor.world.rot.y;
    this->rotationInner += this->rotationSpeedInner * dir;
    this->rotationOuter += this->rotationSpeedOuter * -dir;
    this->actor.world.pos = player->actor.world.pos;
    this->actor.world.pos.y += 240.0f;
}

void ResetCloud(En_Skysphere* this, int32_t index, int32_t layer) {
    // bottom
    if (layer) {
        this->cloudsLayerBottom[index] = 0.0f;
        this->cloudsLayerBottomX[index] = Rand_ZeroOne();
    }
    // top
    else {
        this->cloudsLayerTop[index] = 0.0f;
        this->cloudsLayerTopX[index] = Rand_ZeroOne();
    }
}

void DrawClouds(En_Skysphere* this, GlobalContext* globalCtx) {
    int32_t index;

    for (index = 0; index < CLOUDCOUNT; index++) {
        Matrix_RotateRPY(0, 0, 0, MTXMODE_NEW);
        Matrix_Translate((this->cloudsLayerTopX[index] * CLOUDWIDE) - HCLOUDWIDE, -index * 3, (this->cloudsLayerTop[index] * CLOUDRANGE) - HCLOUDRANGE, MTXMODE_NEW);

        this->cloudsLayerTop[index] += this->cloudsLayerTopSpeed * 0.01f;
        if (this->cloudsLayerTop[index] > 1.0f) ResetCloud(this, index, CLOUDLAYER_TOP);

        Gfx_DrawDListOpa(globalCtx, DL_BIRDSEYECLOUDSTOP);

        Matrix_RotateRPY(0, 0, 0, MTXMODE_NEW);
        Matrix_Translate((this->cloudsLayerBottomX[index] * CLOUDWIDE) - HCLOUDWIDE, -index * 3, (this->cloudsLayerBottom[index] * CLOUDRANGE) - HCLOUDRANGE, MTXMODE_NEW);

        this->cloudsLayerBottom[index] += this->cloudsLayerBottomSpeed * 0.01f;
        if (this->cloudsLayerBottom[index] > 1.0f) ResetCloud(this, index, CLOUDLAYER_BOTTOM);

        Gfx_DrawDListOpa(globalCtx, DL_BIRDSEYECLOUDSBOTTOM);
    }
}

void draw(En_Skysphere* this, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, DL_SKY);

    Matrix_RotateRPY(0, (short)(this->rotationOuter * DEG2S), 0, MTXMODE_NEW);
    Gfx_DrawDListOpa(globalCtx, DL_OUTERCLOUD);

    Matrix_RotateRPY(0, (short)(this->rotationInner * DEG2S), 0, MTXMODE_NEW);
    Gfx_DrawDListOpa(globalCtx, DL_INNERCLOUD);

    DrawClouds(this, globalCtx);
}

const ActorInit initVars = {
    .id = 5,
    .category = ACTORLIST_CATEGORY_NPC,
    .flags = 0x00000030,
    .objectId = 1,
    .instanceSize = sizeof(En_Skysphere),
    .init = init,
    .destroy = destroy,
    .update = update,
    .draw = draw
};


