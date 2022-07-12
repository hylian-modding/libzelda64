#include "Puppet.h"

/*#if OOT_DEBUG
    #define LINK 0x802245B0
#elif OOT_U_1_0
    #define LINK 0x801DAA30
#endif*/

#ifdef GAME_OOT
#define LINK 0x801DAA30
#define SAVE_CONTEXT 0x8011A5D0
#elif defined GAME_MM
#define LINK 0x803FFDB0
#define SAVE_CONTEXT 0x801EF670
#endif
#define OFFSETOF(TYPE, ELEMENT) ((uint32_t)&(((TYPE *)0)->ELEMENT))
#define SYNC_START (ooto_sync_object_t){"sync_start", 0x0, 0x0}
#define SYNC_END (ooto_sync_object_t){"sync_end", 0x0, 0x0}

// Used to sync members that share the same structure hierarchy.
#define SYNC(NAME, SRC, DEST, MEMBER) (ooto_sync_object_t){  \
    (char*)(NAME),                                           \
    LINK + ((uint32_t)&(((SRC*)0)->MEMBER)),                 \
    ((uint32_t)&(((DEST*)0)->MEMBER)),                       \
    sizeof(typeof((((DEST*)0)->MEMBER)))                     \
}

// Used to sunc members that have a different structure hierarchy.
#define SYNC_RAW(NAME, SRC, DEST, SIZE) (ooto_sync_object_t){   \
    (char*)(NAME),                                              \
    LINK + ((uint32_t)SRC),                                     \
    ((uint32_t)DEST),                                           \
    ((uint32_t)SIZE)                                            \
}

// Used to sync members that are not in a structure (i.e absolute RAM addresses.)
#define SYNC_RAW_NO_LINK(NAME, SRC, DEST, SIZE) (ooto_sync_object_t){   \
    (char*)(NAME),                                                      \
    ((uint32_t)SRC),                                                    \
    ((uint32_t)DEST),                                                   \
    ((uint32_t)SIZE)                                                    \
}

typedef struct sync_obj_s {
    char* property_name;
    uint32_t read_offset;
    uint32_t write_offset;
    uint32_t buffer_size;
} ooto_sync_object_t;

#ifdef GAME_OOT
volatile ooto_sync_object_t sync_entries[] = {
    SYNC_START,
    SYNC("pos", Player, Puppet, actor.world),
    SYNC("rot", Player, Puppet, actor.shape.rot),
    SYNC("fpos", Player, Puppet, actor.focus),
    SYNC("xz_speed", Player, Puppet, actor.speedXZ),
    SYNC_RAW("sword_info", OFFSETOF(Player, swordInfo[0]), OFFSETOF(Puppet, syncInfo.blureSwordInfo), sizeof(WeaponInfo)),
    SYNC_RAW("boots", OFFSETOF(Player, currentBoots), OFFSETOF(Puppet, syncInfo.currentBoots), sizeof(uint8_t)),
    SYNC_RAW("shield", OFFSETOF(Player, currentShield), OFFSETOF(Puppet, syncInfo.currentShield), sizeof(uint8_t)),
    SYNC_RAW("sword", OFFSETOF(Player, currentSword), OFFSETOF(Puppet, syncInfo.currentSword), sizeof(uint8_t)),
    SYNC_RAW("mask", OFFSETOF(Player, currentMask), OFFSETOF(Puppet, syncInfo.currentMask), sizeof(uint8_t)),
    SYNC_RAW("action_a", OFFSETOF(Player, heldItemActionParam), OFFSETOF(Puppet, syncInfo.actionParams[0]), sizeof(uint8_t)),
    SYNC_RAW("action_b", OFFSETOF(Player, itemActionParam), OFFSETOF(Puppet, syncInfo.actionParams[1]), sizeof(uint8_t)),
    SYNC_RAW("state1", OFFSETOF(Player, stateFlags1), OFFSETOF(Puppet, syncInfo.stateFlags[0]), sizeof(uint32_t)),
    SYNC_RAW("state2", OFFSETOF(Player, stateFlags2), OFFSETOF(Puppet, syncInfo.stateFlags[1]), sizeof(uint32_t)),
    SYNC_RAW("state3", OFFSETOF(Player, stateFlags3), OFFSETOF(Puppet, syncInfo.stateFlags[2]), sizeof(uint32_t)),
    SYNC_RAW_NO_LINK("deku_stick_length", (LINK + 0x84c), OFFSETOF(Puppet, syncInfo.dekuStickLength), sizeof(float)),
    SYNC_RAW("body_angle", OFFSETOF(Player, bodyAngle), OFFSETOF(Puppet, syncInfo.bodyAngle), sizeof(Vec3s)),
    SYNC_RAW_NO_LINK("anim", (LINK + 0x01F0), OFFSETOF(Puppet, animeTable), 0x86),
    SYNC_RAW_NO_LINK("str", 0x806FFF00, OFFSETOF(Puppet, syncInfo.strength), sizeof(uint8_t)),
    SYNC_RAW_NO_LINK("ears", 0x803AF180, OFFSETOF(Puppet, syncInfo.bunnyHoodRot), (sizeof(Vec3s) * 2)),
    SYNC_RAW_NO_LINK("age", 0x8011A5D4, OFFSETOF(Puppet, syncInfo.ageOrForm.age), sizeof(uint32_t)),
    SYNC_RAW_NO_LINK("tunic", 0xDEADBEEF, OFFSETOF(Puppet, syncInfo.colorTunic), 0x3),
    SYNC_RAW_NO_LINK("strength", 0xDEADBEEF, OFFSETOF(Puppet, syncInfo.strength), sizeof(uint8_t)),
    SYNC_RAW_NO_LINK("gauntlet", 0xDEADBEEF, OFFSETOF(Puppet, syncInfo.colorGauntlet), 0x3),
    SYNC_RAW_NO_LINK("ocarina", 0x8011A64B, OFFSETOF(Puppet, syncInfo.currentOcarina), sizeof(uint8_t)),
    SYNC_END
};
#elif defined GAME_MM
volatile ooto_sync_object_t sync_entries[] = {
    SYNC_START,
    SYNC("pos", Player, Puppet, actor.world),
    SYNC("rot", Player, Puppet, actor.shape.rot),
    SYNC("fpos", Player, Puppet, actor.focus),
    SYNC_RAW("state1", OFFSETOF(Player, stateFlags1), OFFSETOF(Puppet, syncInfo.stateFlags[0]), sizeof(uint32_t)),
    SYNC_RAW("state2", OFFSETOF(Player, stateFlags2), OFFSETOF(Puppet, syncInfo.stateFlags[1]), sizeof(uint32_t)),
    SYNC_RAW("state3", OFFSETOF(Player, stateFlags3), OFFSETOF(Puppet, syncInfo.stateFlags[2]), sizeof(uint32_t)),
    SYNC_RAW_NO_LINK("anim", (0x80400500), OFFSETOF(Puppet, animeTable), 0x86),
    SYNC_RAW_NO_LINK("form", SAVE_CONTEXT + 0x20, OFFSETOF(Puppet, syncInfo.ageOrForm.form), sizeof(uint8_t)),
    SYNC_END
};
#endif

#include "DefaultCollider.c"
#include "LimbDraw.c"
#include "SkelAnimeCustom.c"
#include "TPose.c"
#include "Puppet.c"