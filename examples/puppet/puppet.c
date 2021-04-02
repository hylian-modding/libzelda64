#include "puppet.h"
#include "deps/equip.h"
#include "deps/happy_mask.h"
#include <libzelda64/lib/GraphicsContext.h>

const Vec3f footOffsets[] = {
    { 200.0f, 300.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f }
};

const float shadowScales[] = { 90.0f, 60.0f };
const float ageProperties_00[] = { 56.0f, 40.0f };
const float ageProperties_38[] = {70.0f, 45.29412079f };

const Color_RGBA8_u32 white = {.rgba = 0xFFFFFFFF};

const uint8_t copyFlags[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

static void SkelAnime_InitLink_Custom(
    struct GlobalContext* globalCtx
    , struct SkelAnime* skelAnime
    , struct FlexSkeletonHeader* skeletonHeaderSeg
    , struct LinkAnimationHeader* animation
    , int32_t flags
    , struct Vec3s* jointTable
    , struct Vec3s* morphTable
    , int32_t limbBufCount
)
{
    struct FlexSkeletonHeader* skeletonHeader = skeletonHeaderSeg;
    int32_t headerJointCount = skeletonHeader->sh.limbCount;
    int32_t limbCount;

    skelAnime->initFlags = flags;
    limbCount = (flags & 2) ? headerJointCount : 1;

    if (flags & 1) {
        limbCount += headerJointCount;
    }
    if (flags & 4) {
        limbCount += headerJointCount;
    }

    skelAnime->limbCount = limbCount;
    skelAnime->dListCount = skeletonHeader->dListCount;

    skelAnime->skeleton = skeletonHeader->sh.segment;

    skelAnime->jointTable = (Vec3s*)ALIGN16((uint32_t)jointTable);
    skelAnime->morphTable = (Vec3s*)ALIGN16((uint32_t)morphTable);

    if (animation != NULL) LinkAnimation_Change(globalCtx, skelAnime, animation, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP, 0.0f);
}

// TODO: Move to a more appropriate header or file.
static void* memcpy(void* dest, const void* src, uint32_t len) {
    char* d = dest;
    const char* s = src;
    while (len--) {
        *d++ = *s++;
    }
    return dest;
}

static int32_t AnimateCallback(
    struct GlobalContext* globalCtx
    , int32_t limbIndex
    , struct Gfx** dList
    , struct Vec3f* pos
    , Vec3s* rot
    , entity_t* this
)
{
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;
    TwoHeadGfxArena* polyXlu = &globalCtx->game.gfxCtx->polyXlu;

    memcpy(&this->skelAnime0.jointTable, &this->puppet.anim, 0x86);

    if (limbIndex == 1)
    {
        pos->y *= this->puppet.age == 0 ? 1 : 0.66f;
    }

    //Actor_SetFeetPos(&this->actor, limbIndex, PLAYER_LIMB_FOOT_L, &footOffsets[this->puppet.age], PLAYER_LIMB_FOOT_L, &footOffsets[this->puppet.age]);

    uint32_t bootDList = 0;
    bool swordIsOut = false;
    switch (limbIndex) {
        case PLAYER_LIMB_NONE: {
        } break;
        case PLAYER_LIMB_ROOT: {
        } break;
        case PLAYER_LIMB_WAIST: {
        } break;
        case PLAYER_LIMB_LOWER: {
        } break;
        case PLAYER_LIMB_THIGH_R: {
        } break;
        case PLAYER_LIMB_SHIN_R: {
        } break;
        case PLAYER_LIMB_FOOT_R: {
            if (this->puppet.currentBoots > PLAYER_BOOTS_NORMAL) {
                bootDList = (this->puppet.currentBoots > 1) ? RESOLVE_PROXY(ADULT_LINK_LUT_DL_BOOT_RHOVER) : RESOLVE_PROXY(ADULT_LINK_LUT_DL_BOOT_RIRON);
                DrawDlistOpa(baseToPointer(this, bootDList));
            }
        } break;
        case PLAYER_LIMB_THIGH_L: {
        } break;
        case PLAYER_LIMB_SHIN_L: {
        } break;
        case PLAYER_LIMB_FOOT_L: {
            if (this->puppet.currentBoots > PLAYER_BOOTS_NORMAL) {
                bootDList = (this->puppet.currentBoots > 1) ? RESOLVE_PROXY(ADULT_LINK_LUT_DL_BOOT_LHOVER) : RESOLVE_PROXY(ADULT_LINK_LUT_DL_BOOT_LIRON);
                DrawDlistOpa(baseToPointer(this, bootDList));
            }
        } break;
        case PLAYER_LIMB_UPPER: {
            Matrix_RotateRPY((this->puppet).bodyAngle.x, (this->puppet).bodyAngle.y, (this->puppet).bodyAngle.z, 1);
        } break;
        case PLAYER_LIMB_HEAD: {
            if (this->puppet.age && this->puppet.currentMask) {
                Matrix_Push();
                {
                    Matrix_Translate(pos->x, pos->y, pos->z, 1);
                    Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

                    if (this->puppet.currentMask == MASK_INDEX_BUNNY_HOOD)
                        BunnyHood_Mtx_Setup(this, globalCtx);
                    
                    gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(mask_dlists[this->puppet.currentMask - 1])));
                }
                Matrix_Pop();
            }
        } break;
        case PLAYER_LIMB_HAT: {
        } break;
        case PLAYER_LIMB_COLLAR: {
        } break;
        case PLAYER_LIMB_SHOULDER_L: {
        } break;
        case PLAYER_LIMB_FOREARM_L: {
        } break;
        case PLAYER_LIMB_HAND_L: {
            if ((this->actor.speedXZ > 2.0f && !(this->puppet.state.Flags[0] & PLAYER_ACTION_ANCHOR_FIGHT)) || (ACTION_IS_WEAPON)) /* && Link->bVar1 == 0*/
            {
                *dList = baseToPointer(this, RESOLVE_PROXY(RESOLVE_LEFT_FIST(this->puppet.age)));
            }
            else
                *dList = baseToPointer(this, RESOLVE_PROXY(RESOLVE_LEFT_HAND(this->puppet.age)));
            Matrix_Push();
            {
                Matrix_Translate(pos->x, pos->y, pos->z, 1);
                Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

                if (ACTION_IS_SWORD)
                {
                    swordIsOut = true;
                    /*if (ACTION_IS_KOKIRI_SWORD)
                    {
                        DRAW_PROXY_OPA(DL_SWORD0_HILT); DRAW_PROXY_OPA(DL_SWORD0_BLADE);
                    }
                    else if (ACTION_IS_MASTER_SWORD)
                    {
                        DRAW_PROXY_OPA(DL_SWORD1_HILT); DRAW_PROXY_OPA(DL_SWORD1_BLADE);
                    }
                    else if (ACTION_IS_BIGGORON_SWORD)
                    {
                        DRAW_PROXY_OPA(DL_SWORD2_HILT); DRAW_PROXY_OPA(DL_SWORD2_BLADE);
                    }*/
                    gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(hilt_proxies[this->puppet.currentSword - 0x3B])));
                    gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(blade_proxies[this->puppet.currentSword - 0x3B])));
                }
                else if (ACTION_IS_DEKU_STICK) {
                    Matrix_Push();
                    {
                        Matrix_Translate(-428.26f, 267.20f, -33.82f, 1);
                        Matrix_RotateRPY(0x8000, 0, 0x4000, 1);
                        Matrix_Scale(1.0f, (this->puppet).deku_stick.length, 1.0f, 1);
                        DRAW_PROXY_OPA(DL_STICK);
                    }
                    Matrix_Pop();
                }
                else if (ACTION_IS_BOTTLE)
                {
                    *dList = baseToPointer(this, RESOLVE_PROXY(RESOLVE_BOTTLE_HAND(this->puppet.age)));
                    gDPSetEnvColor(polyOpa->p++, contents[BOTTLE_INDEX].r, contents[BOTTLE_INDEX].g, contents[BOTTLE_INDEX].b, 255);
                    DrawDlistOpa(baseToPointer(this, RESOLVE_PROXY(RESOLVE_BOTTLE(this->puppet.age))));
                    RESET_ENV_TO_TUNIC(polyOpa);
                }
                else if (ACTION_IS_MEGATON_HAMMER)
                {
                    DRAW_PROXY_OPA(DL_HAMMER);
                }
                // TODO:
                // Boomerang
                // Fishing Pole
            }
            Matrix_Pop();
        } break;
        case PLAYER_LIMB_SHOULDER_R: {
        } break;
        case PLAYER_LIMB_FOREARM_R: {
        } break;
        case PLAYER_LIMB_HAND_R: {
            if (this->actor.speedXZ > 2.0f && !(this->puppet.state.Flags[0] & PLAYER_ACTION_ANCHOR_FIGHT)) /* && Link->right_hand_item == 8*/
            {
                *dList = baseToPointer(this, RESOLVE_PROXY(RESOLVE_RIGHT_FIST(this->puppet.age)));
            }
            else
                *dList = baseToPointer(this, RESOLVE_PROXY(RESOLVE_RIGHT_HAND(this->puppet.age)));
            
            Matrix_Push();
            {
                Matrix_Translate(pos->x, pos->y, pos->z, 1);
                Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

                if (ACTION_IS_SHIELD)
                {
                    /*if (SHIELD_IS_DEKU)
                    {
                        DRAW_PROXY_OPA(DL_SHIELD0);
                    }
                    else if (SHIELD_IS_HYLIAN)
                    {
                        DRAW_PROXY_OPA(DL_SHIELD1);
                    }
                    else if (SHIELD_IS_MIRROR)
                    {
                        DRAW_PROXY_OPA(DL_SHIELD2);
                    }*/
                    gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(shield_proxies[this->puppet.currentShield - 1])));
                }
                // TODO:
                // Bow
                // Slingshot
                // Hookshot / Longshot
            }
            Matrix_Pop();
        } break;
        case PLAYER_LIMB_SHEATH: {
            if (this->puppet.currentSword)
            {
                Matrix_Push();
                {
                    Matrix_Translate(pos->x, pos->y, pos->z, 1);
                    Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
                    
                    *dList = baseToPointer(this, RESOLVE_PROXY(sheath_proxies[this->puppet.currentSword - 0x3B]));

                    if (!swordIsOut)
                    {
                        gSPMatrix(polyOpa->p++, MATRIX_MOVE_HILT_TO_SHEATH, G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
                        gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(hilt_proxies[this->puppet.currentSword - 0x3B])));
                        gSPPopMatrix(polyOpa->p++, 1);
                    }

                    if (!ACTION_IS_SHIELD)
                    {
                        gSPMatrix(polyOpa->p++, MATRIX_ROTATE_SHIELD_TO_BACK, G_MTX_LOAD | G_MTX_NOPUSH | G_MTX_MODELVIEW);
                        gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(shield_proxies[this->puppet.currentShield - 1])));
                        gSPPopMatrix(polyOpa->p++, 1);
                    }
                }
                Matrix_Pop();
            }
            //else
                //*dList = G_ENDDL
        } break;
        case PLAYER_LIMB_TORSO: {
        } break;
        case PLAYER_LIMB_MAX: {
        } break;
    }

    //#L10296 is hover boot special effects
    //#L10357 is damage color effect

    return 0;
}

