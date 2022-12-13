#ifndef ACTORFUNC_TYPE_H
#define ACTORFUNC_TYPE_H

typedef void (*ActorFunc)(struct Actor* actor, struct GlobalContext* globalCtx);
typedef void (*ActorFunc2)(struct GlobalContext* globalCtx, struct Actor* actor);
typedef void (*ActorShadowFunc)(struct Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);

#endif
