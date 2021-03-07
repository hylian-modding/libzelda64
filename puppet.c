#include "puppet.h"
#include "footik.h"

void* memcpy(void* dest, const void* src, uint32_t len) {
    char* d = dest;
    const char* s = src;
    while (len--) {
        *d++ = *s++;
    }
    return dest;
}


int32_t IsZobjLoaded(GlobalContext* globalCtx, int32_t id) {
    int32_t index = Object_GetIndex(&globalCtx->objectCtx, id);
    if (index < 0) return 0;
    else return 1;
}

uint32_t AnimateCallback_HandsAndBack(entity_t* this, struct GlobalContext* globalCtx, int32_t limb) {
    uint32_t dlist = 0;

    if (AGE_IS_ADULT(this->puppet.age)) {
        // Set the defaults.
        if (limb == PLAYER_LIMB_R_HAND) {
            dlist = baseToPointer(this, ADULT_LINK_LUT_DL_RHAND);
        }
        else if (limb == PLAYER_LIMB_L_HAND) {
           dlist = baseToPointer(this, ADULT_LINK_LUT_DL_LHAND);
        }
        else if (limb == PLAYER_LIMB_SHEATH) {
            dlist = baseToPointer(this, ADULT_LINK_LUT_DL_SWORD_SHEATH);
        }

        if (this->puppet.action > 0) {
            if (this->puppet.shield_on_back) {
                if (limb == PLAYER_LIMB_SHEATH) {
                    if (this->puppet.shield == PLAYER_SHIELD_NONE) {
                        Matrix_Scale(0, 0, 0, 1);
                    }
                    else if (this->puppet.shield == PLAYER_SHIELD_DEKU) {
                        // TODO Deal with this shit somehow.
                        Matrix_Scale(0, 0, 0, 1);
                    }
                    else if (this->puppet.shield == PLAYER_SHIELD_HYLIAN) {
                        if (isSwordOut(this->puppet.action)) {
                            dlist = baseToPointer(this, ADULT_LINK_LUT_DL_SHEATH0_HYLIAN);
                        }
                        else {
                            dlist = baseToPointer(this, ADULT_LINK_LUT_DL_SWORD_SHIELD_HYLIAN);
                        }
                    }
                    else if (this->puppet.shield == PLAYER_SHIELD_MIRROR) {
                        if (isSwordOut(this->puppet.action)) {
                            dlist = baseToPointer(this, ADULT_LINK_LUT_DL_SHEATH0_MIRROR);
                        }
                        else {
                            dlist = baseToPointer(this, ADULT_LINK_LUT_DL_SWORD_SHIELD_MIRROR);
                        }
                    }
                }
            }
            else if (limb == PLAYER_LIMB_R_HAND) {
                if (isSwordOut(this->puppet.action)) {
                    switch (this->puppet.shield) {
                    case PLAYER_SHIELD_NONE:
                        Matrix_Scale(0, 0, 0, 1);
                        break;
                    case PLAYER_SHIELD_DEKU:
                        // deal with this shit later.
                        Matrix_Scale(0, 0, 0, 1);
                        break;
                    case PLAYER_SHIELD_HYLIAN:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_SHIELD_HYLIAN));
                        break;
                    case PLAYER_SHIELD_MIRROR:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_SHIELD_MIRROR));
                        break;
                    }
                }
                else {
                    if (valueInRange(this->puppet.action, PLAYER_AP_BOW, PLAYER_AP_BOW_0E)) {
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_BOW));
                    }
                    else if (this->puppet.action == PLAYER_AP_OCARINA_FAIRY) {
                        Matrix_Scale(0, 0, 0, 1);
                    }
                    else if (this->puppet.action == PLAYER_AP_OCARINA_TIME) {
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_OCARINA_TIME));
                    }
                    else if (this->puppet.action == valueInRange(this->puppet.action, PLAYER_AP_HOOKSHOT, PLAYER_AP_LONGSHOT)) {
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_HOOKSHOT));
                    }
                }
            }
            else if (limb == PLAYER_LIMB_L_HAND) {

            }
        }
    }
    else {
        if (limb == PLAYER_LIMB_R_HAND) {
            dlist = baseToPointer(this, CHILD_LINK_LUT_DL_RHAND);
        }
        else if (limb == PLAYER_LIMB_L_HAND) {
            dlist = baseToPointer(this, CHILD_LINK_LUT_DL_LHAND);
        }
        else if (limb == PLAYER_LIMB_SHEATH) {
            dlist = baseToPointer(this, CHILD_LINK_LUT_DL_SWORD_SHEATH);
        }
    }

    // Return default fucking hands.
    return dlist;
}

