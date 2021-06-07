#ifndef COMMAND_H
#define COMMAND_H

#include <inttypes.h>
#include <libzelda64/lib/types/Vec3f.h>
#include <libzelda64/lib/types/Vec3s.h>

enum {
    COMMANDTYPE_NONE,
    COMMANDTYPE_ACTORSPAWN,
    COMMANDTYPE_ACTORDESTROY,
    COMMANDTYPE_LOADOBJECT,
    COMMANDTYPE_RELOCATE,
    COMMANDTYPE_UPDATEBUTTON,
    COMMANDTYPE_PLAYSOUND,
    COMMANDTYPE_PLAYMUSIC,
    COMMANDTYPE_WARP,
    COMMANDTYPE_MOVEPLAYERTOADDRESS,
    COMMANDTYPE_SFX
};

typedef struct {
    /* 0x00 */ int16_t actorId;
    /* 0x02 */ int16_t params;
    /* 0x04 */ Vec3s rot;
    /* 0x0A */ int16_t pad;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ struct Actor* address; // 0 to spawn on game heap, otherwise actor will spawn at this address
} CommandParams_ActorSpawn; /* sizeof = 0x1C */

typedef struct {

} CommandParams_LoadObject;

typedef struct {
    /* 0x00 */ void* allocatedVRamAddress;
    /* 0x04 */ struct OverlayRelocationSection* overlayInfo;
    /* 0x08 */ void* vRamAddress;
} CommandParams_Relocate; /* sizeof = 0x08 */

typedef struct {
    /* 0x00 */ uint16_t button;
} CommandParams_UpdateButton; /* sizeof = 0x02 */

typedef struct {
    uint16_t sfxId;
    Vec3f a1;
    uint8_t a2;
    float a3;
    float a4;
    float a5;
} CommandParams_PlaySound;

typedef struct {

} CommandParams_PlayMusic;

typedef struct {

} CommandParams_Warp;

typedef struct {
    struct Player* address;
} CommandParams_MovePlayerTooAddress;

typedef union {
    CommandParams_ActorSpawn actorSpawn;
    CommandParams_LoadObject loadObject;
    CommandParams_Relocate relocate;
    CommandParams_UpdateButton updateButton;
    CommandParams_PlaySound playSound;
    CommandParams_PlayMusic playMusic;
    CommandParams_Warp warp;
    CommandParams_MovePlayerTooAddress movePlayerToAddr;
} CommandParams; /* sizeof = 0x1C */

typedef struct {
    /* 0x00 */ uint32_t type;
    /* 0x04 */ uint32_t uuid;
    /* 0x08 */ CommandParams params;
} Command; /* sizeof = 0x24 */

#endif

