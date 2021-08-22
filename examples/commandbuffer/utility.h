#ifndef CB_EXTERNS_H
#define CB_EXTERNS_H

#include <libultra/ultra64.h>
#include <libzelda64/lib/types/Actor.h>
#include <libzelda64/lib/types/Vec3s.h>
#include <libzelda64/lib/types/RomFile.h>
#include <libzelda64/lib/types/ActorOverlay.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/SaveContext.h>
#include <libzelda64/lib/types/LightNode.h>
#include <libzelda64/lib/types/Color_RGBA8_u32.h>

typedef struct Lights {
    /* 0x00 */ uint8_t numLights;
    /* 0x08 */ Lightsn l;
} Lights; /* sizeof = 0x80 */

#define ALIGN16(val) (((val) + 0xF) & ~0xF)
#define PHYSICAL_TO_VIRTUAL(addr) (void*)((uint32_t)(addr) + 0x80000000)
#define VIRTUAL_TO_PHYSICAL(addr) (uint32_t)((uint8_t*)(addr) - 0x80000000)
#define SEGMENTED_TO_VIRTUAL(addr) PHYSICAL_TO_VIRTUAL(gSegments[SEGMENT_NUMBER(addr)] + SEGMENT_OFFSET(addr))

#define POLY_OPA_DISP globalCtx->game.gfxCtx->polyOpa.p
#define POLY_XLU_DISP globalCtx->game.gfxCtx->polyXlu.p

extern RomFile gObjectTable[];
asm("gObjectTable = 0x800F8FF0");

extern uint32_t gSegments[];
asm("gSegments = 0x80120C38");

extern ActorOverlay gActorOverlayTable[];
asm("gActorOverlayTable = 0x800E8530");

extern GlobalContext global;
asm("global = 0x801C84A0");

extern SaveContext gSaveContext;
asm("gSaveContext = 0x8011A5D0");

extern uint32_t debug;
asm("debug = 0x806C0000");

extern void* GameState_Alloc(GameState* gameState, uint32_t size);
asm("GameState_Alloc = 0x800A01B8");

extern int32_t DmaMgr_SendRequestImpl(DmaRequest* req, uint32_t ram, uint32_t vrom, uint32_t size, uint32_t unk, OSMesgQueue* queue, OSMesg msg);
asm("DmaMgr_SendRequestImpl = 0x80000D28");

//extern void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, int32_t count);
asm("osCreateMesgQueue = 0x80004220");

//extern int32_t osRecvMesg(OSMesgQueue* mq, OSMesg* msg, int32_t flag);
asm("osRecvMesg = 0x80002030");

extern void Lights_BindAll(Lights* lights, LightNode* listHead, Vec3f* vec);
asm("Lights_BindAll = 0x80066298");

extern void Lights_Draw(Lights* lights, GraphicsContext* gfxCtx);
asm("Lights_Draw = 0x80065D60");

extern void func_800D1694(float x, float y, float z, Vec3s* vec);
asm("func_800D1694 = 0x800AB510");

extern void Actor_SetObjectDependency(GlobalContext* globalCtx, Actor* actor);
asm("Actor_SetObjectDependency = 0x80020FA4");

extern void func_80026860(GlobalContext* globalCtx, Color_RGBA8* color, int16_t arg2, int16_t arg3);
asm("func_80026860 = 0x8001A654");

extern void func_80026400(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
asm("func_80026400 = 0x8001A288");

extern void func_80026A6C(GlobalContext* globalCtx);
asm("func_80026A6C = 0x8001A83C");

extern void func_80026608(GlobalContext* globalCtx);
asm("func_80026608 = 0x8001A468");

extern void SkinMatrix_SetTranslate(MtxF* mf, float x, float y, float z);
asm("SkinMatrix_SetTranslate = 0x8008F82C");

extern void SkinMatrix_SetScale(MtxF* mf, float x, float y, float z);
asm("SkinMatrix_SetScale = 0x8008F4A8");

extern void SkinMatrix_MtxFMtxFMult(MtxF* mfB, MtxF* mfA, MtxF* dest);
asm("SkinMatrix_MtxFMtxFMult = 0x8008EDB8");

extern Mtx* SkinMatrix_MtxFToNewMtx(GraphicsContext* gfxCtx, MtxF* src);
asm("SkinMatrix_MtxFToNewMtx = 0x8008FC98");

extern void func_80094C50(GraphicsContext* gfxCtx);
asm("func_80094C50 = 0x8007E978");

#endif