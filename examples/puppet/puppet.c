#include "puppet.h"
#include "deps/footik.h"

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
    int32_t limbNumber = limbIndex; /*- 1; // OG puppet did this, but I think it's because our old enum began at ROOT instead of NONE */

    Actor_SetFeetPos(&this->actor, limbIndex, PLAYER_LIMB_FOOT_L, &footOffsets[this->puppet.age], PLAYER_LIMB_FOOT_L, &footOffsets[this->puppet.age]);

    // TODO:
    switch (limbNumber) {
        case PLAYER_LIMB_NONE: {
        } break;
        case PLAYER_LIMB_ROOT: {
        } break;
        case PLAYER_LIMB_WAIST: {
        } break;
        case PLAYER_LIMB_LOWER: {
        } break;
        case PLAYER_LIMB_THIGH_R: {
            FootIK(globalCtx, this, &this->skelAnime0.skelAnime, pos, rot, PLAYER_LIMB_THIGH_R, PLAYER_LIMB_SHIN_R, PLAYER_LIMB_FOOT_R);
        } break;
        case PLAYER_LIMB_SHIN_R: {
        } break;
        case PLAYER_LIMB_FOOT_R: {
            uint32_t bootDList = 0;
            if (this->puppet.boots > PLAYER_BOOTS_NORMAL) {
                bootDList = (this->puppet.boots > 1) ? ADULT_LINK_LUT_DL_BOOT_RIRON : ADULT_LINK_LUT_DL_BOOT_RHOVER;
                DrawDlistOpa(baseToPointer(this, bootDList));
            }
        } break;
        case PLAYER_LIMB_THIGH_L: {
            FootIK(globalCtx, this, &this->skelAnime0.skelAnime, pos, rot, PLAYER_LIMB_THIGH_L, PLAYER_LIMB_SHIN_L, PLAYER_LIMB_FOOT_L);
        } break;
        case PLAYER_LIMB_SHIN_L: {
        } break;
        case PLAYER_LIMB_FOOT_L: {
            uint32_t bootDList = 0;
            if (this->puppet.boots > PLAYER_BOOTS_NORMAL) {
                bootDList = (this->puppet.boots > 1) ? ADULT_LINK_LUT_DL_BOOT_LIRON : ADULT_LINK_LUT_DL_BOOT_LHOVER;
                DrawDlistOpa(baseToPointer(this, bootDList));
            }
        } break;
        case PLAYER_LIMB_UPPER: {
        } break;
        case PLAYER_LIMB_HEAD: {
            if (!AGE_IS_ADULT(this->puppet.age)) {
                switch (this->puppet.mask)
                {
                    case OOT_MASK_KEATON:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_KEATON));
                        break;
                    case OOT_MASK_SKULL:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_SKULL));
                        break;
                    case OOT_MASK_SPOOKY:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_SPOOKY));
                        break;
                    case OOT_MASK_BUNNY_HOOD:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_BUNNY));
                        break;
                    case OOT_MASK_GORON:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_GORON));
                        break;
                    case OOT_MASK_ZORA:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_ZORA));
                        break;
                    case OOT_MASK_GERUDO:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_GERUDO));
                        break;
                    case OOT_MASK_TRUTH:
                        DrawDlistOpa(baseToPointer(this, CHILD_LINK_LUT_DL_MASK_TRUTH));
                        break;
                }
            }
        } break;
        case PLAYER_LIMB_HAT: {
        } break;
        case PLAYER_LIMB_COLLAR: {
        } break;
        case PLAYER_LIMB_SHOULDER_L: {
        } break;
        case PLAYER_LIMB_FOREARM_L: {
            if (this->puppet.strength)
            {
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorGauntlet.r, this->puppet.colorGauntlet.g, this->puppet.colorGauntlet.b, this->puppet.colorGauntlet.a);
                DrawDlistOpa(baseToPointer(this, baseToPointer(this, AGE_IS_ADULT(this->puppet.age) ? ADULT_LINK_LUT_DL_UPGRADE_LFOREARM : CHILD_LINK_LUT_DL_GORON_BRACELET)));
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);
            }
        } break;
        case PLAYER_LIMB_HAND_L: {
            if (this->puppet.lhandDlist)
            {
                Matrix_Push();
                {
                    Matrix_Translate(pos->x, pos->y, pos->z, 1);
                    Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
                    *dList = baseToPointer(this, (this->puppet.lhandDlist & 0x0000FFFF));
                }
                Matrix_Pop();
            }
        } break;
        case PLAYER_LIMB_SHOULDER_R: {
        } break;
        case PLAYER_LIMB_FOREARM_R: {
            if (this->puppet.strength)
            {
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorGauntlet.r, this->puppet.colorGauntlet.g, this->puppet.colorGauntlet.b, this->puppet.colorGauntlet.a);
                DrawDlistOpa(baseToPointer(this, ADULT_LINK_LUT_DL_UPGRADE_RFOREARM));
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);
            }
        } break;
        case PLAYER_LIMB_HAND_R: {
            if (this->puppet.rhandDlist)
            {
                Matrix_Push();
                {
                    Matrix_Translate(pos->x, pos->y, pos->z, 1);
                    Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
                    *dList = baseToPointer(this, (this->puppet.rhandDlist & 0x0000FFFF));
                }
                Matrix_Pop();
            }
        } break;
        case PLAYER_LIMB_SHEATH: {
            if (this->puppet.backDlist)
                *dList = baseToPointer(this, (this->puppet.backDlist & 0x0000FFFF));
        } break;
        case PLAYER_LIMB_TORSO: {
        } break;
        case PLAYER_LIMB_MAX: {
        } break;
    }

    return 0;
}

