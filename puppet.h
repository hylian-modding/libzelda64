#ifndef PUPPET_H
#define PUPPET_H

#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/ActorShape.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/Collider.h>
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/LinkAnimation.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/SkelAnime.h>
#include <libzelda64/lib/BGCheck.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/Player.h>
#include <libzelda64/lib/types/ColliderInitType1.h>
#include <libzelda64/lib/types/DamageTable.h>
#include <libzelda64/lib/types/StandardLimb.h>
#include <libultra/PR/gbi.h>
#include "Helpers.h"
#include "offsets.h"

// TODO: Copy from old puppet
#define EPONA_OBJ (0)

#define valueInRange(value, min, max) ((value) >= (min) && (value) <= (max))
#define isSwordOut(action) (valueInRange(action, PLAYER_AP_SWORD_MASTER, PLAYER_AP_SWORD_KOKIRI))

//*((uint32_t*)(*((uint32_t*)(&(this->actor.home.rot)))))
#define baseToPointer(this, addr) ((*((uint32_t*)(&(this)->actor.home.rot))) + addr)
#define baseToPointerSkel(this, addr) (*((uint32_t*)((uint32_t)(*((uint32_t*)(&(this)->actor.home.rot))) + (addr))))


#ifdef _MLDEBUG
#define MLDEBUG_END(this, value) ((this)->end = (value))
#else
#define MLDEBUG_END(this, value)
#endif

enum {
    OOT_MASK_NONE,
    OOT_MASK_KEATON,
    OOT_MASK_SKULL,
    OOT_MASK_SPOOKY,
    OOT_MASK_BUNNY_HOOD,
    OOT_MASK_GORON,
    OOT_MASK_ZORA,
    OOT_MASK_GERUDO,
    OOT_MASK_TRUTH,
    OOT_MASK_COUNT
} Oot_Mask;

typedef struct {
    /* 0x00 */ uint32_t age;
    /* 0x04 */ struct LinkAnimationHeader* syncAnimation; // player->skelAnime.animation (player + 0x1A4 + 0x8)
    /* 0x08 */ float syncFrame; // player->skelAnime.curFrame (player + 0x1A4 + 0x18)
    /* 0x0C */ float syncSpeed; // player->skelAnime.playSpeed (player + 0x1A4 + 0x1C)
    /* 0x10 */ float latencyFrames; // latency in seconds(?), can calculate on node side
    /* 0x14 */ Color_RGBA8_u32 colorGauntlet;
    /* 0x18 */ Color_RGBA8_u32 colorBottle;
    /* 0x1C */ Color_RGBA8_u32 colorTunic;
    /* 0x20 */ uint16_t soundId;
    /* 0x22 */ uint16_t eyeIndex;
    /* 0x24 */ uint32_t eyeTexture;
    /* 0x28 */ uint32_t unused;
    /* 0x2C */ uint32_t action;
    /* 0x30 */ uint8_t strength;
    /* 0x31 */ uint8_t boots;
    /* 0x32 */ uint8_t shield;
    /* 0x33 */ uint8_t shield_on_back;
    /* 0x34 */ uint8_t mask;
    /* 0x35 */ uint8_t syncMode;
    /* 0x36 */ uint8_t pad[2];
} puppet_info_t; /* sizeof = 0x38 */

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x13C */ SkelAnime skelAnime;
    /* 0x180 */ Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x210 */ Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x2A0 */ ColliderCylinder collider;
    /* 0x2EC */ puppet_info_t puppet;
    /* 0x308 */ uint32_t end;
    /* 0x30C */ uint32_t end0;
    /* 0x30C */ uint32_t end1;
    /* 0x30C */ uint32_t end2;
    /* 0x30C */ uint32_t end3;
    /* 0x30C */ uint32_t end4;
} entity_t; /* sizeof = 0x310 */

// copy of Link's default ColliderCylinderInit
const ColliderCylinderInit colliderInit = {
    {   // ColiderInit base
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {   // ColliderInfoInit info
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 }, // ColliderTouch toucher
        { 0xFFCFFFFF, 0x00, 0x00 }, // ColliderBumpInit bumper
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    }, // Cylinder16 dim
    { 12, 60, 0, { 0, 0, 0 } },
};

