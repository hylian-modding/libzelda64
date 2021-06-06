#include "vr_overlord.h"
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/Math.h>
#include <libzelda64/lib/Collider.h>

//TODO: Add to the right file
extern void Matrix_Get(MtxF* dest);
asm("Matrix_Get = 0x800AA740");

extern void Matrix_Put(MtxF* src);
asm("Matrix_Put = 0x800AA764");

extern void Matrix_MultVec3f(Vec3f* src, Vec3f* dest);
asm("Matrix_MultVec3f = 0x800AB958");

extern uint8_t Sword_Attack_Collision_Set(GlobalContext* globalCtx, ColliderQuad* collider, WeaponInfo* weaponDim, Vec3f* newTip, Vec3f* newBase);
asm("Sword_Attack_Collision_Set = 0x8007AF14");

extern void EffectBlure_AddVertex(EffectBlure* this, Vec3f* p1, Vec3f* p2);
asm("EffectBlure_AddVertex = 0x80013F30");

extern void* Effect_GetByIndex(int32_t index);
asm("Effect_GetByIndex = 0x8001A890");

extern void Effect_Add(GlobalContext* globalCtx, int32_t* pIndex, int32_t type, uint8_t arg3, uint8_t arg4, void* initParams);
asm("Effect_Add = 0x8001AA5C");

extern int32_t Collider_InitQuad(GlobalContext* globalCtx, ColliderQuad* collider);
asm("Collider_InitQuad = 0x8004B858");

extern int32_t Collider_SetQuad(GlobalContext* globalCtx, ColliderQuad* collider, Actor* actor, ColliderQuadInit* src);
asm("Collider_SetQuad = 0x8004B960");

extern void Collider_DestroyQuad(GlobalContext* globalCtx, ColliderQuad* collider);
asm("Collider_DestroyQuad = 0x8004B8A8");

extern void Collider_ResetQuadAT(GlobalContext* globalCtx, Collider* collider);
asm("Collider_ResetQuadAT = 0x8004B9C8");

extern void Collider_ResetQuadAC(GlobalContext* globalCtx, Collider* collider);
asm("Collider_ResetQuadAC = 0x8004BA18");

extern void CollisionCheck_SetAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
asm("CollisionCheck_SetAC = 0x8004BF40");

extern void CollisionCheck_SetAT(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
asm("CollisionCheck_SetAT = 0x8004BD50");

extern void Collider_SetQuadVertices(ColliderQuad* collider, Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d);
asm("Collider_SetQuadVertices = 0x80050B64");

extern void OnePointCutscene_DisableAttention(void);
asm("OnePointCutscene_DisableAttention = 0x8006BBE0");

const float RAD2S = (0x8000 / 3.14159f);

void* memcpy(void* dest, const void* src, uint32_t len) {
    char* d = dest;
    const char* s = src;
    while (len--) {
        *d++ = *s++;
    }
    return dest;
}

void Fix_Cutscenes(GlobalContext* globalCtx) {
    OnePointCutscene_DisableAttention();
    globalCtx->roomCtx.curRoom.showInvisActors = 1;
}

void Sword_Update(Vr_Overlord* this, GlobalContext* globalCtx, Vec3f* newTipPos) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    Vec3f newBasePos[3];

    Matrix_MultVec3f(&D_801260A4[0], &newBasePos[0]);
    Matrix_MultVec3f(&D_801260A4[1], &newBasePos[1]);
    Matrix_MultVec3f(&D_801260A4[2], &newBasePos[2]);

    if (Sword_Attack_Collision_Set(globalCtx, NULL, &this->swordInfo[0], &newTipPos[0], &newBasePos[0])) {
        player->stateFlags1 &= ~0x400000;
        EffectBlure_AddVertex(Effect_GetByIndex(this->swordEffectIndex), &this->swordInfo[0].tip, &this->swordInfo[0].base);
    }

    player->stateFlags2 |= 0x20000;
    Sword_Attack_Collision_Set(globalCtx, &this->swordQuads[0], &this->swordInfo[1], &newTipPos[1], &newBasePos[1]);
    Sword_Attack_Collision_Set(globalCtx, &this->swordQuads[1], &this->swordInfo[2], &newTipPos[2], &newBasePos[2]);
}

void Shield_Update(Vr_Overlord* this, GlobalContext* globalCtx, ColliderQuad* collider, Vec3f* quadSrc) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    Vec3f quadDest[4];

    player->stateFlags1 |= 0x400000;

    this->shieldQuad.base.colType = COLTYPE_WOOD; //shieldColTypes[this->rightHand.actionParam - PLAYER_EQUIPMENT_SHIELD_NONE];

    Matrix_MultVec3f(&quadSrc[0], &quadDest[0]);
    Matrix_MultVec3f(&quadSrc[1], &quadDest[1]);
    Matrix_MultVec3f(&quadSrc[2], &quadDest[2]);
    Matrix_MultVec3f(&quadSrc[3], &quadDest[3]);
    Collider_SetQuadVertices(collider, &quadDest[0], &quadDest[1], &quadDest[2], &quadDest[3]);

    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &collider->base);
    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &collider->base);
}

