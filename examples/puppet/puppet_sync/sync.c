#include "../puppet.h"

/*#if OOT_DEBUG
    #define LINK 0x802245B0
#elif OOT_U_1_0
    #define LINK 0x801DAA30
#endif*/

#define LINK 0x801DAA30
#define SAVE_CONTEXT 0x8011A5D0
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

volatile ooto_sync_object_t sync_entries[] = {
    SYNC_START,
    SYNC("pos", Player, En_Puppet, actor.world),
    SYNC("rot", Player, En_Puppet, actor.shape.rot),
    SYNC("fpos", Player, En_Puppet, actor.focus),
    SYNC("xz_speed", Player, En_Puppet, actor.speedXZ),
    SYNC_RAW("sword_info", OFFSETOF(Player, swordInfo[0]), OFFSETOF(En_Puppet, puppet.blureSwordInfo), sizeof(WeaponInfo)),
    SYNC_RAW("boots", OFFSETOF(Player, currentBoots), OFFSETOF(En_Puppet, puppet.currentBoots), sizeof(uint8_t)),
    SYNC_RAW("shield", OFFSETOF(Player, currentShield), OFFSETOF(En_Puppet, puppet.currentShield), sizeof(uint8_t)),
    SYNC_RAW("sword", OFFSETOF(Player, currentSword), OFFSETOF(En_Puppet, puppet.currentSword), sizeof(uint8_t)),
    SYNC_RAW("mask", OFFSETOF(Player, currentMask), OFFSETOF(En_Puppet, puppet.currentMask), sizeof(uint8_t)),
    SYNC_RAW("action_a", OFFSETOF(Player, heldItemActionParam), OFFSETOF(En_Puppet, puppet.actionParams[0]), sizeof(uint8_t)),
    SYNC_RAW("action_b", OFFSETOF(Player, itemActionParam), OFFSETOF(En_Puppet, puppet.actionParams[1]), sizeof(uint8_t)),
    SYNC_RAW("state1", OFFSETOF(Player, stateFlags1), OFFSETOF(En_Puppet, puppet.stateFlags[0]), sizeof(uint32_t)),
    SYNC_RAW("state2", OFFSETOF(Player, stateFlags2), OFFSETOF(En_Puppet, puppet.stateFlags[1]), sizeof(uint32_t)),
    SYNC_RAW("state3", OFFSETOF(Player, stateFlags3), OFFSETOF(En_Puppet, puppet.stateFlags[2]), sizeof(uint32_t)),
    SYNC_RAW_NO_LINK("deku_stick_length", (LINK + 0x84c), OFFSETOF(En_Puppet, puppet.dekuStickLength), sizeof(float)),
    SYNC_RAW("body_angle", OFFSETOF(Player, bodyAngle), OFFSETOF(En_Puppet, puppet.bodyAngle), sizeof(Vec3s)),
    SYNC_RAW_NO_LINK("anim", 0x80600000, OFFSETOF(En_Puppet, puppet.anim), 0x86),
    SYNC_RAW_NO_LINK("str", 0x806FFF00, OFFSETOF(En_Puppet, puppet.strength), sizeof(uint8_t)),
    SYNC_RAW_NO_LINK("ears", 0x803AF180, OFFSETOF(En_Puppet, puppet.bunnyHoodRot), (sizeof(Vec3s) * 2)),
    SYNC_RAW_NO_LINK("age", 0x8011A5D4, OFFSETOF(En_Puppet, puppet.age), sizeof(uint32_t)),
    SYNC_RAW_NO_LINK("tunic", 0xDEADBEEF, OFFSETOF(En_Puppet, puppet.colorTunic), 0x3),
    SYNC_RAW_NO_LINK("strength", 0xDEADBEEF, OFFSETOF(En_Puppet, puppet.strength), sizeof(uint8_t)),
    SYNC_RAW_NO_LINK("gauntlet", 0xDEADBEEF, OFFSETOF(En_Puppet, puppet.colorGauntlet), 0x3),
    SYNC_RAW_NO_LINK("ocarina", 0x8011A64B, OFFSETOF(En_Puppet, puppet.currentOcarina), sizeof(uint8_t)),
    SYNC_END
};

#include "../puppet.c"