#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

#include "../zelda64_version.h"
#include "Actor.h"
#include "ColliderCylinder.h"
#include "ColliderQuad.h"
#include "DmaRequest.h"
#include "MtxF.h"
#include "SkelAnime.h"
#include "WeaponInfo.h"
#include <inttypes.h>
#include <libultra/PR/os.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef enum {
    /* 0x00 */ PLAYER_SHIELD_NONE,
    /* 0x01 */ PLAYER_SHIELD_DEKU,
    /* 0x02 */ PLAYER_SHIELD_HYLIAN,
    /* 0x03 */ PLAYER_SHIELD_MIRROR,
    /* 0x04 */ PLAYER_SHIELD_MAX
} PlayerShield;

typedef enum {
    /* 0x00 */ PLAYER_TUNIC_KOKIRI,
    /* 0x01 */ PLAYER_TUNIC_GORON,
    /* 0x02 */ PLAYER_TUNIC_ZORA,
    /* 0x03 */ PLAYER_TUNIC_MAX
} PlayerTunic;

typedef enum {
    /* 0x00 */ PLAYER_BOOTS_NORMAL,
    /* 0x01 */ PLAYER_BOOTS_IRON,
    /* 0x02 */ PLAYER_BOOTS_HOVER,
    /* Values below are only relevant when setting regs in Player_SetBootData */
    /* 0x03 */ PLAYER_BOOTS_INDOOR,
    /* 0x04 */ PLAYER_BOOTS_IRON_UNDERWATER,
    /* 0x05 */ PLAYER_BOOTS_NORMAL_CHILD,
    /* 0x06 */ PLAYER_BOOTS_MAX
} PlayerBoots;

typedef enum {
    /* 0x00 */ PLAYER_STR_NONE,
    /* 0x01 */ PLAYER_STR_BRACELET,
    /* 0x02 */ PLAYER_STR_SILVER_G,
    /* 0x03 */ PLAYER_STR_GOLD_G,
    /* 0x04 */ PLAYER_STR_MAX
} PlayerStrength;

typedef enum {
    /* 0x00 */ PLAYER_MASK_NONE,
    /* 0x01 */ PLAYER_MASK_KEATON,
    /* 0x02 */ PLAYER_MASK_SKULL,
    /* 0x03 */ PLAYER_MASK_SPOOKY,
    /* 0x04 */ PLAYER_MASK_BUNNY,
    /* 0x05 */ PLAYER_MASK_GORON,
    /* 0x06 */ PLAYER_MASK_ZORA,
    /* 0x07 */ PLAYER_MASK_GERUDO,
    /* 0x08 */ PLAYER_MASK_TRUTH,
    /* 0x09 */ PLAYER_MASK_MAX
} PlayerMask;

typedef enum {
    /* 0x00 */ PLAYER_AP_NONE,
    /* 0x01 */ PLAYER_AP_LAST_USED,
    /* 0x02 */ PLAYER_AP_FISHING_POLE,
    /* 0x03 */ PLAYER_AP_SWORD_MASTER,
    /* 0x04 */ PLAYER_AP_SWORD_KOKIRI,
    /* 0x05 */ PLAYER_AP_SWORD_BGS,
    /* 0x06 */ PLAYER_AP_STICK,
    /* 0x07 */ PLAYER_AP_HAMMER,
    /* 0x08 */ PLAYER_AP_BOW,
    /* 0x09 */ PLAYER_AP_BOW_FIRE,
    /* 0x0A */ PLAYER_AP_BOW_ICE,
    /* 0x0B */ PLAYER_AP_BOW_LIGHT,
    /* 0x0C */ PLAYER_AP_BOW_0C,
    /* 0x0D */ PLAYER_AP_BOW_0D,
    /* 0x0E */ PLAYER_AP_BOW_0E,
    /* 0x0F */ PLAYER_AP_SLINGSHOT,
    /* 0x10 */ PLAYER_AP_HOOKSHOT,
    /* 0x11 */ PLAYER_AP_LONGSHOT,
    /* 0x12 */ PLAYER_AP_BOMB,
    /* 0x13 */ PLAYER_AP_BOMBCHU,
    /* 0x14 */ PLAYER_AP_BOOMERANG,
    /* 0x15 */ PLAYER_AP_MAGIC_SPELL_15,
    /* 0x16 */ PLAYER_AP_MAGIC_SPELL_16,
    /* 0x17 */ PLAYER_AP_MAGIC_SPELL_17,
    /* 0x18 */ PLAYER_AP_FARORES_WIND,
    /* 0x19 */ PLAYER_AP_NAYRUS_LOVE,
    /* 0x1A */ PLAYER_AP_DINS_FIRE,
    /* 0x1B */ PLAYER_AP_NUT,
    /* 0x1C */ PLAYER_AP_OCARINA_FAIRY,
    /* 0x1D */ PLAYER_AP_OCARINA_TIME,
    /* 0x1E */ PLAYER_AP_BOTTLE,
    /* 0x1F */ PLAYER_AP_BOTTLE_FISH,
    /* 0x20 */ PLAYER_AP_BOTTLE_FIRE,
    /* 0x21 */ PLAYER_AP_BOTTLE_BUG,
    /* 0x22 */ PLAYER_AP_BOTTLE_POE,
    /* 0x23 */ PLAYER_AP_BOTTLE_BIG_POE,
    /* 0x24 */ PLAYER_AP_BOTTLE_LETTER,
    /* 0x25 */ PLAYER_AP_BOTTLE_POTION_RED,
    /* 0x26 */ PLAYER_AP_BOTTLE_POTION_BLUE,
    /* 0x27 */ PLAYER_AP_BOTTLE_POTION_GREEN,
    /* 0x28 */ PLAYER_AP_BOTTLE_MILK,
    /* 0x29 */ PLAYER_AP_BOTTLE_MILK_HALF,
    /* 0x2A */ PLAYER_AP_BOTTLE_FAIRY,
    /* 0x2B */ PLAYER_AP_LETTER_ZELDA,
    /* 0x2C */ PLAYER_AP_WEIRD_EGG,
    /* 0x2D */ PLAYER_AP_CHICKEN,
    /* 0x2E */ PLAYER_AP_BEAN,
    /* 0x2F */ PLAYER_AP_POCKET_EGG,
    /* 0x30 */ PLAYER_AP_POCKET_CUCCO,
    /* 0x31 */ PLAYER_AP_COJIRO,
    /* 0x32 */ PLAYER_AP_ODD_MUSHROOM,
    /* 0x33 */ PLAYER_AP_ODD_POTION,
    /* 0x34 */ PLAYER_AP_SAW,
    /* 0x35 */ PLAYER_AP_SWORD_BROKEN,
    /* 0x36 */ PLAYER_AP_PRESCRIPTION,
    /* 0x37 */ PLAYER_AP_FROG,
    /* 0x38 */ PLAYER_AP_EYEDROPS,
    /* 0x39 */ PLAYER_AP_CLAIM_CHECK,
    /* 0x3A */ PLAYER_AP_MASK_KEATON,
    /* 0x3B */ PLAYER_AP_MASK_SKULL,
    /* 0x3C */ PLAYER_AP_MASK_SPOOKY,
    /* 0x3D */ PLAYER_AP_MASK_BUNNY,
    /* 0x3E */ PLAYER_AP_MASK_GORON,
    /* 0x3F */ PLAYER_AP_MASK_ZORA,
    /* 0x40 */ PLAYER_AP_MASK_GERUDO,
    /* 0x41 */ PLAYER_AP_MASK_TRUTH,
    /* 0x42 */ PLAYER_AP_LENS,
    /* 0x43 */ PLAYER_AP_MAX
} PlayerActionParam;

