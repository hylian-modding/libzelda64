#ifndef FOOTIK_H
#define FOOTIK_H

#include "../puppet.h"
#include <libzelda64.h>
#include <PR/gu.h>

Vec3f D_8012602C = { 0.0f, 0.0f, 0.0f };
Vec3f D_80126038[] = {
    { 1304.0f, 0.0f, 0.0f },
    { 695.0f, 0.0f, 0.0f },
};
float D_80126050[] = { 1265.0f, 826.0f };
float D_80126058[] = { 170.0415955f, 48.30249786f };
float D_80126060[] = { 10.019104f, -19.92510223f };
float D_80126068[] = { 5.0f, 3.0f };
Vec3f D_80126070 = { 0.0f, -300.0f, 0.0f };

void FootIK(GlobalContext* globalCtx, En_Puppet* this, SkelAnime* skelAnime, Vec3f* pos, Vec3s* rot, int32_t thighLimbIndex,
            int32_t shinLimbIndex, int32_t footLimbIndex) {
    Vec3f spA4;
    Vec3f sp98;
    Vec3f footprintPos;
    struct CollisionPoly* sp88;
    int32_t sp84;
    float sp80;
    float sp7C;
    float sp78;
    float sp74;
    float sp70;
    float sp6C;
    float sp68;
    float sp64;
    float sp60;
    float sp5C;
    float sp58;
    float sp54;
    float sp50;
    int16_t temp1;
    int16_t temp2;
    int32_t temp3;

    if (1) {
        int32_t pad;

        sp7C = D_80126058[this->puppet.age];
        sp78 = D_80126060[this->puppet.age];
        sp74 = D_80126068[this->puppet.age]; /* - this->unk_6C4 something to do with boots */

        Matrix_Push();
        Matrix_JointPosition(pos, rot);
        Matrix_MultVec3f(&D_8012602C, &spA4);
        Matrix_JointPosition(&D_80126038[this->puppet.age], &skelAnime->jointTable[shinLimbIndex]);
        Matrix_Translate(D_80126050[this->puppet.age], 0.0f, 0.0f, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_8012602C, &sp98);
        Matrix_MultVec3f(&D_80126070, &footprintPos);
        Matrix_Pop();

        footprintPos.y += 15.0f;

        sp80 = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &sp88, &sp84, &this->actor, &footprintPos) + sp74;

        if (sp98.y < sp80) {
            sp70 = sp98.x - spA4.x;
            sp6C = sp98.y - spA4.y;
            sp68 = sp98.z - spA4.z;

            sp64 = sqrtf(SQ(sp70) + SQ(sp6C) + SQ(sp68));
            sp60 = (SQ(sp64) + sp78) / (2.0f * sp64);

            sp58 = sp7C - SQ(sp60);
            sp58 = (sp7C < SQ(sp60)) ? 0.0f : sqrtf(sp58);

            sp54 = Math_FAtan2F(sp58, sp60);

            sp6C = sp80 - spA4.y;

            sp64 = sqrtf(SQ(sp70) + SQ(sp6C) + SQ(sp68));
            sp60 = (SQ(sp64) + sp78) / (2.0f * sp64);
            sp5C = sp64 - sp60;

            sp58 = sp7C - SQ(sp60);
            sp58 = (sp7C < SQ(sp60)) ? 0.0f : sqrtf(sp58);

            sp50 = Math_FAtan2F(sp58, sp60);

            temp1 = (M_PI - (Math_FAtan2F(sp5C, sp58) + ((M_PI / 2) - sp50))) * 10430.378f;
            temp1 = temp1 - skelAnime->jointTable[shinLimbIndex].z;

            if ((int16_t)(ABS(skelAnime->jointTable[shinLimbIndex].x) + ABS(skelAnime->jointTable[shinLimbIndex].y)) < 0) {
                temp1 += 0x8000;
            }

            temp2 = (sp50 - sp54) * 10430.378f;
            rot->z -= temp2;

            skelAnime->jointTable[thighLimbIndex].z = skelAnime->jointTable[thighLimbIndex].z - temp2;
            skelAnime->jointTable[shinLimbIndex].z = skelAnime->jointTable[shinLimbIndex].z + temp1;
            skelAnime->jointTable[footLimbIndex].z = skelAnime->jointTable[footLimbIndex].z + temp2 - temp1;
        }
    }
}

