#ifndef GLOBALCONTEXT_TYPE_H
#define GLOBALCONTEXT_TYPE_H

#include "../zelda64_version.h"
#include "ActorContext.h"
#include "ActorFunc.h"
#include "AnimationContext.h"
#include "Camera.h"
#include "CollisionCheckContext.h"
#include "CollisionContext.h"
#include "CutsceneContext.h"
#include "DoorContext.h"
#include "EffFootmark.h"
#include "EnvironmentContext.h"
#include "GameState.h"
#include "InterfaceContext.h"
#include "LightContext.h"
#include "MessageContext.h"
#include "MtxF.h"
#include "ObjectContext.h"
#include "PauseContext.h"
#include "PauseInfo.h"
#include "PreRenderContext.h"
#include "RoomContext.h"
#include "SkyboxContext.h"
#include "SoundContext.h"
#include "SoundSource.h"
#include "SramContext.h"
#include "TransitionActorContext.h"
#include "TransitionContext.h"
#include "TransitionType.h" // For TransitionFade
#include "View.h"
#include <libultra/PR/gbi.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
// TODO:FlexSkeletonHeader, move to proper files
typedef int32_t (*GenericFunc)(struct GlobalContext* globalCtx);
typedef int32_t (*PlayerFunc)(struct GlobalContext* globalCtx, struct Player* player);
typedef void (*PlayerFunc2)(struct Player* player, struct GlobalContext* globalCtx);
typedef void (*PlayerInitFunc)(struct Player* player, struct GlobalContext* globalCtx, struct FlexSkeletonHeader* skelHeader);
typedef void (*PlayerUpdateFunc)(struct Player* player, struct GlobalContext* globalCtx, struct Input* input);
typedef int32_t (*StartPlayerCutsceneFunc)(struct GlobalContext* globalCtx, struct Actor* actor, int32_t mode);
typedef int32_t (*DamagePlayerFunc)(struct GlobalContext* globalCtx, int32_t damage);

