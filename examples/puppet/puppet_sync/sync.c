#include "../puppet.h"

/*#if OOT_DEBUG
    #define LINK 0x802245B0
#elif OOT_U_1_0
    #define LINK 0x801DAA30
#endif*/

#define LINK 0x801DAA30
#define OFFSETOF(TYPE, ELEMENT) ((uint32_t)&(((TYPE *)0)->ELEMENT))
#define SYNC_START (ooto_sync_object_t){"sync_start", 0x0, 0x0}
#define SYNC_END (ooto_sync_object_t){"sync_end", 0x0, 0x0}
#define SYNC(NAME, SRC, DEST, MEMBER) (ooto_sync_object_t){  \
    (char*)(NAME),                                           \
    LINK + ((uint32_t)&(((SRC*)0)->MEMBER)),                 \
    ((uint32_t)&(((DEST*)0)->MEMBER)),                       \
    sizeof(typeof((((DEST*)0)->MEMBER)))                     \
}
#define SYNC_RAW(NAME, SRC, DEST, SIZE) (ooto_sync_object_t){   \
    (char*)(NAME),                                              \
    LINK + ((uint32_t)SRC),                                     \
    ((uint32_t)DEST),                                           \
    ((uint32_t)SIZE)                                            \
}
#define SYNC_RAW_NO_LINK(NAME, SRC, DEST, SIZE) (ooto_sync_object_t){   \
    (char*)(NAME),                                              \
    ((uint32_t)SRC),                                     \
    ((uint32_t)DEST),                                           \
    ((uint32_t)SIZE)                                            \
}

typedef struct sync_obj_s {
    char* property_name;
    uint32_t read_offset;
    uint32_t write_offset;
    uint32_t buffer_size;
} ooto_sync_object_t;

volatile ooto_sync_object_t sync_entries[] = {
    SYNC_START,
    SYNC("pos", Player, entity_t, actor.world),
    SYNC("rot", Player, entity_t, actor.shape.rot),
    SYNC("fpos", Player, entity_t, actor.focus),
    SYNC("xz_speed", Player, entity_t, actor.speedXZ),
    SYNC_RAW("boots", OFFSETOF(Player, currentBoots), OFFSETOF(entity_t, puppet.currentBoots), sizeof(uint8_t)),
    SYNC_RAW("shield", OFFSETOF(Player, currentShield), OFFSETOF(entity_t, puppet.currentShield), sizeof(uint8_t)),
    SYNC_RAW("sword", OFFSETOF(Player, currentSword), OFFSETOF(entity_t, puppet.currentSword), sizeof(uint8_t)),
    SYNC_RAW("mask", OFFSETOF(Player, currentMask), OFFSETOF(entity_t, puppet.currentMask), sizeof(uint8_t)),
    SYNC_RAW_NO_LINK("anim", 0x80600000, OFFSETOF(entity_t, puppet.anim), 0x86),
    SYNC_RAW("action_a", OFFSETOF(Player, heldItemActionParam), OFFSETOF(entity_t, puppet.action), sizeof(uint8_t)),
    SYNC_RAW("action_b", OFFSETOF(Player, itemActionParam), OFFSETOF(entity_t, puppet.action2), sizeof(uint8_t)),
    SYNC_RAW("state1", OFFSETOF(Player, stateFlags1), OFFSETOF(entity_t, puppet.stateFlags1), sizeof(uint32_t)),
    SYNC_RAW("state2", OFFSETOF(Player, stateFlags2), OFFSETOF(entity_t, puppet.stateFlags2), sizeof(uint32_t)),
    SYNC_RAW("state3", OFFSETOF(Player, stateFlags3), OFFSETOF(entity_t, puppet.stateFlags3), sizeof(uint32_t)),
    SYNC_RAW_NO_LINK("str", 0x806FFF00, OFFSETOF(entity_t, puppet.strength), sizeof(uint8_t)),
    SYNC_RAW_NO_LINK("ears", 0x803AF180, OFFSETOF(entity_t, puppet.bunny_hood), (sizeof(vec3s_t) * 2)),
    SYNC_END
};

#include "../puppet.c"