// Player Action Flags
#define PLAYER_ACTION_NORMAL            (0)
#define PLAYER_ACTION_SCENE_CHANGE_DEMO (1)
//#define	PLAYER_ACTION_TURN			      (1<<1)
#define PLAYER_ACTION_BOTTLE_ATTACK (1 << 1)
//#define	PLAYER_ACTION_FIGHT			      (1<<2)
#define PLAYER_ACTION_HOOK_FLY_END    (1 << 2)
#define PLAYER_ACTION_BOW             (1 << 3)
#define PLAYER_ACTION_ANCHOR_FIGHT    (1 << 4)
#define PLAYER_ACTION_NO_KEY_MODE     (1 << 5)
#define PLAYER_ACTION_TALK            (1 << 6)
#define PLAYER_ACTION_DOWN            (1 << 7)
#define PLAYER_ACTION_AUTO_FIGHT      (1 << 8)
#define PLAYER_ACTION_ARROW_CATCH     (1 << 9)
#define PLAYER_ACTION_GET_ITEM        (1 << 10)
#define PLAYER_ACTION_CARRY           (1 << 11)
#define PLAYER_ACTION_POWER_KIRU      (1 << 12)
#define PLAYER_ACTION_FALL            (1 << 13)
#define PLAYER_ACTION_JUMP_CLIMB      (1 << 14)
#define PLAYER_ACTION_ANCHOR          (1 << 15)
#define PLAYER_ACTION_KEEPON          (1 << 16)
#define PLAYER_ACTION_PARALLEL        (1 << 17)
#define PLAYER_ACTION_JUMP            (1 << 18)
#define PLAYER_ACTION_FREEFALL        (1 << 19)
#define PLAYER_ACTION_SUBJECT         (1 << 20)
#define PLAYER_ACTION_LADDER          (1 << 21)
#define PLAYER_ACTION_DEFENSE         (1 << 22)
#define PLAYER_ACTION_RIDE_HORSE      (1 << 23)
#define PLAYER_ACTION_BOOM            (1 << 24)
#define PLAYER_ACTION_BOOM_THROW      (1 << 25)
#define PLAYER_ACTION_DAMAGE          (1 << 26)
#define PLAYER_ACTION_SWIM            (1 << 27)
#define PLAYER_ACTION_ALL_STOP_DEMO   (1 << 28)
#define PLAYER_ACTION_DEMO            (1 << 29)
#define PLAYER_ACTION_PARALLEL_CAMERA (1 << 30)
#define PLAYER_ACTION_WARP_FALL       (1 << 31)
#define PLAYER_ACTION_DONT_CARRY \
    (PLAYER_ACTION_DOWN | PLAYER_ACTION_POWER_KIRU | PLAYER_ACTION_FALL | PLAYER_ACTION_JUMP_CLIMB | PLAYER_ACTION_JUMP | PLAYER_ACTION_FREEFALL | PLAYER_ACTION_SUBJECT | PLAYER_ACTION_LADDER)