void UnityMatrix_To_Matrix(MtxF* source, MtxF* dest) {
    // Right
    dest->mf[0][0] = source->mf[0][0];
    dest->mf[1][0] = source->mf[0][1];
    dest->mf[2][0] = source->mf[0][2];

    // Up
    dest->mf[0][1] = source->mf[1][0];
    dest->mf[1][1] = source->mf[1][1];
    dest->mf[2][1] = source->mf[1][2];

    // Back
    dest->mf[0][2] = source->mf[2][0];
    dest->mf[1][2] = source->mf[2][1];
    dest->mf[2][2] = source->mf[2][2];
}

void init(Vr_Overlord* this, GlobalContext* globalCtx) {
    this->actor.room = -1;
    this->leftHand.anchorPos = (Vec3f){0, 0, 0};
    this->leftHand.actionParam = PLAYER_AP_SWORD_KOKIRI;
    this->leftHand.gripping = 0;
    this->rightHand.anchorPos = (Vec3f){0, 0, 0};
    this->rightHand.actionParam = 0;
    this->rightHand.gripping = 0;
    this->swordEffectIndex = TOTAL_EFFECT_COUNT;

    Effect_Add(globalCtx, &this->swordEffectIndex, EFFECT_BLURE2, 0, 0, &D_8085470C);

    Collider_InitQuad(globalCtx, &this->swordQuads[0]);
    Collider_SetQuad(globalCtx, &this->swordQuads[0], &this->actor, &D_80854650);
    Collider_InitQuad(globalCtx, &this->swordQuads[1]);
    Collider_SetQuad(globalCtx, &this->swordQuads[1], &this->actor, &D_80854650);
    Collider_InitQuad(globalCtx, &this->shieldQuad);
    Collider_SetQuad(globalCtx, &this->shieldQuad, &this->actor, &D_808546A0);
}

void destroy(Vr_Overlord* this, GlobalContext* globalCtx) {
    Collider_DestroyQuad(globalCtx, &this->swordQuads[0]);
    Collider_DestroyQuad(globalCtx, &this->swordQuads[1]);
    Collider_DestroyQuad(globalCtx, &this->shieldQuad);
}

void update(Vr_Overlord* this, GlobalContext* globalCtx) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    float height = 50.0f;
    if (globalCtx->linkAgeOnLoad) {
        height = 75.0f;
    }

    // climbing
    if (player->stateFlags1 & 0x00200000) {
        Vec3f anchorPos;
        Vec3f move;

        if (this->leftHand.gripping) {
            anchorPos.x = this->leftHand.matrix.mf[0][3];
            anchorPos.y = this->leftHand.matrix.mf[1][3];
            anchorPos.z = this->leftHand.matrix.mf[2][3];

            if (anchorPos.x != this->leftHand.anchorPos.x || anchorPos.y != this->leftHand.anchorPos.y || anchorPos.z != this->leftHand.anchorPos.z) {
                move.x = anchorPos.x - this->leftHand.anchorPos.x;
                move.y = anchorPos.y - this->leftHand.anchorPos.y;
                move.z = anchorPos.z - this->leftHand.anchorPos.z;
                this->leftHand.anchorPos = anchorPos;
            }
            else {
                move.x = 0;
                move.y = 0;
                move.z = 0;
            }

            player->actor.world.pos.x -= move.x * height;
            player->actor.world.pos.y -= move.y * height;
            player->actor.world.pos.z -= move.z * height;
        }
        else if (this->rightHand.gripping) {
            anchorPos.x = this->rightHand.matrix.mf[0][3];
            anchorPos.y = this->rightHand.matrix.mf[1][3];
            anchorPos.z = this->rightHand.matrix.mf[2][3];

            if (anchorPos.x != this->rightHand.anchorPos.x || anchorPos.y != this->rightHand.anchorPos.y || anchorPos.z != this->rightHand.anchorPos.z) {
                move.x = anchorPos.x - this->rightHand.anchorPos.x;
                move.y = anchorPos.y - this->rightHand.anchorPos.y;
                move.z = anchorPos.z - this->rightHand.anchorPos.z;
                this->rightHand.anchorPos = anchorPos;
            }
            else {
                move.x = 0;
                move.y = 0;
                move.z = 0;
            }

            player->actor.world.pos.x -= move.x * height;
            player->actor.world.pos.y -= move.y * height;
            player->actor.world.pos.z -= move.z * height;
        }
        else {
            this->leftHand.anchorPos.x = this->leftHand.matrix.mf[0][3];
            this->leftHand.anchorPos.y = this->leftHand.matrix.mf[1][3];
            this->leftHand.anchorPos.z = this->leftHand.matrix.mf[2][3];
            this->rightHand.anchorPos.x = this->rightHand.matrix.mf[0][3];
            this->rightHand.anchorPos.y = this->rightHand.matrix.mf[1][3];
            this->rightHand.anchorPos.z = this->rightHand.matrix.mf[2][3];
        }
    }
    else {
        this->leftHand.anchorPos.x = this->leftHand.matrix.mf[0][3];
        this->leftHand.anchorPos.y = this->leftHand.matrix.mf[1][3];
        this->leftHand.anchorPos.z = this->leftHand.matrix.mf[2][3];
        this->rightHand.anchorPos.x = this->rightHand.matrix.mf[0][3];
        this->rightHand.anchorPos.y = this->rightHand.matrix.mf[1][3];
        this->rightHand.anchorPos.z = this->rightHand.matrix.mf[2][3];
    }

    Collider_ResetQuadAT(globalCtx, &this->swordQuads[0].base);
    Collider_ResetQuadAT(globalCtx, &this->swordQuads[1].base);
    Collider_ResetQuadAC(globalCtx, &this->shieldQuad.base);
    Collider_ResetQuadAT(globalCtx, &this->shieldQuad.base);

    Fix_Cutscenes(globalCtx);
}