typedef struct GlobalContext {
    union {
        /* 0x00000 */ GameState game;
        /* 0x00000 */ GameState state;
    };
    /* 0x000A4 */ int16_t sceneNum;
    /* 0x000A6 */ uint8_t sceneConfig;
    /* 0x000A7 */ uint8_t _pad0;
    /* 0x000A8 */ char* keepSegment;
    /* 0x000AC */ char* exchange_keepSegment;
    /* 0x000B0 */ char* sceneSegment;
    /* 0x000B4 */ int32_t _pad1;
    /* 0x000B8 */ View view;
    /* 0x001E0 */ Camera mainCamera;
    /* 0x0034C */ Camera subCameras[3];
    /* 0x00790 */ struct Camera* cameraPtrs[4];
    /* 0x007A0 */ int16_t activeCamera;
    /* 0x007A2 */ int16_t nextCamera;
    /* 0x007A4 */ SoundContext soundCtx;
    /* 0x007A8 */ LightContext lightCtx;
    /* 0x007B8 */ PauseInfo pauseInfo;
    /* 0x007C0 */ CollisionContext colCtx;
    /* 0x01C24 */ ActorContext actorCtx;
    /* 0x01D64 */ CutsceneContext csCtx;
    /* 0x01DB4 */ SoundSource soundSources[16];
    /* 0x01F74 */ SramContext sramCtx;
    /* 0x01F78 */ SkyboxContext skyboxCtx;
    /* 0x020D8 */ MessageContext msgCtx;         // "message"
    /* 0x104F0 */ InterfaceContext interfaceCtx; // "parameter"
    /* 0x10760 */ PauseContext pauseCtx;
    /* 0x10A20 */ uint16_t gover;
    /* 0x10A24 */ EnvironmentContext envCtx;
    /* 0x10B20 */ AnimationContext animationCtx;
    /* 0x117A4 */ ObjectContext objectCtx;
    /* 0x11CBC */ RoomContext roomCtx;
    /* 0x11D30 */ int _pad2; // Is this real??
    /* 0x11D34 */ TransitionActorContext transitionActorCtx;
    /* 0x11D3C */ PlayerInitFunc playerInit;
    /* 0x11D40 */ PlayerUpdateFunc playerUpdate;
    /* 0x11D44 */ GenericFunc isPlayerDroppingFish;
    /* 0x11D48 */ GenericFunc startPlayerFishing;
    /* 0x11D4C */ PlayerFunc grabPlayer;
    /* 0x11D50 */ StartPlayerCutsceneFunc startPlayerCutscene;
    /* 0x11D54 */ PlayerFunc2 func_11D54;
    /* 0x11D58 */ DamagePlayerFunc damagePlayer;
    /* 0x11D5C */ ActorFunc talkWithPlayer;
    /* 0x11D60 */ MtxF projectionMatrix;
    /* 0x11DA0 */ MtxF softspriteMatrix;
    /* 0x11DE0 */ Mtx* softspriteMtxp;
    /* 0x11DE4 */ uint32_t gameplayFrames;
    /* 0x11DE8 */ uint8_t linkAgeOnLoad;
    /* 0x11DE9 */ uint8_t actorStopFlag;
    /* 0x11DEA */ uint8_t curSpawn;
    /* 0x11DEB */ uint8_t nbSetupActors;
    /* 0x11DEC */ uint8_t nbRooms; // Member of addition substruct "Room_Rom_Address" in source which includes RomFile*
    /* 0x11DF0 */ struct RomFile* roomList;
    /* 0x11DF4 */ struct ActorEntry* linkActorEntry;
    /* 0x11DF8 */ struct ActorEntry* setupActorList;
    /* 0x11DFC */ struct CameraData* cameraData;
    /* 0x11E00 */ struct EntranceEntry* setupEntranceList;
    /* 0x11E04 */ int16_t* setupExitList;
    /* 0x11E08 */ struct Path* setupPathList;
    /* 0x11E0C */ struct ElfMessage* cUpElfMsgs;
    /* 0x11E10 */ void* specialEffect;
    /* 0x11E14 */ uint8_t skyboxId;
    /* 0x11E15 */ int8_t sceneLoadFlag; // "fade_direction"
    /* 0x11E16 */ int16_t fadeCounter;
    /* 0x11E18 */ int16_t bgFadeCounter;
    /* 0x11E1A */ int16_t nextEntranceIndex;
    /* 0x11E1C */ MtxF dynamicCheckMatrix;
    /* 0x11E5C */ int8_t shootingGalleryStatus;
    /* 0x11E5D */ int8_t bombchuBowlingStatus; // "bombchu_game_flag"
    /* 0x11E5E */ uint8_t fadeTransition;
    /* 0x11E60 */ CollisionCheckContext colChkCtx;
    /* 0x120FC */ uint16_t envFlags[20];
    /* 0x12124 */ PreRenderContext preRenderCtx;
    /* 0x12174 */ PreRenderContext preRender7kPolygon;
    /* 0x121C4 */ uint8_t _pad3[3];
    /* 0x121C7 */ uint8_t zBufferMode; // 0 = none, 1 = zbuffer, 2 = prerender
    /* 0x121C8 */ TransitionContext transitionCtx;
    /* 0x12418 */ uint8_t _pad4[3];
    /* 0x1241B */ uint8_t transitionMode; // "fbdemo_wipe_modem"
    /* 0x1241C */ TransitionFade transitionFade;
    /* 0x12428 */ uint8_t _pad5[3];
    /* 0x1242B */ uint8_t prerenderSkyboxSwitch;
    /* 0x1242C */ struct Scene* loadedScene;
    /* 0x12430 */ uint8_t _pad6[0xE8];
} GlobalContext; /* sizeof = 0x12518 */

#else /* GAME_VERSION_1_0 */
#warning "GlobalContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
// TODO:FlexSkeletonHeader, move to proper files
typedef int32_t (*GenericFunc)(struct GlobalContext* globalCtx);
typedef int32_t (*PlayerFunc)(struct GlobalContext* globalCtx, struct Player* player);
typedef void (*PlayerFunc2)(struct Player* player, struct GlobalContext* globalCtx);
typedef void (*PlayerInitFunc)(struct Player* player, struct GlobalContext* globalCtx, struct FlexSkeletonHeader* skelHeader);
typedef void (*PlayerUpdateFunc)(struct Player* player, struct GlobalContext* globalCtx, struct Input* input);
typedef int32_t (*StartPlayerCutsceneFunc)(struct GlobalContext* globalCtx, struct Actor* actor, int32_t mode);
typedef int32_t (*DamagePlayerFunc)(struct GlobalContext* globalCtx, int32_t damage);