#define PLAYER_ACTION_DONT_RIDE           (PLAYER_ACTION_DONT_CARRY | PLAYER_ACTION_CARRY)
#define PLAYER_ACTION_DONT_COMPAS         (PLAYER_ACTION_ANCHOR_FIGHT | PLAYER_ACTION_POWER_KIRU | PLAYER_ACTION_FALL | PLAYER_ACTION_JUMP_CLIMB | PLAYER_ACTION_SUBJECT)
#define PLAYER_ACTION2_PUSH_PULL_OK       (1)
#define PLAYER_ACTION2_TALK_OK            (1 << 1)
#define PLAYER_ACTION2_STEPUP_OK          (1 << 2)
#define PLAYER_ACTION2_BIG_SE_SET         (1 << 3)
#define PLAYER_ACTION2_PUSH_PULL          (1 << 4)
#define PLAYER_ACTION2_NO_ANCHOR_ANGLE    (1 << 5)
#define PLAYER_ACTION2_NO_SHAPE_ANGLE     (1 << 6)
#define PLAYER_ACTION2_RE_DEAD_ATTACK     (1 << 7)
#define PLAYER_ACTION2_PUSH_PULL_CATCH    (1 << 8)
#define PLAYER_ACTION2_SAND_SOUND_SET     (1 << 9)
#define PLAYER_ACTION2_SWIM_DEEP          (1 << 10)
#define PLAYER_ACTION2_SWIM_DEEP_CAMERA   (1 << 11)
#define PLAYER_ACTION2_CLIMB_STOP         (1 << 12)
#define PLAYER_ACTION2_ANCHOR_ROCK        (1 << 13)
#define PLAYER_ACTION2_ICE_DOWN           (1 << 14)
#define PLAYER_ACTION2_STOP_FLAG          (1 << 15)
#define PLAYER_ACTION2_TUNNEL_OK          (1 << 16)
#define PLAYER_ACTION2_POWER_KIRU_SHOT    (1 << 17)
#define PLAYER_ACTION2_TUNNEL             (1 << 18)
#define PLAYER_ACTION2_DEMO_JUMP          (1 << 19)
#define PLAYER_ACTION2_ELF_ACTION         (1 << 20)
#define PLAYER_ACTION2_ELF_MAIL_OK        (1 << 21)
#define PLAYER_ACTION2_RIDE_HORSE_END_OK  (1 << 22)
#define PLAYER_ACTION2_OKARINA_REQUEST    (1 << 23)
#define PLAYER_ACTION2_OKARINA_REQUEST_OK (1 << 24)
#define PLAYER_ACTION2_OKARINA_ACTOR_OK   (1 << 25)
#define PLAYER_ACTION2_MIRROR_DISPLAY     (1 << 26)
#define PLAYER_ACTION2_OKARINA_MODE       (1 << 27)
#define PLAYER_ACTION2_WAIT               (1 << 28)
#define PLAYER_ACTION2_NO_DISPLAY         (1 << 29)
#define PLAYER_ACTION2_KIRU_TRANSLATE     (1 << 30)
#define PLAYER_ACTION2_WATER_FALL         (1 << 31)
#define PLAYER_ACTION3_GROUND_NO_CHECK    (1)
#define PLAYER_ACTION3_SKY                (1 << 1)
#define PLAYER_ACTION3_MOVE_STOP          (1 << 2)
#define PLAYER_ACTION3_KIRU_END           (1 << 3)
#define PLAYER_ACTION3_GROUND_CHECKED     (1 << 4)
#define PLAYER_ACTION3_TO_OKARINA         (1 << 5)
#define PLAYER_ACTION3_SHIELD_REMAKE      (1 << 6)
#define PLAYER_ACTION3_HOOK_FLY           (1 << 7)

typedef enum {
    /* 0x00 */ PLAYER_LIMB_NONE,
    /* 0x01 */ PLAYER_LIMB_ROOT,
    /* 0x02 */ PLAYER_LIMB_WAIST,
    /* 0x03 */ PLAYER_LIMB_LOWER,
    /* 0x04 */ PLAYER_LIMB_THIGH_R,
    /* 0x05 */ PLAYER_LIMB_SHIN_R,
    /* 0x06 */ PLAYER_LIMB_FOOT_R,
    /* 0x07 */ PLAYER_LIMB_THIGH_L,
    /* 0x08 */ PLAYER_LIMB_SHIN_L,
    /* 0x09 */ PLAYER_LIMB_FOOT_L,
    /* 0x0A */ PLAYER_LIMB_UPPER,
    /* 0x0B */ PLAYER_LIMB_HEAD,
    /* 0x0C */ PLAYER_LIMB_HAT,
    /* 0x0D */ PLAYER_LIMB_COLLAR,
    /* 0x0E */ PLAYER_LIMB_SHOULDER_L,
    /* 0x0F */ PLAYER_LIMB_FOREARM_L,
    /* 0x10 */ PLAYER_LIMB_HAND_L,
    /* 0x11 */ PLAYER_LIMB_SHOULDER_R,
    /* 0x12 */ PLAYER_LIMB_FOREARM_R,
    /* 0x13 */ PLAYER_LIMB_HAND_R,
    /* 0x14 */ PLAYER_LIMB_SHEATH,
    /* 0x15 */ PLAYER_LIMB_TORSO,
    /* 0x16 */ PLAYER_LIMB_MAX
} PlayerLimb;

typedef enum {
    /* 0 */ ANIMMODE_LOOP,
    /* 1 */ ANIMMODE_LOOP_INTERP,
    /* 2 */ ANIMMODE_ONCE,
    /* 3 */ ANIMMODE_ONCE_INTERP,
    /* 4 */ ANIMMODE_LOOP_PARTIAL,
    /* 5 */ ANIMMODE_LOOP_PARTIAL_INTERP
} AnimationModes;