/*
Link's func:

f32 D_80126050[] = { 1265.0f, 826.0f };
f32 D_80126058[] = { 170.0415955f, 48.30249786f };
f32 D_80126060[] = { 10.019104f, -19.92510223f };
f32 D_80126068[] = { 5.0f, 3.0f };

Vec3f D_80126070 = { 0.0f, -300.0f, 0.0f };

void func_8008F87C(GlobalContext* globalCtx, Player* this, SkelAnime* skelAnime, Vec3f* pos, Vec3s* rot,
                   s32 thighLimbIndex, s32 shinLimbIndex, s32 footLimbIndex) {
    Vec3f spA4;
    Vec3f sp98;
    Vec3f footprintPos;
    CollisionPoly* sp88;
    UNK_TYPE sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s16 temp1;
    s16 temp2;
    s32 temp3;

    if ((this->actor.scale.y >= 0.0f) && !(this->stateFlags1 & 0x80) &&
        (Player_ActionToMagicSpell(this, this->itemActionParam) < 0)) {
        s32 pad;

        sp7C = D_80126058[(void)0, gSaveContext.linkAge];
        sp78 = D_80126060[(void)0, gSaveContext.linkAge];
        sp74 = D_80126068[(void)0, gSaveContext.linkAge] - this->unk_6C4;

        Matrix_Push();
        Matrix_JointPosition(pos, rot);
        Matrix_MultVec3f(&D_8012602C, &spA4);
        Matrix_JointPosition(&D_80126038[(void)0, gSaveContext.linkAge], &skelAnime->jointTable[shinLimbIndex]);
        Matrix_Translate(D_80126050[(void)0, gSaveContext.linkAge], 0.0f, 0.0f, MTXMODE_APPLY);
        Matrix_MultVec3f(&D_8012602C, &sp98);
        Matrix_MultVec3f(&D_80126070, &footprintPos);
        Matrix_Pop();

        footprintPos.y += 15.0f;

        sp80 = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &sp88, &sp84, &this->actor, &footprintPos) + sp74;

        if (sp98.y < sp80) {
            sp70 = sp98.x - spA4.x;
            sp6C = sp98.y - spA4.y;
            sp68 = sp98.z - spA4.z;

            sp64 = sqrtf(SQ(sp70) + SQ(sp6C) + SQ(sp68));
            sp60 = (SQ(sp64) + sp78) / (2.0f * sp64);

            sp58 = sp7C - SQ(sp60);
            sp58 = (sp7C < SQ(sp60)) ? 0.0f : sqrtf(sp58);

            sp54 = Math_FAtan2F(sp58, sp60);

            sp6C = sp80 - spA4.y;

            sp64 = sqrtf(SQ(sp70) + SQ(sp6C) + SQ(sp68));
            sp60 = (SQ(sp64) + sp78) / (2.0f * sp64);
            sp5C = sp64 - sp60;

            sp58 = sp7C - SQ(sp60);
            sp58 = (sp7C < SQ(sp60)) ? 0.0f : sqrtf(sp58);

            sp50 = Math_FAtan2F(sp58, sp60);

            temp1 = (M_PI - (Math_FAtan2F(sp5C, sp58) + ((M_PI / 2) - sp50))) * 10430.378f;
            temp1 = temp1 - skelAnime->jointTable[shinLimbIndex].z;

            if ((s16)(ABS(skelAnime->jointTable[shinLimbIndex].x) + ABS(skelAnime->jointTable[shinLimbIndex].y)) < 0) {
                temp1 += 0x8000;
            }

            temp2 = (sp50 - sp54) * 10430.378f;
            rot->z -= temp2;

            skelAnime->jointTable[thighLimbIndex].z = skelAnime->jointTable[thighLimbIndex].z - temp2;
            skelAnime->jointTable[shinLimbIndex].z = skelAnime->jointTable[shinLimbIndex].z + temp1;
            skelAnime->jointTable[footLimbIndex].z = skelAnime->jointTable[footLimbIndex].z + temp2 - temp1;

            temp3 = func_80041D4C(&globalCtx->colCtx, sp88, sp84);

            if ((temp3 >= 2) && (temp3 < 4) && !SurfaceType_IsWallDamage(&globalCtx->colCtx, sp88, sp84)) {
                footprintPos.y = sp80;
                EffectSsGFire_Spawn(globalCtx, &footprintPos);
            }
        }
    }
}
*/

#endif