typedef struct GlobalContext {
    union {
        /* 0x00000 */ GameState game;
        /* 0x00000 */ GameState state;
    };
    /* 0x000A4 */ int16_t sceneNum;
    /* 0x000A6 */ uint8_t sceneConfig;
    /* 0x000A7 */ char unk_A7[0x9];
    /* 0x000B0 */ void* sceneSegment;
    /* 0x000B4 */ char unk_B4[0x4];
    /* 0x000B8 */ View view;
    /* 0x00220 */ Camera mainCamera;
    /* 0x00398 */ Camera subCameras[3];
    /* 0x00800 */ Camera* cameraPtrs[4];
    /* 0x00810 */ int16_t activeCamera;
    /* 0x00812 */ int16_t nextCamera;
    /* 0x00814 */ SoundContext soundCtx;
    /* 0x00818 */ LightContext lightCtx;
    /* 0x00828 */ PauseInfo pauseInfo;
    /* 0x00830 */ CollisionContext colCtx;
    /* 0x01CA0 */ ActorContext actorCtx;
    /* 0x01F24 */ CutsceneContext csCtx;
    /* 0x01F78 */ SoundSource soundSources[16];
    /* 0x02138 */ EffFootmark footprintInfo[100];
    /* 0x046B8 */ SramContext sramCtx;
    /* 0x046E0 */ SkyboxContext skyboxCtx;
    /* 0x04908 */ MessageContext msgCtx;
    /* 0x169E8 */ InterfaceContext interfaceCtx;
    /* 0x16D30 */ PauseContext pauseCtx;
    /* 0x17000 */ uint16_t gover;
    /* 0x17004 */ EnvironmentContext envCtx;
    /* 0x17104 */ AnimationContext animationCtx;
    /* 0x17D88 */ ObjectContext objectCtx;
    /* 0x186E0 */ RoomContext roomCtx;
    /* 0x18760 */ DoorContext doorCtx;
    /* 0x18768 */ PlayerInitFunc playerInit;
    /* 0x1876C */ PlayerUpdateFunc playerUpdate;
    /* 0x18770 */ GenericFunc isPlayerDroppingFish;
    /* 0x18774 */ GenericFunc startPlayerFishing;
    /* 0x18778 */ PlayerFunc grabPlayer;
    /* 0x1877C */ StartPlayerCutsceneFunc startPlayerCutscene;
    /* 0x18780 */ PlayerFunc2 func_18780;
    /* 0x18784 */ DamagePlayerFunc damagePlayer;
    /* 0x18788 */ ActorFunc2 talkWithPlayer;
    /* 0x1878C */ void* unk_1878C; //! @TODO: Determine function prototype
    /* 0x18790 */ void* unk_18790; //! @TODO: Determine function prototype
    /* 0x18794 */ void* unk_18794; //! @TODO: Determine function prototype
    /* 0x18798 */ int32_t (*setPlayerTalkAnim)(struct GlobalContext* globalCtx, void* talkAnim, int32_t arg2);
    /* 0x1879C */ int16_t unk_1879C[10];
    /* 0x187B0 */ MtxF projectionMatrix;
    /* 0x187F0 */ Vec3f unk_187F0;
    /* 0x187FC */ MtxF mf_187FC;
    /* 0x1883C */ Mtx* unk_1883C;
    /* 0x18840 */ uint32_t gameplayFrames;
    /* 0x18844 */ uint8_t unk_18844;
    /* 0x18845 */ uint8_t unk_18845;
    /* 0x18846 */ int16_t nbSetupActors;
    /* 0x18848 */ uint8_t nbRooms;
    /* 0x1884C */ struct RomFile* roomList;
    /* 0x18850 */ struct ActorEntry* linkActorEntry;
    /* 0x18854 */ struct ActorEntry* setupActorList;
    /* 0x18858 */ struct CameraData* cameraData;
    /* 0x1885C */ struct EntranceEntry* setupEntranceList;
    /* 0x18860 */ uint16_t* setupExitList;
    /* 0x18864 */ struct Path* setupPathList;
    /* 0x18868 */ void* unk_18868;
    /* 0x1886C */ struct AnimatedMaterial* sceneMaterialAnims;
    /* 0x18870 */ void* specialEffects;
    /* 0x18874 */ uint8_t skyboxId;
    /* 0x18875 */ int8_t sceneLoadFlag; // "fade_direction"
    /* 0x18876 */ int16_t unk_18876;
    /* 0x18878 */ int16_t unk_18878;
    /* 0x1887A */ uint16_t nextEntranceIndex;
    /* 0x1887C */ int8_t unk_1887C;
    /* 0x1887D */ int8_t unk_1887D;
    /* 0x1887E */ int8_t unk_1887E;
    /* 0x1887F */ uint8_t fadeTransition;
    /* 0x18880 */ uint8_t unk_18880;
    /* 0x18884 */ CollisionCheckContext colChkCtx;
    /* 0x18B20 */ uint16_t envFlags[20];
    /* 0x18B48 */ uint8_t curSpawn;
    /* 0x18B49 */ uint8_t unk_18B49;
    /* 0x18B4A */ uint8_t unk_18B4A;
    /* 0x18B4C */ PreRenderContext preRenderCtx;
    /* 0x18B9C */ char unk_18B9C[0x2B8];
    /* 0x18E54 */ struct Scene* loadedScene;
    /* 0x18E58 */ char unk_18E58[0x400];
} GlobalContext; /* sizeof = 0x19258 */
#endif                /* GAME_MM */

extern GlobalContext gGlobalCtx;
SYMBOL_VERSION_CONFIG(gGlobalCtx, 0x801C84A0, 0x803E6B20);

extern uint32_t gSegments[];
SYMBOL_VERSION_CONFIG(gSegments, 0x80120C38, 0xDEADBEEF);

#endif