static int32_t OtherCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, entity_t* this)
{
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;
    gSPSegment(polyOpa->p++, 8, this->puppet.eyeTexture);
    gSPSegment(polyOpa->p++, 9, baseToPointer(this, 0x00004000));
    return 1;
}


static void init(entity_t* this, GlobalContext* globalCtx)
{
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    this->actor.room = 0xFF;
    this->puppet.age = (uint32_t) this->actor.params;
    this->puppet.DEBUG_OUT = this->puppet.age;
    this->skelAnime0.syncAnimation = player->skelAnime.animation;

    this->skelAnime0.syncFrame = 0;
    this->skelAnime0.syncSpeed = player->skelAnime.playSpeed;
    this->skelAnime0.latencyFrames = 0;

    this->skelAnime1.syncFrame = 0;
    this->skelAnime1.syncSpeed = player->skelAnime2.playSpeed;
    this->skelAnime1.latencyFrames = 0;

    SkelAnime_InitLink_Custom(globalCtx, &this->skelAnime0.skelAnime,
        baseToPointerSkel(this, 0x500C), /* TODO: current method will not work for mm */
        player->skelAnime.animation,
        9, /* initflags */
        this->skelAnime0.jointTable, this->skelAnime0.morphTable, PLAYER_LIMB_MAX
    );

/*     SkelAnime_InitLink(globalCtx, &this->skelAnime1.skelAnime,
        baseToPointerSkel(this, 0x500C),
        player->skelAnime2.animation,
        9,
        this->skelAnime1.jointTable, this->skelAnime1.morphTable, PLAYER_LIMB_MAX
    ); */

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFeet, shadowScales[this->puppet.age]);

    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.y = 0;
    this->actor.shape.rot.z = 0;

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, this, &colliderInit);

    //TODO: set damage table here (though we might want to do the damage checks ourself for higher accuracy)

    this->collider.dim.radius = 12;

    if (AGE_IS_ADULT(this->puppet.age)) this->collider.dim.height = 60;
    else this->collider.dim.height = 44; 

    Actor_SetScale(this, 0.01f);

    this->puppet.colorBottle = white;
    this->puppet.colorGauntlet = white;

    this->actor.flags |= 0x0E000075;

    //this->puppet.backDlist = 0x06005268;
    //this->puppet.lhandDlist = 0x060052B8;
    //this->puppet.mask = 1;

    void* animdata = (void*) 0x80600000;
    memcpy(&this->skelAnime0.jointTable, animdata, 0x86);

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