void draw(Vr_Overlord* this, GlobalContext* globalCtx) {
    MtxF workingMatrix;
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    Vec3f position = player->actor.world.pos;
    Vec3f lposition = position;
    Vec3f rposition = position;
    float height = 50.0f;
    if (globalCtx->linkAgeOnLoad) {
        height = 75.0f;
    }

    lposition.x += this->leftHand.matrix.mf[0][3] * height;
    lposition.y += this->leftHand.matrix.mf[1][3] * height;
    lposition.z -= this->leftHand.matrix.mf[2][3] * height;
    rposition.x += this->rightHand.matrix.mf[0][3] * height;
    rposition.y += this->rightHand.matrix.mf[1][3] * height;
    rposition.z -= this->rightHand.matrix.mf[2][3] * height;

    // left hand (sword hitquad)
    workingMatrix = gMtxFClear;
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_NEW);
    Matrix_Get(&workingMatrix);
    UnityMatrix_To_Matrix(&this->leftHand.matrix, &workingMatrix);
    workingMatrix.mf[3][0] = lposition.x;
    workingMatrix.mf[3][1] = lposition.y;
    workingMatrix.mf[3][2] = lposition.z;
    Matrix_Put(&workingMatrix);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);

    Vec3f newTip[3];
    float length = sSwordLengths[this->leftHand.actionParam - PLAYER_AP_FISHING_POLE] * 0.01;
    for (int i = 0; i < 3; i++) {
        newTip[i].x = lposition.x + (this->leftHand.matrix.mf[1][0] * length);
        newTip[i].y = lposition.y + (this->leftHand.matrix.mf[1][1] * length);
        newTip[i].z = lposition.z + (this->leftHand.matrix.mf[1][2] * length);

        this->swordInfo[i].base = lposition;
        this->swordInfo[i].tip = newTip[i];
        this->swordInfo[i].active = 1;
    }

    Sword_Update(this, globalCtx, newTip);

    // left hand (sword)
    workingMatrix = gMtxFClear;
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_NEW);
    Matrix_Get(&workingMatrix);
    UnityMatrix_To_Matrix(&this->leftHand.matrix, &workingMatrix);
    workingMatrix.mf[3][0] = lposition.x;
    workingMatrix.mf[3][1] = lposition.y;
    workingMatrix.mf[3][2] = lposition.z;
    Matrix_Put(&workingMatrix);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
    Matrix_RotateRPY((int16_t)(180.0f * RAD2S), 0, 0, MTXMODE_APPLY);
    Gfx_DrawDListOpa(globalCtx, 0x06013F38);

    // right hand (shield hitquad)
    workingMatrix = gMtxFClear;
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_NEW);
    Matrix_Get(&workingMatrix);
    UnityMatrix_To_Matrix(&this->rightHand.matrix, &workingMatrix);
    workingMatrix.mf[3][0] = rposition.x;
    workingMatrix.mf[3][1] = rposition.y;
    workingMatrix.mf[3][2] = rposition.z;
    Matrix_Put(&workingMatrix);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
    Shield_Update(this, globalCtx, &this->shieldQuad, D_80126154);

    // right hand (shield)
    workingMatrix = gMtxFClear;
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_NEW);
    Matrix_Get(&workingMatrix);
    UnityMatrix_To_Matrix(&this->rightHand.matrix, &workingMatrix);
    workingMatrix.mf[3][0] = rposition.x;
    workingMatrix.mf[3][1] = rposition.y;
    workingMatrix.mf[3][2] = rposition.z;
    Matrix_Put(&workingMatrix);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
    Matrix_RotateRPY((int16_t)(180.0f * RAD2S), (int16_t)(90.0f * RAD2S), 0, MTXMODE_APPLY);
    Gfx_DrawDListOpa(globalCtx, 0x06014440);

    Fix_Cutscenes(globalCtx);
}