int32_t AnimateCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3f* pos, Vec3s* rot, entity_t* this) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;
    int32_t limbNumber = limbIndex; /*- 1; // OG puppet did this, but I think it's because our old enum began at ROOT instead of NONE */

    Actor_SetFeetPos(&this->actor, limbIndex, PLAYER_LIMB_L_FOOT, &footOffsets[this->puppet.age], PLAYER_LIMB_R_FOOT, &footOffsets[this->puppet.age]);

    // TODO:
    switch (limbNumber) {
        case PLAYER_LIMB_NONE:
            break;
        case PLAYER_LIMB_ROOT:
            break;
        case PLAYER_LIMB_WAIST:
            break;
        case PLAYER_LIMB_LOWER:
            break;
        case PLAYER_LIMB_R_THIGH:
            FootIK(globalCtx, this, &this->skelAnime, pos, rot, PLAYER_LIMB_R_THIGH, PLAYER_LIMB_R_SHIN, PLAYER_LIMB_R_FOOT);
            break;
        case PLAYER_LIMB_R_SHIN:
            break;
        case PLAYER_LIMB_R_FOOT:
            if (this->puppet.boots == PLAYER_BOOTS_IRON) {
                Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_BOOT_RHOVER));
            }
            else if (this->puppet.boots = PLAYER_BOOTS_HOVER) {
                Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_BOOT_RIRON));
            }
            break;
        case PLAYER_LIMB_L_THIGH:
            FootIK(globalCtx, this, &this->skelAnime, pos, rot, PLAYER_LIMB_L_THIGH, PLAYER_LIMB_L_SHIN, PLAYER_LIMB_L_FOOT);
            break;
        case PLAYER_LIMB_L_SHIN:
            break;
        case PLAYER_LIMB_L_FOOT:
            if (this->puppet.boots == PLAYER_BOOTS_IRON) {
                Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_BOOT_LHOVER));
            }
            else if (this->puppet.boots = PLAYER_BOOTS_HOVER) {
                Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_BOOT_LIRON));
            }
            break;
        case PLAYER_LIMB_UPPER:
            break;
        case PLAYER_LIMB_HEAD:
            if (!AGE_IS_ADULT(this->puppet.age)) {
                switch (this->puppet.mask)
                {
                    case OOT_MASK_KEATON:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_KEATON));
                        break;
                    case OOT_MASK_SKULL:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_SKULL));
                        break;
                    case OOT_MASK_SPOOKY:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_SPOOKY));
                        break;
                    case OOT_MASK_BUNNY_HOOD:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_BUNNY));
                        break;
                    case OOT_MASK_GORON:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_GORON));
                        break;
                    case OOT_MASK_ZORA:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_ZORA));
                        break;
                    case OOT_MASK_GERUDO:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_GERUDO));
                        break;
                    case OOT_MASK_TRUTH:
                        Gfx_DrawDListOpa(globalCtx, baseToPointer(this, CHILD_LINK_LUT_DL_MASK_TRUTH));
                        break;
                }
            }
            break;
        case PLAYER_LIMB_HAT:
            break;
        case PLAYER_LIMB_COLLAR:
            break;
        case PLAYER_LIMB_L_SHOULDER:
            break;
        case PLAYER_LIMB_L_FOREARM:
            if (this->puppet.strength) {
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorGauntlet.r, this->puppet.colorGauntlet.g, this->puppet.colorGauntlet.b, this->puppet.colorGauntlet.a);
                Gfx_DrawDListOpa(globalCtx, baseToPointer(this, AGE_IS_ADULT(this->puppet.age) ? ADULT_LINK_LUT_DL_UPGRADE_LFOREARM : CHILD_LINK_LUT_DL_GORON_BRACELET));
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);
            }
            break;
        case PLAYER_LIMB_L_HAND:
            Matrix_Push();
            Matrix_Translate(pos->x, pos->y, pos->z, 1);
            Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
            dList = AnimateCallback_HandsAndBack(this, limbNumber, globalCtx);
            Matrix_Pull();
            break;
        case PLAYER_LIMB_R_SHOULDER:
            break;
        case PLAYER_LIMB_R_FOREARM:
            if (this->puppet.strength) {
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorGauntlet.r, this->puppet.colorGauntlet.g, this->puppet.colorGauntlet.b, this->puppet.colorGauntlet.a);
                Gfx_DrawDListOpa(globalCtx, baseToPointer(this, ADULT_LINK_LUT_DL_UPGRADE_RFOREARM));
                gDPSetEnvColor(polyOpa->p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);
            }
            break;
        case PLAYER_LIMB_R_HAND:
            Matrix_Push();
            Matrix_Translate(pos->x, pos->y, pos->z, 1);
            Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
            dList = AnimateCallback_HandsAndBack(this, limbNumber, globalCtx);
            Matrix_Pull();
            break;
        case PLAYER_LIMB_SHEATH:
            dList = AnimateCallback_HandsAndBack(this, limbNumber, globalCtx);
            break;
        case PLAYER_LIMB_TORSO:
            break;
        case PLAYER_LIMB_MAX:
            break;
    }

    return 0;
}