typedef enum {
    /* 0 */ PLAYER_AGE_ADULT,
    /* 1 */ PLAYER_AGE_CHILD
} Ages;

#define PLAYER_LIMB_BUF_COUNT PLAYER_LIMB_MAX + 2 // 2 extra entries in limb buffers?

#define AGE_IS_ADULT(age) (age == 0)

typedef void (*PlayerFunc674)(struct Player*, struct GlobalContext*);
typedef int32_t (*PlayerFunc82C)(struct Player*, struct GlobalContext*);
typedef void (*PlayerFuncA74)(struct GlobalContext*, struct Player*);

typedef struct Player {
    /* 0x0000 */ Actor actor;
    /* 0x013C */ int8_t currentTunic;        // current tunic from `PlayerTunic`
    /* 0x013D */ int8_t currentSword;        // current sword Item ID
    /* 0x013E */ int8_t currentShield;       // current shield from `PlayerShield`
    /* 0x013F */ int8_t currentBoots;        // current boots from `PlayerBoots`
    /* 0x0140 */ int8_t heldItemButton;      // Button index for the item currently used
    /* 0x0141 */ int8_t heldItemActionParam; // Action param for the item currently used
    /* 0x0142 */ uint8_t heldItemId;         // Item id for the item currently used
    /* 0x0143 */ int8_t prevBoots;           // previous boots from `PlayerBoots`
    /* 0x0144 */ int8_t itemActionParam;     // the difference between this and heldItemActionParam is unclear
    /* 0x0145 */ int8_t unk_145[0x003];
    /* 0x0148 */ uint8_t modelGroup;
    /* 0x0149 */ uint8_t nextModelGroup;
    /* 0x014A */ int8_t unk_14A;
    /* 0x014B */ uint8_t modelAnimType;
    /* 0x014C */ uint8_t leftHandType;
    /* 0x014D */ uint8_t rightHandType;
    /* 0x014E */ uint8_t sheathType;
    /* 0x014F */ uint8_t currentMask; // current mask equipped from `PlayerMask`
    /* 0x0150 */ struct Gfx** rightHandDLists;
    /* 0x0154 */ struct Gfx** leftHandDLists;
    /* 0x0158 */ struct Gfx** sheathDLists;
    /* 0x015C */ struct Gfx** waistDLists;
    /* 0x0160 */ uint8_t giObjectLoading;
    /* 0x0164 */ DmaRequest giObjectDmaRequest;
    /* 0x0184 */ OSMesgQueue giObjectLoadQueue;
    /* 0x019C */ OSMesg giObjectLoadMsg;
    /* 0x01A0 */ void* giObjectSegment; // also used for title card textures
    /* 0x01A4 */ SkelAnime skelAnime;
    /* 0x01E8 */ Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0278 */ Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0308 */ Vec3s blendTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0398 */ int16_t unk_398[2];
    /* 0x039C */ struct Actor* heldActor;
    /* 0x03A0 */ Vec3f leftHandPos;
    /* 0x03AC */ Vec3s unk_3AC;
    /* 0x03B4 */ struct Actor* unk_3B4;
    /* 0x03B8 */ Vec3f unk_3B8;
    /* 0x03C4 */ int8_t unk_3C4[0x058];
    /* 0x041C */ int8_t doorType;
    /* 0x041D */ int8_t doorDirection;
    /* 0x041E */ int16_t doorTimer;
    /* 0x0420 */ struct Actor* doorActor;
    /* 0x0424 */ int8_t getItemId;
    /* 0x0426 */ uint16_t getItemDirection;
    /* 0x0428 */ struct Actor* interactRangeActor;
    /* 0x042C */ int8_t unk_42C;
    /* 0x042D */ int8_t unk_42D[0x003];
    /* 0x0430 */ struct Actor* rideActor;
    /* 0x0434 */ uint8_t csMode;
    /* 0x0435 */ uint8_t prevCsMode;
    /* 0x0436 */ uint8_t unk_436;
    /* 0x0437 */ uint8_t unk_437;
    /* 0x0438 */ struct Actor* unk_438;
    /* 0x043C */ int8_t unk_43C[0x004];
    /* 0x0440 */ Vec3f unk_440;
    /* 0x044C */ Vec3f unk_44C;
    /* 0x0468 */ int8_t unk_458[0x002];
    /* 0x046A */ int16_t unk_45A;
    /* 0x046C */ int16_t unk_45C;
    /* 0x046E */ int8_t unk_45E[0x02A];
    /* 0x0488 */ ColliderCylinder cylinder;
    /* 0x04D4 */ ColliderQuad swordQuads[2];
    /* 0x05D4 */ ColliderQuad shieldQuad;
    /* 0x0654 */ struct Actor* unk_654;
    /* 0x0658 */ int8_t unk_658[0x004];
    /* 0x065C */ int32_t unk_65C;
    /* 0x0660 */ int32_t swordEffectIndex;
    /* 0x0664 */ PlayerFunc674 func_674;
    /* 0x0668 */ struct PlayerAgeProperties* ageProperties;
    /* 0x066C */ uint32_t stateFlags1;
    /* 0x0670 */ uint32_t stateFlags2;
    /* 0x0674 */ struct Actor* unk_674;
    /* 0x0678 */ struct Actor* boomerangActor;
    union {
        /* 0x067C */ struct Actor* naviActor;
        /* 0x067C */ struct Actor* tatlActor;
        /* 0x067C */ struct Actor* fairyActor;
    };
    union {
        /* 0x0680 */ int16_t naviTextId;
        /* 0x0680 */ int16_t tatlTextId;
        /* 0x0680 */ int16_t fairyTextId;
    };
    /* 0x0682 */ uint8_t stateFlags3;
    /* 0x0683 */ int8_t exchangeItemId;
    /* 0x0684 */ struct Actor* targetActor;
    /* 0x0688 */ float targetActorDistance;
    /* 0x068C */ int8_t unk_68C[0x004];
    /* 0x0690 */ float unk_690;
    /* 0x0694 */ float unk_694;
    /* 0x0698 */ struct Actor* unk_698;
    /* 0x069C */ int8_t unk_69C;
    /* 0x069D */ uint8_t unk_69D;
    /* 0x069E */ uint16_t unk_69E;
    /* 0x06A0 */ int16_t unk_6A0;
    /* 0x06A2 */ int8_t unk_6A4[0x004];
    /* 0x06A6 */ int16_t unk_6A6;
    /* 0x06A8 */ int16_t unk_6A8;
    /* 0x06AA */ int16_t unk_6AA;
    /* 0x06AC */ vec3s_t bodyAngle;
    /* 0x06B2 */ int16_t unk_6B2;
    /* 0x06B4 */ float unk_6B4;
    /* 0x06B8 */ SkelAnime skelAnime2;
    /* 0x06FC */ Vec3s jointTable2[PLAYER_LIMB_BUF_COUNT];
    /* 0x078C */ Vec3s morphTable2[PLAYER_LIMB_BUF_COUNT];
    /* 0x081C */ PlayerFunc82C func_81C;
    /* 0x0820 */ float unk_820;
    /* 0x0824 */ int16_t unk_824;
    /* 0x0826 */ int8_t unk_826;
    /* 0x0827 */ uint8_t unk_827;
    /* 0x0828 */ float linearVelocity;
    /* 0x082C */ int16_t currentYaw;
    /* 0x082E */ int16_t targetYaw;
    /* 0x0830 */ uint16_t unk_830;
    /* 0x0832 */ int8_t swordAnimation;
    /* 0x0833 */ int8_t swordState;
    /* 0x0834 */ int8_t unk_834;
    /* 0x0835 */ uint8_t unk_835;
    /* 0x0836 */ uint8_t unk_836;
    /* 0x0837 */ int8_t unk_837[4];
    /* 0x083B */ int8_t unk_83B[4];
    /* 0x083F */ int8_t unk_83F;
    /* 0x0840 */ int16_t unk_840; // multipurpose timer
    /* 0x0844 */ float unk_844;
    /* 0x0848 */ float unk_848;
    /* 0x084C */ float unk_84C;   // stick length among other things
    /* 0x0850 */ int16_t unk_850; // stick flame timer among other things
    /* 0x0852 */ int8_t unk_852;  // get item draw ID + 1
    /* 0x0854 */ float unk_854;
    /* 0x0858 */ float unk_858;
    /* 0x085C */ float unk_85C;
    /* 0x0860 */ float unk_860;
    /* 0x0864 */ float unk_864;
    /* 0x0868 */ float unk_868;
    /* 0x086C */ int16_t unk_86C;
    /* 0x086E */ int16_t unk_86E;
    /* 0x0870 */ float unk_870;
    /* 0x0874 */ float wallHeight;   // height used to determine whether link can climb or grab a ledge at the top
    /* 0x0878 */ float wallDistance; // distance to the colliding wall plane
    /* 0x087C */ uint8_t unk_87C;
    /* 0x087D */ uint8_t unk_87D;
    /* 0x087E */ uint8_t unk_87E;
    /* 0x087F */ uint8_t unk_87F;
    /* 0x0880 */ uint8_t unk_880;
    /* 0x0881 */ uint8_t shockTimer;
    /* 0x0882 */ uint8_t unk_882;
    /* 0x0883 */ uint8_t unk_883;
    /* 0x0884 */ int16_t fallStartHeight; // last truncated Y position before falling
    /* 0x0886 */ int16_t fallDistance;    // truncated Y distance the player has fallen so far (positive is down)
    /* 0x0888 */ int16_t unk_888;
    /* 0x088A */ int16_t unk_88A;
    /* 0x088C */ int16_t unk_88C;
    /* 0x088E */ uint16_t unk_88E;
    /* 0x0890 */ uint8_t unk_890;
    /* 0x0891 */ uint8_t unk_891;
    /* 0x0892 */ int16_t unk_892;
    /* 0x0894 */ float unk_894;
    /* 0x0898 */ float unk_898;
    /* 0x089C */ float windSpeed;
    /* 0x08A0 */ int16_t windDirection;
    /* 0x08A4 */ WeaponInfo swordInfo[3];
    /* 0x08F8 */ Vec3f bodyPartsPos[18];
    /* 0x09D0 */ MtxF swordMtxF;
    /* 0x0A10 */ MtxF shieldMtxF;
    /* 0x0A50 */ uint8_t isBurning;
    /* 0x0A51 */ uint8_t flameTimers[18]; // one flame per body part
    /* 0x0A63 */ uint8_t unk_A63;
    /* 0x0A64 */ PlayerFuncA74 func_A74;
    /* 0x0A68 */ int8_t invincibilityTimer; // prevents damage when nonzero (positive = visible, counts towards zero each frame)
    /* 0x0A69 */ uint8_t unk_A69;
    /* 0x0A6A */ uint8_t unk_A6A;
    /* 0x0A6B */ uint8_t unk_A6B;
    /* 0x0A6C */ float dekuStickLength;
    /* 0x0A70 */ int16_t dekuStickAngle;
    /* 0x0A72 */ uint16_t unk_A72;
    /* 0x0A74 */ int16_t unk_A74;
    /* 0x0A76 */ int8_t unk_A76;
    /* 0x0A77 */ uint8_t unk_A77;
    /* 0x0A78 */ Vec3f unk_A78; // previous body part 0 position
} Player;                       /* sizeof = 0xA84 */
#else                           /* GAME_VERSION_1_0 */
#warning "Actor is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef enum {
    /* 0x00 */ PLAYER_SHIELD_NONE,
    /* 0x01 */ PLAYER_SHIELD_HEROS_SHIELD,
    /* 0x02 */ PLAYER_SHIELD_MIRROR_SHIELD,
    /* 0x03 */ PLAYER_SHIELD_MAX
} PlayerShield;

