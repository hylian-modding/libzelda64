#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

#include "Actor.h"
#include "DmaRequest.h"
#include "SkelAnime.h"
#include "ColliderCylinder.h"
#include "ColliderQuad.h"
#include "WeaponInfo.h"
#include "MtxF.h"
#include <libultra/PR/os.h>
#include <inttypes.h>

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

typedef enum {
    /* 0x00 */ PLAYER_LIMB_NONE,
    /* 0x01 */ PLAYER_LIMB_ROOT,
    /* 0x02 */ PLAYER_LIMB_WAIST,
    /* 0x03 */ PLAYER_LIMB_LOWER,
    /* 0x04 */ PLAYER_LIMB_R_THIGH,
    /* 0x05 */ PLAYER_LIMB_R_SHIN,
    /* 0x06 */ PLAYER_LIMB_R_FOOT,
    /* 0x07 */ PLAYER_LIMB_L_THIGH,
    /* 0x08 */ PLAYER_LIMB_L_SHIN,
    /* 0x09 */ PLAYER_LIMB_L_FOOT,
    /* 0x0A */ PLAYER_LIMB_UPPER,
    /* 0x0B */ PLAYER_LIMB_HEAD,
    /* 0x0C */ PLAYER_LIMB_HAT,
    /* 0x0D */ PLAYER_LIMB_COLLAR,
    /* 0x0E */ PLAYER_LIMB_L_SHOULDER,
    /* 0x0F */ PLAYER_LIMB_L_FOREARM,
    /* 0x10 */ PLAYER_LIMB_L_HAND,
    /* 0x11 */ PLAYER_LIMB_R_SHOULDER,
    /* 0x12 */ PLAYER_LIMB_R_FOREARM,
    /* 0x13 */ PLAYER_LIMB_R_HAND,
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

#define PLAYER_LIMB_BUF_COUNT PLAYER_LIMB_MAX + 2 // 2 extra entries in limb buffers?

#define AGE_IS_ADULT(age) (age == 0)

typedef void (*PlayerFunc674)(struct Player*, struct GlobalContext*);
typedef int32_t (*PlayerFunc82C)(struct Player*, struct GlobalContext*);
typedef void (*PlayerFuncA74)(struct GlobalContext*, struct Player*);

typedef struct Player {
    /* 0x0000 */ Actor actor;
    /* 0x013C */ int8_t currentTunic; // current tunic from `PlayerTunic`
    /* 0x013D */ int8_t currentSword; // current sword Item ID
    /* 0x013E */ int8_t currentShield; // current shield from `PlayerShield`
    /* 0x013F */ int8_t currentBoots; // current boots from `PlayerBoots`
    /* 0x0140 */ int8_t heldItemButton; // Button index for the item currently used
    /* 0x0141 */ int8_t heldItemActionParam; // Action param for the item currently used
    /* 0x0142 */ uint8_t heldItemId; // Item id for the item currently used
    /* 0x0143 */ int8_t prevBoots; // previous boots from `PlayerBoots`
    /* 0x0144 */ int8_t itemActionParam; // the difference between this and heldItemActionParam is unclear
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
    /* 0x067C */ struct Actor* naviActor;
    /* 0x0680 */ int16_t naviTextId;
    /* 0x0682 */ uint8_t stateFlags3;
    /* 0x0683 */ int8_t exchangeItemId;
    /* 0x0684 */ struct Actor* targetActor;
    /* 0x0688 */ float targetActorDistance;
    /* 0x068C */ int8_t unk_68C[0x004];
    /* 0x0690 */ float unk_690;
    /* 0x0694 */ float unk_694;
    /* 0x0698 */ struct Actor* unk_698;
    /* 0x069C */ int8_t unk_69C;
    /* 0x069D */ uint8_t  unk_69D;
    /* 0x069E */ uint16_t unk_69E;
    /* 0x06A0 */ int16_t unk_6A0;
    /* 0x06A2 */ int8_t unk_6A4[0x004];
    /* 0x06A6 */ int16_t unk_6A6;
    /* 0x06A8 */ int16_t unk_6A8;
    /* 0x06AA */ int16_t unk_6AA;
    /* 0x06AC */ int16_t unk_6AC;
    /* 0x06AE */ int16_t unk_6AE;
    /* 0x06B0 */ int16_t unk_6B0;
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
    /* 0x084C */ float unk_84C; // stick length among other things
    /* 0x0850 */ int16_t unk_850; // stick flame timer among other things
    /* 0x0852 */ int8_t unk_852; // get item draw ID + 1
    /* 0x0854 */ float unk_854;
    /* 0x0858 */ float unk_858;
    /* 0x085C */ float unk_85C;
    /* 0x0860 */ float unk_860;
    /* 0x0864 */ float unk_864;
    /* 0x0868 */ float unk_868;
    /* 0x086C */ int16_t unk_86C;
    /* 0x086E */ int16_t unk_86E;
    /* 0x0870 */ float unk_870;
    /* 0x0874 */ float wallHeight; // height used to determine whether link can climb or grab a ledge at the top
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
    /* 0x0886 */ int16_t fallDistance; // truncated Y distance the player has fallen so far (positive is down)
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
    /* 0x09D0 */ MtxF mf_9E0;
    /* 0x0A10 */ MtxF shieldMf;
    /* 0x0A50 */ uint8_t isBurning;
    /* 0x0A51 */ uint8_t flameTimers[18]; // one flame per body part
    /* 0x0A63 */ uint8_t unk_A63;
    /* 0x0A64 */ PlayerFuncA74 func_A74;
    /* 0x0A68 */ int8_t invincibilityTimer; // prevents damage when nonzero (positive = visible, counts towards zero each frame)
    /* 0x0A69 */ uint8_t unk_A69;
    /* 0x0A6A */ uint8_t unk_A6A;
    /* 0x0A6B */ uint8_t unk_A6B;
    /* 0x0A6C */ float unk_A6C;
    /* 0x0A70 */ int16_t unk_A70;
    /* 0x0A72 */ uint16_t unk_A72;
    /* 0x0A74 */ int16_t unk_A74;
    /* 0x0A76 */ int8_t unk_A76;
    /* 0x0A77 */ uint8_t unk_A77;
    /* 0x0A78 */ Vec3f unk_A78; // previous body part 0 position
} Player; /* sizeof = 0xA84 */

#endif

