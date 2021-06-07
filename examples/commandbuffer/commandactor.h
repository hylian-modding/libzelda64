#ifndef COMMANDACTOR_H
#define COMMANDACTOR_H

#include <inttypes.h>

/*
    Uses hooks to keep track of events that have happened, relevant to actors
*/

enum {
    COMMANDACTORTYPE_NONE,
    COMMANDACTORTYPE_INIT,
    COMMANDACTORTYPE_SPAWN,
    COMMANDACTORTYPE_SPAWNENTRY,
    COMMANDACTORTYPE_SPAWNTRANSITION,
    COMMANDACTORTYPE_DESTROY,
    COMMANDACTORTYPE_UPDATE
};

typedef struct {
    /* 0x00 */ uint32_t type;
    /* 0x04 */ struct Actor* actor;
} CommandActor; /* sizeof = 0x08 */

#endif

