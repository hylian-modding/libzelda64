#include "../puppet.h"
#include "../puppet.c"
#include <libzelda64/lib/types/Player.h>

#define LINK 0x80800000 // Change this to be the start offset in RAM of Link's instance, or whever the start of `player_t` is.

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

Player* player = (Player*) LINK;

volatile ooto_sync_object_t sync[] = {
    SYNC_START,
    SYNC("world", Player, en_puppet_t, actor.world),
    SYNC("anim", Player, en_puppet_t, actor.world),
    SYNC('backDlist', Player, puppet_info_t, ),
    SYNC_END
};