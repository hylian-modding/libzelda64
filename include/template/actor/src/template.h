#ifndef __OVL_EN_TEMPLATE__
#define __OVL_EN_TEMPLATE__

#include <libzelda64/Actor.h>
#include <libzelda64/ActorShape.h>
#include <libzelda64/types/GlobalContext.h>

typedef struct {
    Actor actor;
} en_template_t;

static void init(en_template_t* this, GlobalContext* globalCtx);
static void destroy(en_template_t* this, GlobalContext* globalCtx);
static void update(en_template_t* this, GlobalContext* globalCtx);
static void draw(en_template_t* this, GlobalContext* globalCtx);

ActorInit initVars = {
    .id = 5
    , .category = ACTORLIST_CATEGORY_NPC
    , .flags = (ACTORFLAG_ALWAYS_DRAW | ACTORFLAG_ALWAYS_UPDATE)
    , .objectId = 1
    , .instanceSize = sizeof(en_template_t)
    , .init = init
    , .destroy = destroy
    , .update = update
    , .draw = draw
};

#endif /* __OVL_EN_TEMPLATE__ */