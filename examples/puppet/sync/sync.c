#include "../puppet.h"

/*#if OOT_DEBUG
    #define LINK 0x802245B0
#elif OOT_U_1_0
    #define LINK 0x801DAA30
#endif*/

#define LINK 0x801DAA30

#define SYNC_START (ooto_sync_object_t){"sync_start", 0x0, 0x0}
#define SYNC_END (ooto_sync_object_t){"sync_end", 0x0, 0x0}
#define SYNC(NAME, SRC, DEST, MEMBER) (ooto_sync_object_t){  \
    (char*)(NAME),                                           \
    LINK + ((uint32_t)&(((SRC*)0)->MEMBER)),                 \
    ((uint32_t)&(((DEST*)0)->MEMBER)),                       \
    sizeof(typeof((((DEST*)0)->MEMBER)))                     \
}

typedef struct sync_obj_s {
    char* property_name;
    uint32_t read_offset;
    uint32_t write_offset;
    uint32_t buffer_size;
} ooto_sync_object_t;

volatile ooto_sync_object_t sync_entries[] = {
    SYNC_START,
    SYNC("world_pos", Player, entity_t, actor.world),
    SYNC("focus_pos", Player, entity_t, actor.focus),
    SYNC_END
};

#include "../puppet.c"