static int32_t OtherCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, entity_t* this)
{
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;
    const uint32_t eyes[3] = { deref(baseToPointer(this, 0x580)) + 0, deref(baseToPointer(this, 0x580)) + 0x800, deref(baseToPointer(this, 0x580)) + 0x1000 };
    this->puppet.eyeTexture = eyes[Helper_EyeBlink(&this->puppet.eyeIndex)];
    gSPSegment(polyOpa->p++, 8, this->puppet.eyeTexture);
    gSPSegment(polyOpa->p++, 9, deref(baseToPointer(this, 0x584)));
    return 1;
}

static void init(entity_t* this, GlobalContext* globalCtx)
{
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    this->actor.room = 0xFF;
    this->puppet.age = this->actor.params;

    SkelAnime_InitLink_Custom(globalCtx, &this->skelAnime0.skelAnime,
        baseToPointerSkel(this, 0xC), /* TODO: current method will not work for mm */
        0,
        9, /* initflags */
        this->skelAnime0.jointTable, this->skelAnime0.morphTable, PLAYER_LIMB_MAX
    );

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFeet, shadowScales[this->puppet.age]);

    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.y = 0;
    this->actor.shape.rot.z = 0;

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, this, &colliderInit);

    this->collider.dim.radius = 12;

    if (AGE_IS_ADULT(this->puppet.age)) this->collider.dim.height = 60;
    else this->collider.dim.height = 44; 

    Actor_SetScale(this, 0.01f);

    this->puppet.colorBottle = white;
    this->puppet.colorGauntlet = white;

    this->actor.flags |= 0x0E000075;

    memcpy(&this->puppet.anim, __tpose_anim, __tpose_anim_size);

    MLDEBUG_END(this, 0xDEADBEEF);
}

