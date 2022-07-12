#ifndef COMMANDEVENT_H
#define COMMANDEVENT_H

#include <inttypes.h>

/*
    Uses hooks to keep track of events that have happened, relevant to actors
*/

enum {
    COMMANDEVENTTYPE_NONE,
    COMMANDEVENTTYPE_INIT,
    COMMANDEVENTTYPE_SPAWN,
    COMMANDEVENTTYPE_SPAWNENTRY,
    COMMANDEVENTTYPE_SPAWNTRANSITION,
    COMMANDEVENTTYPE_DESTROY,
    COMMANDEVENTTYPE_UPDATE,
    COMMANDEVENTTYPE_OBJECTSPAWN,
    COMMANDEVENTTYPE_ERROR_FILLED
};

typedef struct {
    /* 0x00 */ uint16_t objectId;
    /* 0x02 */ uint16_t objectCtxId;
} CommandEvent_Params_ObjectSpawn; /* sizeof = 0x04 */

typedef union {
    struct Actor* actor;
    CommandEvent_Params_ObjectSpawn objSpawn;
} CommandEvent_Params; /* sizeof = 0x04 */

typedef struct {
    /* 0x00 */ uint32_t type;
    /* 0x04 */ CommandEvent_Params params;
} CommandEvent; /* sizeof = 0x08 */

#endif