// 1 damage unit = 1 / 16 heart when passed through Health_ChangeBy
// however, the damage nibble is 0-F, so we need to use effects to apply damage correctly
// in this case, we will store damage as 1 unit =  (1 / 16) / 4
const DamageTable damageTable = {
                        // first entry is amount of damage, second is effect index (0-15) which is entirely arbitrary (we have to impl)
    /* Deku nut      */ DMG_ENTRY(0x01, 0),
    /* Deku stick    */ DMG_ENTRY(0x08, 0),
    /* Slingshot     */ DMG_ENTRY(0x02, 0),
    /* Explosive     */ DMG_ENTRY(0x0A, 1),
    /* Boomerang     */ DMG_ENTRY(0x04, 0),
    /* Normal arrow  */ DMG_ENTRY(0x08, 2),
    /* Hammer swing  */ DMG_ENTRY(0x08, 0),
    /* Hookshot      */ DMG_ENTRY(0x01, 0),
    /* Kokiri sword  */ DMG_ENTRY(0x04, 0),
    /* Master sword  */ DMG_ENTRY(0x06, 0),
    /* Giant's Knife */ DMG_ENTRY(0x07, 0),
    /* Fire arrow    */ DMG_ENTRY(0x0A, 3),
    /* Ice arrow     */ DMG_ENTRY(0x0A, 4),
    /* Light arrow   */ DMG_ENTRY(0x0A, 5),
    /* Unk arrow 1   */ DMG_ENTRY(0x08, 2),
    /* Unk arrow 2   */ DMG_ENTRY(0x08, 2),
    /* Unk arrow 3   */ DMG_ENTRY(0x08, 2),
    /* Fire magic    */ DMG_ENTRY(0x04, 3),
    /* Ice magic     */ DMG_ENTRY(0x04, 4),
    /* Light magic   */ DMG_ENTRY(0x04, 5),
    /* Shield        */ DMG_ENTRY(0x00, 0), // ??
    /* Mirror Ray    */ DMG_ENTRY(0x00, 0), // ??
    /* Kokiri spin   */ DMG_ENTRY(0x06, 0),
    /* Giant spin    */ DMG_ENTRY(0x0F, 0),
    /* Master spin   */ DMG_ENTRY(0x0F, 0),
    /* Kokiri jump   */ DMG_ENTRY(0x08, 0),
    /* Giant jump    */ DMG_ENTRY(0x0E, 0),
    /* Master jump   */ DMG_ENTRY(0x06, 0),
    /* Unknown 1     */ DMG_ENTRY(0x00, 0),
    /* Unblockable   */ DMG_ENTRY(0x00, 0),
    /* Hammer jump   */ DMG_ENTRY(0x0C, 0),
    /* Unknown 2     */ DMG_ENTRY(0x00, 0)
};

/*
uint32_t unkchart[] =
    {
        0x0100000F, 0x001E1E00};

uint8_t damagechart[] =
    {
        0x10, 0xF2, 0x11, 0xF2, 0x11, 0xF2, 0xE2, 0x01,
        0x11, 0xE2, 0xE4, 0xF2, 0xD2, 0xF4, 0xF2, 0xF2,
        0xFF, 0x60, 0x60, 0x60, 0x00, 0x00, 0xE3, 0xE4,
        0xE5, 0xE5, 0xE5, 0xE6, 0xFA, 0x00, 0xE6, 0x00};
        actor->colChkInfo.damageTable->table[index] // index is 0 to 20

        z_actor_damage_table_init(AADDR(&en->actor, 0x98), &damagechart, &unkchart); // damage chart
*/

const Vec3f footOffsets[] = {
    { 200.0f, 300.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f }
};

const float shadowScales[] = { 90.0f, 60.0f };

const Color_RGBA8_u32 white = {.rgba = 0xFFFFFFFF};

// TODO: Remove
#undef AGE_IS_ADULT
#define AGE_IS_ADULT(a) (1)

#endif

