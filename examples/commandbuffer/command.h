#ifndef COMMAND_H
#define COMMAND_H

#include <libzelda64.h>
#include "../puppet/pvp.h"

enum {
    COMMANDTYPE_NONE,
    COMMANDTYPE_ACTORSPAWN,
    COMMANDTYPE_ACTORADDREMCAT,
    COMMANDTYPE_RELOCATE,
    COMMANDTYPE_UPDATEBUTTON,
    COMMANDTYPE_PLAYSOUND,
    COMMANDTYPE_PLAYMUSIC,
    COMMANDTYPE_WARP,
    COMMANDTYPE_MOVEPLAYERTOADDRESS,
    COMMANDTYPE_ARBITRARYFUNCTIONCALL,
    COMMANDTYPE_SFX,
    COMMANDTYPE_PVPDAMAGE,
    COMMANDTYPE_MALLOCFREE,
    COMMANDTYPE_OBJECTLOAD
};

enum {
    ACTORADDREMCAT_REMOVE,
    ACTORADDREMCAT_ADD,
    ACTORADDREMCAT_DELETE
};

enum {
    ACTORSPAWNTYPE_DEFAULT,
    ACTORSPAWNTYPE_WITHPARENTANDCUTSCENE
};

typedef struct {
    /* 0x00 */ int16_t actorId;
    /* 0x02 */ int16_t params;
    /* 0x04 */ Vec3s rot;
    /* 0x0A */ int16_t type;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ struct Actor* address; // 0 to spawn on game heap, otherwise actor will spawn at this address, if mm and type is nonzero, this is the parent
    /* 0x20 */ uint16_t cutscene;
    /* 0x22 */ uint16_t param_12;
} CommandParams_ActorSpawn; /* sizeof = 0x24 */

typedef struct {
    struct Actor* address;
    uint16_t type;
    uint16_t category;
} CommandParams_ActorAddRemCat; /* sizeof = 0x08 */

typedef struct {
    /* 0x00 */ void* allocatedVRamAddress;
    /* 0x04 */ struct OverlayRelocationSection* overlayInfo;
    /* 0x08 */ void* vRamAddress;
} CommandParams_Relocate; /* sizeof = 0x08 */

typedef struct {
    /* 0x00 */ uint16_t button;
} CommandParams_UpdateButton; /* sizeof = 0x02 */

typedef struct {
    /* 0x00 */ uint16_t sfxId;
    /* 0x02 */ uint16_t pad;
    /* 0x04 */ Vec3f a1;
    /* 0x10 */ uint8_t a2;
    /* 0x14 */ float a3;
    /* 0x18 */ float a4;
    /* 0x1C */ float a5;
} CommandParams_PlaySound; /* sizeof = 0x20 */

typedef struct {
    /* 0x00 */ int32_t entranceIndex;
    /* 0x04 */ int32_t cutsceneIndex;
    /* 0x08 */ int32_t age;
} CommandParams_Warp; /* sizeof = 0x0C */

typedef struct {
    /* 0x00 */ struct Player* address;
} CommandParams_MovePlayerTooAddress; /* sizeof = 0x04 */

typedef uint64_t(*ArbitraryFunction)();

typedef struct {
    /* 0x00 */ ArbitraryFunction fn;
    /* 0x04 */ uint64_t* args;
    /* 0x08 */ uint32_t argc;
} CommandParams_ArbitraryFunctionCall; /* sizeof = 0x0C */

typedef struct {
    /* 0x00 */ PvpContext ctx;
    /* 0x0C */ struct Actor* source;
} CommandParams_PvpDamage; /* sizeof = 0x10 */

typedef struct {
    /* 0x00 */ uint32_t malloc;
    /* 0x04 */ uint32_t data;
} CommandParams_MallocFree; /* sizeof = 0x08 */

typedef struct {
    /* 0x02 */ int16_t objectId;
} CommandParams_ObjectLoad; /* sizeof = 0x02 */

typedef union {
    CommandParams_ActorSpawn actorSpawn;
    CommandParams_ActorAddRemCat actorCat;
    CommandParams_Relocate relocate;
    CommandParams_UpdateButton updateButton;
    CommandParams_PlaySound playSound;
    CommandParams_Warp warp;
    CommandParams_MovePlayerTooAddress movePlayerToAddr;
    CommandParams_ArbitraryFunctionCall arbFn;
    CommandParams_PvpDamage pvp;
    CommandParams_MallocFree mallocFree;
    CommandParams_ObjectLoad objLoad;
} CommandParams; /* sizeof = 0x20 */

typedef struct {
    /* 0x00 */ uint32_t type;
    /* 0x04 */ uint32_t uuid;
    /* 0x08 */ CommandParams params;
} Command; /* sizeof = 0x28 */

#endif

