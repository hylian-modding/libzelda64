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

// TODO: Copy from old puppet
#define EPONA_OBJ (0)
#define isSwordOut(action) (TEST_VALUE_RANGE(action, PLAYER_AP_SWORD_MASTER, PLAYER_AP_SWORD_KOKIRI))
#define baseToPointer(this, addr) ((*((uint32_t*)(&(this)->actor.home.rot))) + addr)
#define baseToPointerSkel(this, addr) (*((uint32_t*)((uint32_t)(*((uint32_t*)(&(this)->actor.home.rot))) + (addr))))

#ifdef _MLDEBUG
#define MLDEBUG_END(this, value) ((this)->end = (value))
#else
#define MLDEBUG_END(this, value)
#endif

// TODO: Remove
#undef AGE_IS_ADULT
#define AGE_IS_ADULT(a) (a == 0)

//!Old Stuff
//typedef struct {
//    /* 0x00 */ uint32_t age;
//    /* 0x04 */ float deku_stick_length;
//    /* 0x08 */ Color_RGBA8_u32 gauntlet_color;
//    /* 0x0C */ Color_RGBA8_u32 bottle_color;
//    /* 0x10 */ Color_RGBA8_u32 tunic_color;
//    /* 0x14 */ uint16_t sound_id;
//    /* 0x16 */ uint8_t tunic_id;
//    /* 0x17 */ uint8_t sword_id;
//    /* 0x18 */ uint8_t shield_id;
//    /* 0x19 */ uint8_t boots_id;
//    /* 0x1A */ uint8_t strength_upgrade_id;
//    /* 0x1B */ uint8_t hand_closed;
//    /* 0x1C */ uint8_t item_held_left;
//    /* 0x1D */ uint8_t item_held_right;
//    /* 0x1E */ uint8_t item_back;
//    /* 0x1F */ uint8_t item_mask;
//    /* 0x20 */ uint8_t action_param;
//    /* 0x21 */ uint8_t is_zz; // playas data is not in it's own structure to save a couple bytes due to alignment, it starts here
//    /* 0x22 */ uint16_t eye_index;
//    /* 0x24 */ uint32_t eye_texture;
//    /* 0x28 */ uint32_t skeleton;
//    /* 0x2C */ uint32_t base;
//} puppet_info_t; /* sizeof = 0x30 */

//typedef struct {
//    /* 0x000 */ Actor actor;
//    /* 0x13C */ uint8_t frame_data[0x86];
//    /* 0x1C2 */ int16_t _pad;
//    /* 0x1C4 */ SkelAnime skelanime;
//    /* 0x208 */ ColliderCylinder collider;
//    /* 0x254 */ puppet_info_t puppet;
//    /* 0x284 */ uint32_t end;
//} entity_t; /* sizeof = 0x288 */

///* 0x04 */ struct LinkAnimationHeader* syncAnimation; // player->skelAnime.animation (player + 0x1A4 + 0x8)
///* 0x08 */ float syncFrame; // player->skelAnime.curFrame (player + 0x1A4 + 0x18)
///* 0x0C */ float syncSpeed; // player->skelAnime.playSpeed (player + 0x1A4 + 0x1C)
///* 0x10 */ float latencyFrames; // latency in seconds(?), can calculate on node side//
///* 0x35 */ uint8_t syncMode;

typedef struct {
    /* 0x00 */ uint32_t age;
    /* 0x04 */ Color_RGBA8_u32 colorGauntlet;
    /* 0x08 */ Color_RGBA8_u32 colorBottle;
    /* 0x0C */ Color_RGBA8_u32 colorTunic;
    /* 0x10 */ uint32_t action;
    /* 0x14 */ float syncLinearVelocity;
    /* 0x18 */ float syncUnk_830;
    /* 0x1C */ uint32_t eyeTexture;
    /* 0x20 */ uint16_t eyeIndex;
    /* 0x22 */ uint16_t soundId;
    /* 0x24 */ uint8_t strength;
    /* 0x25 */ uint8_t boots;
    /* 0x26 */ uint8_t mask;
    /* 0x27 */ uint8_t pad[1];
    /* 0x28 */ uint32_t backDlist;
    /* 0x2C */ uint32_t rhandDlist;
    /* 0x30 */ uint32_t lhandDlist;
    uint32_t DEBUG_OUT;
} puppet_info_t; /* sizeof = 0x2C */

typedef struct {
    /* 0x000 */ SkelAnime skelAnime;
    /* 0x044 */ Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0D4 */ Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x164 */ struct LinkAnimationHeader* syncAnimation;
    /* 0x168 */ float syncFrame;
    /* 0x16C */ float syncSpeed;
    /* 0x170 */ float latencyFrames;
    /* 0x174 */ uint8_t syncMode;
    /* 0x175 */ uint8_t pad[3];
} SkelAnimeSyncPair; /* sizeof = 0x178 */

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x13C */ SkelAnimeSyncPair skelAnime0;
    /* 0x2B4 */ SkelAnimeSyncPair skelAnime1;
    /* 0x42C */ ColliderCylinder collider;
    /* 0x478 */ puppet_info_t puppet;
    /* 0x4A4 */ uint32_t end;
} entity_t; /* sizeof = 0x4A8 */

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

