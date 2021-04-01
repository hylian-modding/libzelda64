#ifndef __OVL_EN_OOTO_PUPPET__
#define __OVL_EN_OOTO_PUPPET__

#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/ActorShape.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/Collider.h>
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/LinkAnimation.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/SkelAnime.h>
#include <libzelda64/lib/BGCheck.h>
#include <libzelda64/lib/AnimationContext.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/Player.h>
#include <libzelda64/lib/types/ColliderInitType1.h>
#include <libzelda64/lib/types/DamageTable.h>
#include <libzelda64/lib/types/StandardLimb.h>
#include <libzelda64/lib/Macros.h>
#include <ultra64.h>
#include "Helpers.h"
#include "deps/lut_offsets.h"
#include "deps/collider.h"
#include "deps/happy_mask.h"
#include "./tpose.h"

#define F3DEX_GBI_2 1
#define _LANGUAGE_C 1
#include <libultra/PR/gbi.h>

#define baseToPointer(this, addr) ((*((uint32_t*)(&(this)->actor.home.rot))) + addr)
#define baseToPointerSkel(this, addr) (*((uint32_t*)((uint32_t)(*((uint32_t*)(&(this)->actor.home.rot))) + (addr))))
#define deref(addr) *((uint32_t*) addr)

#ifdef _MLDEBUG
#define MLDEBUG_END(this, value) ((this)->end = (value))
#else
#define MLDEBUG_END(this, value)
#endif

typedef struct {
    Vec3s anim[PLAYER_LIMB_BUF_COUNT];
    uint16_t age;
    Color_RGBA8_u32 colorGauntlet;
    Color_RGBA8_u32 colorBottle;
    Color_RGBA8_u32 colorTunic;
    uint32_t eyeTexture;
    uint16_t eyeIndex;
    uint16_t soundId;
    uint8_t strength;
    uint8_t currentSword;
    uint8_t currentShield;
    uint8_t currentBoots;
    uint8_t currentMask;
    uint8_t action;
    uint8_t action2;
    uint32_t stateFlags1;
    uint32_t stateFlags2;
    uint32_t stateFlags3;
    struct {
        vec3s_t rot;
        vec3s_t unk;
    } bunny_hood;
} puppet_info_t;

typedef struct {
    SkelAnime skelAnime;
    Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
} SkelAnimeSyncPair;

typedef struct {
    Actor actor;
    SkelAnimeSyncPair skelAnime0;
    ColliderCylinder collider;
    puppet_info_t puppet;
    uint32_t DEBUG_OUT;
    uint32_t end;
} entity_t;

static void init(entity_t* this, GlobalContext* globalCtx);
static void destroy(entity_t* this, GlobalContext* globalCtx);
static void update(entity_t* this, GlobalContext* globalCtx);
static void draw(entity_t* this, GlobalContext* globalCtx);

ActorInit initVars = {
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

#endif /* __OVL_EN_OOTO_PUPPET__ */

