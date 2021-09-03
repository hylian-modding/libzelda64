#include "Puppet.h"
#include "DefaultCollider.h"
#include "SkelAnimeCustom.h"
#include "LUTOffsets.h"
#include "TPose.h"
#include "LimbDraw.h"
#include "Macros.h"
#include <ultra64.h>
#include <PR/gbi.h>

#ifdef GAME_OOT
// Misc data for adult and child link
static const Vec3f sFootOffsets[] = {
    { 200.0f, 300.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f }
};

static const float sShadowScales[] = {
    90.0f,
    60.0f
};

static const int16_t sColliderRadius[] = {
    12,
    10
};

static const int16_t sColliderHeight[] = {
    60,
    44
};

#elif defined GAME_MM
// Misc data for feirce deity, goron, zora, deku, and link
static const Vec3f sFootOffsets[] = {
    { 200.0f, 300.0f, 0.0f },
    { 200.0f, 300.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f }
};

static const float sShadowScales[] = {
    90.0f,
    80.0f,
    70.0f,
    40.0f,
    60.0f
};

static const int16_t sColliderRadius[] = {
    15,
    14,
    12,
    10,
    12
};

static const int16_t sColliderHeight[] = {
    110,
    60,
    60,
    30,
    44
};
#endif

void Puppet_Ctor(Puppet* thisx, GlobalContext* globalCtx) {
#ifdef _MLDEBUG
    thisx->__debugFlg |= DEBUGFLG_CTOR;
#endif

#ifdef GAME_OOT
    thisx->syncInfo.ageOrForm.age = thisx->actor.params;
#elif defined GAME_MM
    thisx->syncInfo.ageOrForm.form = (uint8_t) thisx->actor.params;
#endif
    thisx->actor.room = 0xFF;
    thisx->actor.shape.rot.x = 0;
    thisx->actor.shape.rot.y = 0;
    thisx->actor.shape.rot.z = 0;

    thisx->basePointer = *((uint32_t*)(&thisx->actor.home.rot));

    SkelAnimeCustom_InitLink(globalCtx, &thisx->skelAnime,
        (FlexSkeletonHeader*)(thisx->basePointer + SKEL_SECTION), // This custom function assumes this is not segmented!
        NULL, 9, thisx->jointTable, thisx->morphTable, PLAYER_LIMB_MAX);

#ifdef GAME_OOT
    ActorShape_Init(&thisx->actor.shape, 0.0f, ActorShadow_DrawFeet, sShadowScales[thisx->syncInfo.ageOrForm.age]);
    thisx->collider.dim.radius = sColliderRadius[thisx->syncInfo.ageOrForm.age];
#elif defined GAME_MM
    ActorShape_Init(&thisx->actor.shape, 0.0f, ActorShadow_DrawFeet, sShadowScales[thisx->syncInfo.ageOrForm.form]);
    thisx->collider.dim.radius = sColliderRadius[thisx->syncInfo.ageOrForm.form];
#endif

    Collider_InitCylinder(globalCtx, &thisx->collider);
    Collider_SetCylinder(globalCtx, &thisx->collider, thisx, &gDefaultCollider);

    Actor_SetScale((Actor*)thisx, 0.01f);

    thisx->actor.flags |= 0x0E000075; // @Help: What is this for, and why isn't it in the init vars?

    memcpy(&thisx->animeTable, &gTPose_Anim, gTPose_Anim_Size);

#ifdef _MLDEBUG
    thisx->__debug = 0xDEADBEEF;
    thisx->__debugFlg &= ~DEBUGFLG_CTOR;
#endif
}

void Puppet_Dtor(Puppet* thisx, GlobalContext* globalCtx) {
#ifdef _MLDEBUG
    thisx->__debugFlg |= DEBUGFLG_DTOR;
#endif

    if (thisx->actor.child) {
        thisx->actor.child->parent = 0;
        Actor_Kill(thisx->actor.child);
        thisx->actor.child = 0;
    }

#ifdef _MLDEBUG
    thisx->__debugFlg &= ~DEBUGFLG_DTOR;
#endif
}

void Puppet_Step(Puppet* thisx, GlobalContext* globalCtx) {
#ifdef _MLDEBUG
    thisx->__debugFlg |= DEBUGFLG_STEP;
#endif

    Vec3f focusPos;
    Player* player = (Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head;

#ifdef GAME_OOT
        thisx->collider.dim.height = sColliderHeight[thisx->syncInfo.ageOrForm.age];
#elif defined GAME_MM
        thisx->collider.dim.height = sColliderHeight[thisx->syncInfo.ageOrForm.form];
#endif

    thisx->actor.shape.shadowAlpha = player->actor.shape.shadowAlpha;

    Collider_UpdateCylinder((Actor*)thisx, &thisx->collider);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &thisx->collider.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &thisx->collider.base);

    Actor_SetFocus((Actor*)thisx, (float)thisx->collider.dim.height);
    thisx->actor.focus.rot.x = thisx->actor.world.rot.x;
    thisx->actor.focus.rot.y = thisx->actor.world.rot.y;
    thisx->actor.focus.rot.z = thisx->actor.world.rot.z;

#ifdef _MLDEBUG
    thisx->__debugFlg &= ~DEBUGFLG_STEP;
#endif
}

void Puppet_Draw(Puppet* thisx, GlobalContext* globalCtx) {
#ifdef _MLDEBUG
    thisx->__debugFlg |= DEBUGFLG_DRAW;
#endif

#ifdef GAME_OOT
    RESET_ENV_TO_TUNIC();
#endif
    uint8_t rollState = 0;
    if (thisx->syncInfo.stateFlags[2] == 0x00001000){
        DrawDlistOpa(obtainAlias(DL_CURLED));
        rollState += 1;
    }
    if (thisx->syncInfo.stateFlags[2] == 0x00081000){
        DrawDlistOpa(obtainAlias(DL_CURLED));
        DrawDlistOpa(obtainAlias(DL_SPIKES));
        rollState += 2;
    }
    if (!rollState){
        SkelAnime_DrawFlexOpa(globalCtx, thisx->skelAnime.skeleton, thisx->jointTable,
        thisx->skelAnime.dListCount, LimbDrawOpa_Override, LimbDrawOpa_Post, thisx);
    }

#ifdef _MLDEBUG
    thisx->__debugFlg &= ~DEBUGFLG_DRAW;
#endif
}

ActorInit initVars = {
    .id = 5,
    .category = ACTORLIST_CATEGORY_NPC,
    .flags = 0x00002431,
    .objectId = 1,
    .instanceSize = sizeof(Puppet),
    .init = Puppet_Ctor,
    .destroy = Puppet_Dtor,
    .update = Puppet_Step,
    .draw = Puppet_Draw
};

