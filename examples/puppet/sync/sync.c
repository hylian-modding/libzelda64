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
    SYNC_RAW("animp", OFFSETOF(Player, skelAnime.animation), OFFSETOF(entity_t, skelAnime0.syncAnimation), sizeof(void*)),
    SYNC_RAW("syncFrame", OFFSETOF(Player, skelAnime.curFrame), OFFSETOF(entity_t, skelAnime0.syncFrame), sizeof(float)),
    SYNC_RAW("syncSpeed", OFFSETOF(Player, skelAnime.playSpeed), OFFSETOF(entity_t, skelAnime0.syncSpeed), sizeof(float)),
    SYNC_RAW("latencyFrames", 0xDEADBEEF, OFFSETOF(entity_t, skelAnime0.latencyFrames), sizeof(float)),
    SYNC_RAW("syncMode", OFFSETOF(Player, skelAnime.mode), OFFSETOF(entity_t, skelAnime0.syncMode), sizeof(uint8_t)),
    SYNC_END
};

#include "../puppet.c"