static void SkelAnimeSyncPair_Update(GlobalContext* globalCtx, SkelAnimeSyncPair* this)
{
    if (this->skelAnime.curFrame < this->syncFrame) this->skelAnime.curFrame = this->syncFrame;

    LinkAnimation_Update(globalCtx, &this->skelAnime);
    this->skelAnime.mode = this->syncMode; // We use ANIMMODE_LOOP_INTERP first to prevent random folding

     // Change animation if remote player's animation changed
    if (this->skelAnime.animation != this->syncAnimation && this->syncAnimation != 0) {
        // FIXME: Playas animations will not have the same animation pointer, we must find a way to safely sync these!
        // We could probably make a table that gives each custom animation a unique id, and use the index of the uuid for the index of the pointer
        // for example, let's say we have the uuid table [0xDEADBEEF, 0xABABBEEF, 0xBEEFDEAD, 0xBABADEAD]
        // to get the animation with the uuid BEEFDEAD, we would additionally have the table of pointers to the animations
        // so in this case, BEEFDEAD is the third uuid, at index 2
        // so we would do syncAnimation = animations[index]
        // this way we can have animation and playas stuff on the heap, and still write the correct pointer in the puppet
        // so we would instead sync the uuid, and have the puppet perform the scan to get the correct pointer
        // this would also be a good excuse to implement a system which does not allocate copies of existing data
        LinkAnimation_Change(globalCtx, &this->skelAnime, this->syncAnimation, this->syncSpeed, this->syncFrame, Animation_GetLength(this->syncAnimation), ANIMMODE_LOOP_INTERP, this->latencyFrames);
    } 
}

static void update(entity_t* this, GlobalContext* globalCtx)
{

    Vec3f focusPos;
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

    const uint32_t eyes[3] = { baseToPointer(this, 0), baseToPointer(this, 0x800), baseToPointer(this, 0x1000) };
    Helper_EyeBlink(&this->puppet.eyeIndex);
    this->puppet.eyeTexture = eyes[this->puppet.eyeIndex];

    this->actor.shape.shadowAlpha = player->actor.shape.shadowAlpha;

    Collider_UpdateCylinder(this, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);

    Actor_UpdateBgCheckInfo(globalCtx, this, 26.0f, ageProperties_38[this->puppet.age], ageProperties_00[this->puppet.age], 5);

    SkelAnimeSyncPair_Update(globalCtx, &this->skelAnime0);
    //SkelAnimeSyncPair_Update(globalCtx, &this->skelAnime1);

     if (this->puppet.syncUnk_830 != 0.0f) {
        if (this->puppet.syncLinearVelocity != 0.0f) {
            AnimationContext_SetCopyFalse(globalCtx, this->skelAnime0.skelAnime.limbCount, this->skelAnime1.jointTable, this->skelAnime0.jointTable, copyFlags);
        }

        Math_StepToF(&this->puppet.syncUnk_830, 0.0f, 0.25f);
        AnimationContext_SetInterp(globalCtx, this->skelAnime0.skelAnime.limbCount, this->skelAnime0.jointTable, this->skelAnime1.jointTable, 1.0f - this->puppet.syncUnk_830);
    }
    else if (this->puppet.syncLinearVelocity != 0.0f) {
        AnimationContext_SetCopyTrue(globalCtx, this->skelAnime0.skelAnime.limbCount, this->skelAnime0.jointTable, this->skelAnime1.jointTable, copyFlags);
    }
    else {
        AnimationContext_SetCopyAll(globalCtx, this->skelAnime0.skelAnime.limbCount, this->skelAnime0.jointTable, this->skelAnime1.jointTable);
    }

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

