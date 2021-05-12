#ifndef __OVL_EN_STREAMREADER__
#define __OVL_EN_STREAMREADER__

#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/ActorShape.h>
#include <libzelda64/lib/types/GlobalContext.h>

extern int32_t sprintf(char* dst, const char* fmt, ...);
asm("sprintf = 0x800CE7B4");

#define __DEBUG_STEAM_FLAG__  0x21485346
#define __DEBUG_HEAP_STREAM__ 0x21485350

typedef struct {
    Actor actor;
    struct stream {
        uint32_t state;
        uint32_t buffer;
    } stream;
} en_streamreader_t;

static void init(en_streamreader_t* this, GlobalContext* globalCtx);
static void destroy(en_streamreader_t* this, GlobalContext* globalCtx);
static void update(en_streamreader_t* this, GlobalContext* globalCtx);
static void draw(en_streamreader_t* this, GlobalContext* globalCtx);

ActorInit initVars = {
    .id = 5
    , .category = ACTORLIST_CATEGORY_NPC
    , .flags = (ACTORFLAG_ALWAYS_DRAW | ACTORFLAG_ALWAYS_UPDATE)
    , .objectId = 1
    , .instanceSize = sizeof(en_streamreader_t)
    , .init = init
    , .destroy = destroy
    , .update = update
    , .draw = draw
};

#endif /* __OVL_EN_STREAMREADER__ */