typedef enum {
    /* 0x00 */ PLAYER_FORM_FIERCE_DEITY,
    /* 0x01 */ PLAYER_FORM_GORON,
    /* 0x02 */ PLAYER_FORM_ZORA,
    /* 0x03 */ PLAYER_FORM_DEKU,
    /* 0x04 */ PLAYER_FORM_HUMAN,
    /* 0x05 */ PLAYER_FORM_MAX
} PlayerTransformation;

typedef enum {
    /* 0x00 */ PLAYER_MASK_NONE,
    /* 0x01 */ PLAYER_MASK_MASK_OF_TRUTH,
    /* 0x02 */ PLAYER_MASK_KAFEIS_MASK,
    /* 0x03 */ PLAYER_MASK_ALL_NIGHT_MASK,
    /* 0x04 */ PLAYER_MASK_BUNNY_HOOD,
    /* 0x05 */ PLAYER_MASK_KEATON_MASK,
    /* 0x06 */ PLAYER_MASK_GAROS_MASK,
    /* 0x07 */ PLAYER_MASK_ROMANIS_MASK,
    /* 0x08 */ PLAYER_MASK_CIRCUS_LEADERS_MASK,
    /* 0x09 */ PLAYER_MASK_POSTMANS_HAT,
    /* 0x0A */ PLAYER_MASK_COUPLES_MASK,
    /* 0x0B */ PLAYER_MASK_GREAT_FAIRYS_MASK,
    /* 0x0C */ PLAYER_MASK_GIBDO_MASK,
    /* 0x0D */ PLAYER_MASK_DON_GEROS_MASK,
    /* 0x0E */ PLAYER_MASK_KAMAROS_MASK,
    /* 0x0F */ PLAYER_MASK_CAPTAINS_HAT,
    /* 0x10 */ PLAYER_MASK_STONE_MASK,
    /* 0x11 */ PLAYER_MASK_BREMEN_MASK,
    /* 0x12 */ PLAYER_MASK_BLAST_MASK,
    /* 0x13 */ PLAYER_MASK_MASK_OF_SCENTS,
    /* 0x14 */ PLAYER_MASK_GIANTS_MASK,
    /* 0x15 */ PLAYER_MASK_FIERCE_DEITYS_MASK,
    /* 0x16 */ PLAYER_MASK_GORON_MASK,
    /* 0x17 */ PLAYER_MASK_ZORA_MASK,
    /* 0x18 */ PLAYER_MASK_DEKU_MASK,
    /* 0x19 */ PLAYER_MASK_MAX
} PlayerMask;