static void destroy(entity_t* this, GlobalContext* globalCtx)
{
    if (this->actor.child) {
        this->actor.child->parent = 0;
        Actor_Kill(this->actor.child);
        this->actor.child = 0;
    }
}

static void update(entity_t* this, GlobalContext* globalCtx)
{

    Vec3f focusPos;
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

    this->actor.shape.shadowAlpha = player->actor.shape.shadowAlpha;

    Collider_UpdateCylinder(this, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);

    focusPos = this->actor.world.pos;

    if (AGE_IS_ADULT(this->puppet.age)) focusPos.y += 68.0f; // camera uses these offsets, who knows if they work here
    else focusPos.y += 44.0f;

    this->actor.focus.pos = focusPos;
    this->actor.focus.rot = this->actor.world.rot;
}

static void draw(entity_t* this, GlobalContext* globalCtx)
{
    gDPSetEnvColor(globalCtx->game.gfxCtx->polyOpa.p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);

    // Teardrop / feet shadow drawn by callback from ActorShape_Init, feetpos is set in AnimateCallback
    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime0.skelAnime.skeleton, this->skelAnime0.skelAnime.jointTable, this->skelAnime0.skelAnime.dListCount, &AnimateCallback, &OtherCallback, this);

    if (this->puppet.soundId)
    {
        Audio_PlaySoundAtPosition(globalCtx, &this->actor.world.pos, 25, this->puppet.soundId);
        this->puppet.soundId = 0;
    }
}