int32_t OtherCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, entity_t* this) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    gSPSegment(polyOpa->p++, 8, this->puppet.eyeTexture);
    gSPSegment(polyOpa->p++, 9, baseToPointer(this, 0x4000));

    return 1;
}

void init(entity_t* this, GlobalContext* globalCtx) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    this->actor.room = 0xFF;
    this->puppet.age = globalCtx->linkAgeOnLoad; // Don't we need to set this?
    this->puppet.syncAnimation = player->skelAnime.animation;

    this->puppet.syncFrame = 0;
    this->puppet.syncSpeed = player->skelAnime.playSpeed;
    this->puppet.latencyFrames = 0;

    this->end4 = 0xDEEFBEAD;
    this->end = 0xDEADBEEF;

    SkelAnime_InitLink(globalCtx, &this->skelAnime,
        baseToPointerSkel(this, 0x500C), /* TODO: base + 0x0000500C? pointer to FlexSkeletonHeader; current method will not work for mm */
        player->skelAnime.animation,
        9, /* initflags */
        this->jointTable, this->morphTable, PLAYER_LIMB_MAX
    );

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

    //if (IsZobjLoaded(globalCtx, EPONA_OBJ)) {
    //    // TODO
    //}

    this->actor.flags |= 0x0E000075;
    MLDEBUG_END(this, 0xDEADBEEF);
}

void destroy(entity_t* this, GlobalContext* globalCtx) {
    if (this->actor.child) {
        this->actor.child->parent = 0;
        Actor_Kill(this->actor.child);
        this->actor.child = 0;
    }
}

void update(entity_t* this, GlobalContext* globalCtx) {
    Vec3f focusPos;
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

    const uint32_t eyes[3] = { baseToPointer(this, 0), baseToPointer(this, 0x800), baseToPointer(this, 0x1000) };
    Helper_EyeBlink(&this->puppet.eyeIndex);
    this->puppet.eyeTexture = eyes[this->puppet.eyeIndex];

    if (this->skelAnime.curFrame < this->puppet.syncFrame) this->skelAnime.curFrame = this->puppet.syncFrame;
    LinkAnimation_Update(globalCtx, &this->skelAnime);

    // Change animation if remote player's animation changed
    if (this->skelAnime.animation != this->puppet.syncAnimation) {
        // FIXME: Playas animations will not have the same animation pointer, we must find a way to safely sync these!
        // We could probably make a table that gives each custom animation a unique id, and use the index of the uuid for the index of the pointer
        // for example, let's say we have the uuid table [0xDEADBEEF, 0xABABBEEF, 0xBEEFDEAD, 0xBABADEAD]
        // to get the animation with the uuid BEEFDEAD, we would additionally have the table of pointers to the animations
        // so in this case, BEEFDEAD is the third uuid, at index 2
        // so we would do syncAnimation = animations[index]
        // this way we can have animation and playas stuff on the heap, and still write the correct pointer in the puppet
        // so we would instead sync the uuid, and have the puppet perform the scan to get the correct pointer
        // this would also be a good excuse to implement a system which does not allocate copies of existing data
        LinkAnimation_Change(globalCtx, &this->skelAnime, this->puppet.syncAnimation, this->puppet.syncSpeed, this->puppet.syncFrame, Animation_GetLength(this->puppet.syncAnimation), this->puppet.syncMode, this->puppet.latencyFrames);
    }

    focusPos = this->actor.world.pos;

    if (AGE_IS_ADULT(this->puppet.age)) focusPos.y += 68.0f; // camera uses these offsets, who knows if they work here
    else focusPos.y += 44.0f;

    this->actor.focus.pos = focusPos;
    this->actor.focus.rot = this->actor.world.rot;
}

void draw(entity_t* this, GlobalContext* globalCtx) {
    gDPSetEnvColor(globalCtx->game.gfxCtx->polyOpa.p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);

    // Teardrop / feet shadow drawn by callback from ActorShape_Init, feetpos is set in AnimateCallback
    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount, AnimateCallback, OtherCallback, this);

    if (this->puppet.soundId > 0) {
        Audio_PlaySoundAtPosition(globalCtx, &this->actor.world.pos, 25, this->puppet.soundId);
        this->puppet.soundId = 0;
    }
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