typedef void (*PlayerFuncD58)(struct GlobalContext*, struct Player*);

typedef struct Player {
    /* 0x000 */ Actor actor;
    /* 0x144 */ int8_t currentShield;
    /* 0x145 */ int8_t currentBoots;
    /* 0x146 */ int8_t heldItemButton;
    /* 0x147 */ int8_t itemActionParam;
    /* 0x148 */ uint8_t heldItemId;
    /* 0x149 */ int8_t prevBoots;
    /* 0x14A */ int8_t heldItemActionParam;
    /* 0x14B */ uint8_t transformation;
    /* 0x14C */ uint8_t modelGroup;
    /* 0x14D */ uint8_t nextModelGroup;
    /* 0x14E */ int8_t unk_14E;
    /* 0x14F */ uint8_t modelAnimType;
    /* 0x150 */ uint8_t leftHandType;
    /* 0x151 */ uint8_t rightHandType;
    /* 0x152 */ uint8_t sheathType;
    /* 0x153 */ uint8_t currentMask;
    /* 0x154 */ int8_t unk_154;
    /* 0x155 */ uint8_t prevMask;
    /* 0x158 */ struct Gfx** rightHandDLists;
    /* 0x15C */ struct Gfx** leftHandDLists;
    /* 0x160 */ struct Gfx** sheathDLists;
    /* 0x164 */ struct Gfx** waistDLists;
    /* 0x168 */ float unk_168;
    /* 0x16C */ float unk_16C;
    /* 0x170 */ float unk_170;
    /* 0x174 */ float unk_174;
    /* 0x178 */ float unk_178;
    /* 0x17C */ float unk_17C;
    /* 0x180 */ float unk_180;
    /* 0x184 */ float unk_184;
    /* 0x188 */ float unk_188;
    /* 0x18C */ float unk_18C;
    /* 0x190 */ float unk_190;
    /* 0x194 */ float unk_194;
    /* 0x198 */ float unk_198;
    /* 0x19C */ float unk_19C;
    /* 0x1A0 */ float unk_1A0;
    /* 0x1A4 */ float unk_1A4;
    /* 0x1A8 */ float unk_1A8;
    /* 0x1AC */ float unk_1AC;
    /* 0x1B0 */ float unk_1B0;
    /* 0x1B4 */ int16_t unk_1B4;
    /* 0x1B6 */ char unk_1B6[2];
    /* 0x1B8 */ uint8_t giObjectLoading;
    /* 0x1BC */ DmaRequest giObjectDmaRequest;
    /* 0x1DC */ OSMesgQueue giObjectLoadQueue;
    /* 0x1F4 */ OSMesg giObjectLoadMsg;
    /* 0x1F8 */ void* giObjectSegment;
    /* 0x1FC */ uint8_t maskObjectLoading;
    /* 0x1FD */ int8_t maskId;
    /* 0x200 */ DmaRequest maskDmaRequest;
    /* 0x220 */ OSMesgQueue maskObjectLoadQueue;
    /* 0x238 */ OSMesg maskObjectLoadMsg;
    /* 0x23C */ void* maskObjectSegment;
    /* 0x240 */ SkelAnime skelAnime;
    /* 0x284 */ SkelAnime unk_284;
    /* 0x2C8 */ SkelAnime unk_2C8;
    /* 0x30C */ Vec3s jointTable[5];
    /* 0x32A */ Vec3s morphTable[5];
    /* 0x348 */ int16_t eyeTexId;
    /* 0x34A */ int16_t eyeAnimTimer;
    /* 0x34C */ struct Actor* leftHandActor;
    /* 0x350 */ PosRot leftHandWorld;
    /* 0x364 */ struct Actor* rightHandActor;
    /* 0x368 */ PosRot rightHandWorld;
    /* 0x37C */ int8_t doorType;
    /* 0x37D */ int8_t doorDirection;
    /* 0x37E */ int8_t doorTimer;
    /* 0x37F */ int8_t doorNext; // used with spiral staircase
    /* 0x380 */ struct Actor* doorActor;
    /* 0x384 */ int16_t getItemId;
    /* 0x386 */ uint16_t getItemDirection;
    /* 0x388 */ struct Actor* interactRangeActor;
    /* 0x38C */ int16_t unk_38C;
    /* 0x390 */ struct Actor* rideActor;
    /* 0x394 */ uint8_t csMode;
    /* 0x395 */ uint8_t prevCsMode;
    /* 0x396 */ uint8_t unk_396;
    /* 0x397 */ uint8_t unk_397;
    /* 0x398 */ struct Actor* unk_398;
    /* 0x39C */ int16_t unk_39C;
    /* 0x39E */ int16_t unk_39E;
    /* 0x3A0 */ Vec3f unk_3A0;
    /* 0x3AC */ Vec3f unk_3AC;
    /* 0x3B8 */ uint16_t unk_3B8;
    /* 0x3BA */ int16_t unk_3BA;
    /* 0x3BC */ int16_t unk_3BC;
    /* 0x3BE */ char unk_3BE[2];
    /* 0x3C0 */ Vec3f unk_3C0;
    /* 0x3CC */ int16_t unk_3CC;
    /* 0x3CE */ int8_t unk_3CE;
    /* 0x3CF */ uint8_t unk_3CF;
    /* 0x3D0 */ char unk_3D0[0x148];
    /* 0x518 */ ColliderCylinder cylinder;
    /* 0x564 */ ColliderQuad swordQuads[2];
    /* 0x664 */ ColliderQuad shieldQuad;
    /* 0x6E4 */ ColliderCylinder shieldCylinder;
    /* 0x730 */ struct Actor* unk_730;
    /* 0x734 */ char unk_734[8];
    /* 0x73C */ int32_t blureEffectIndex[3];
    /* 0x748 */ char unk_748[0x320];
    /* 0xA68 */ struct PlayerAgeProperties* ageProperties; // repurposed as "transformation properties"?
    /* 0xA6C */ uint32_t stateFlags1;
    /* 0xA70 */ uint32_t stateFlags2;
    /* 0xA74 */ uint32_t stateFlags3;
    /* 0xA78 */ struct Actor* unk_A78;
    /* 0xA7C */ struct Actor* boomerangActor;
    union {
        /* 0xA80 */ struct Actor* naviActor;
        /* 0xA80 */ struct Actor* tatlActor;
        /* 0xA80 */ struct Actor* fairyActor;
    };
    union {
        /* 0xA84 */ int16_t naviTextId;
        /* 0xA84 */ int16_t tatlTextId;
        /* 0xA84 */ int16_t fairyTextId;
    };
    /* 0xA86 */ int8_t unk_A86;
    /* 0xA87 */ int8_t unk_A87;
    /* 0xA88 */ struct Actor* targetActor;
    /* 0xA8C */ float targetActorDistance;
    /* 0xA90 */ struct Actor* unk_A90;
    /* 0xA94 */ float unk_A94;
    /* 0xA98 */ struct Actor* unk_A98;
    /* 0xA9C */ float unk_A9C;
    /* 0xAA0 */ float unk_AA0;
    /* 0xAA4 */ int8_t unk_AA4;
    /* 0xAA5 */ uint8_t unk_AA5;
    /* 0xAA6 */ uint16_t unk_AA6;
    /* 0xAA8 */ int16_t unk_AA8;
    /* 0xAAA */ int16_t unk_AAA;
    /* 0xAAC */ Vec3s unk_AAC;
    /* 0xAB2 */ Vec3s unk_AB2;
    /* 0xAB8 */ float unk_AB8;
    /* 0xABC */ float unk_ABC;
    /* 0xAC0 */ float unk_AC0;
    /* 0xAC4 */ void* unk_AC4;
    /* 0xAC8 */ float unk_AC8;
    /* 0xACC */ int16_t unk_ACC;
    /* 0xACE */ int8_t unk_ACE;
    /* 0xACF */ uint8_t unk_ACF;
    /* 0xAD0 */ float linearVelocity;
    /* 0xAD4 */ int16_t currentYaw;
    /* 0xAD6 */ int16_t targetYaw;
    /* 0xAD8 */ uint16_t unk_AD8;
    /* 0xADA */ int8_t swordAnimation;
    /* 0xADB */ int8_t swordState;
    /* 0xADC */ int8_t unk_ADC;
    /* 0xADD */ int8_t unk_ADD;
    /* 0xADE */ uint8_t unk_ADE;
    /* 0xADF */ int8_t unk_ADF[4];
    /* 0xAE3 */ int8_t unk_AE3[4];
    /* 0xAE7 */ int8_t unk_AE7;  // a timer
    /* 0xAE8 */ int16_t unk_AE8; // multipurpose timer
    /* 0xAEC */ float unk_AEC;
    /* 0xAF0 */ Vec3f unk_AF0[2];
    /* 0xB08 */ float unk_B08[8];
    /* 0xB28 */ int16_t unk_B28;
    /* 0xB2A */ int8_t unk_B2A;
    /* 0xB2B */ int8_t unk_B2B;
    /* 0xB2C */ float windSpeed;
    /* 0xB30 */ int16_t windAngleX;
    /* 0xB32 */ int16_t windAngleY;
    /* 0xB34 */ float unk_B34;
    /* 0xB38 */ float unk_B38;
    /* 0xB3C */ float unk_B3C;
    /* 0xB40 */ float unk_B40;
    /* 0xB44 */ float unk_B44;
    /* 0xB48 */ float unk_B48;
    /* 0xB4C */ int16_t unk_B4C;
    /* 0xB4E */ int16_t unk_B4E;
    /* 0xB50 */ float unk_B50;
    /* 0xB54 */ float unk_B54;
    /* 0xB58 */ float unk_B58;
    /* 0xB5C */ uint8_t unk_B5C;
    /* 0xB5D */ uint8_t unk_B5D;
    /* 0xB5E */ uint8_t unk_B5E;
    /* 0xB5F */ uint8_t unk_B5F;
    /* 0xB60 */ uint16_t unk_B60; // blast mask timer?
    /* 0xB62 */ int16_t unk_B62;
    /* 0xB64 */ uint8_t unk_B64;
    /* 0xB65 */ uint8_t unk_B65;
    /* 0xB66 */ uint8_t unk_B66;
    /* 0xB67 */ uint8_t unk_B67; // deku hop timer?
    /* 0xB68 */ int16_t unk_B68;
    /* 0xB6A */ int16_t unk_B6A;
    /* 0xB6C */ int16_t unk_B6C;
    /* 0xB6E */ int16_t unk_B6E;
    /* 0xB70 */ int16_t unk_B70;
    /* 0xB72 */ uint16_t unk_B72; // floor type?
    /* 0xB74 */ uint8_t unk_B74;
    /* 0xB75 */ uint8_t unk_B75;
    /* 0xB76 */ int16_t unk_B76;
    /* 0xB78 */ float unk_B78;
    /* 0xB7C */ float unk_B7C;
    /* 0xB80 */ float unk_B80;
    /* 0xB84 */ int16_t unk_B84;
    /* 0xB86 */ int16_t unk_B86;
    /* 0xB88 */ int16_t unk_B88;
    /* 0xB8A */ int16_t unk_B8A;
    /* 0xB8C */ int16_t unk_B8C;
    /* 0xB8E */ int16_t unk_B8E;
    /* 0xB90 */ int16_t unk_B90;
    /* 0xB92 */ int16_t unk_B92;
    /* 0xB94 */ int16_t unk_B94;
    /* 0xB96 */ int16_t unk_B96;
    /* 0xB98 */ WeaponInfo swordInfo[3];
    /* 0xBEC */ Vec3f bodyPartsPos[18];
    /* 0xCC4 */ MtxF swordMtxF;
    /* 0xD04 */ MtxF shieldMf;
    /* 0xD44 */ uint8_t isBurning;
    /* 0xD45 */ uint8_t flameTimers[18]; // one flame per body part
    /* 0xD57 */ uint8_t unk_D57;
    /* 0xD58 */ PlayerFuncD58 unk_D58;
    /* 0xD5C */ int8_t invincibilityTimer; // prevents damage when nonzero (positive = visible, counts towards zero each frame)
    /* 0xD5D */ uint8_t unk_D5D;
    /* 0xD5E */ uint8_t unk_D5E;
    /* 0xD5F */ uint8_t unk_D5F;
    /* 0xD60 */ float unk_D60;
    /* 0xD64 */ int16_t unk_D64;
    /* 0xD66 */ uint16_t unk_D66;
    /* 0xD68 */ int16_t unk_D68;
    /* 0xD6A */ int8_t unk_D6A;
    /* 0xD6B */ uint8_t unk_D6B;
    /* 0xD6C */ Vec3f unk_D6C; // previous body part 0 position
} Player;                      /* sizeof = 0xD78 */
#endif                /* GAME_MM */


#endif
