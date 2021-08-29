#ifndef GRAPHICS_FUNCS_H
#define GRAPHICS_FUNCS_H

#include "types/GraphicsContext.h"
#include "zelda64_version.h"
#include <inttypes.h>

#define DrawDlistOpa(DLIST) (Gfx_DrawDListOpa)(globalCtx, (DLIST));
// called Matrix_Pop in decomp, Pull is another function. Poe's sheet is wack?
#define Matrix_Pop Matrix_Pull

extern void Gfx_DrawDListOpa(struct GlobalContext* globalCtx, struct Gfx* dlist);
SYMBOL_VERSION_CONFIG(Gfx_DrawDListOpa, 0x80028048, 0x800BDFC0);

extern void Matrix_Push(void);
SYMBOL_VERSION_CONFIG(Matrix_Push, 0x800AA6EC, 0x8018019C);

extern void Matrix_Translate(float x, float y, float z, int32_t mode);
SYMBOL_VERSION_CONFIG(Matrix_Translate, 0x800AA7F4, 0x8018029C);

extern void Matrix_RotateRPY(int16_t x, int16_t y, int16_t z, int32_t mode);
SYMBOL_VERSION_CONFIG(Matrix_RotateRPY, 0x800AAF00, 0x8018039C);

extern void Matrix_Scale(float x, float y, float z, int32_t mode);
SYMBOL_VERSION_CONFIG(Matrix_Scale, 0x800AA8FC, 0x8018039C);

extern void Matrix_Pull(void);
SYMBOL_VERSION_CONFIG(Matrix_Pull, 0x800AA724, 0x80000180);

extern void Matrix_JointPosition(struct Vec3f* position, struct Vec3f* rotation);
SYMBOL_VERSION_CONFIG(Matrix_JointPosition, 0x800AB1BC, 0x80000180);

extern void Matrix_MultVec3f(struct Vec3f* src, struct Vec3f* dest);
SYMBOL_VERSION_CONFIG(Matrix_MultVec3f, 0x800AB958, 0x80181A98);

extern void Matrix_SoftCv3_Load(float x, float y, float z, struct Vec3s* v);
SYMBOL_VERSION_CONFIG(Matrix_SoftCv3_Load, 0x800AB510, 0x80181650);

extern Mtx* Matrix_ToMtx(Mtx* dest, char* file, int32_t line);
SYMBOL_VERSION_CONFIG(Matrix_ToMtx, 0x800AB8D8, 0x80181A18);

extern Mtx* Matrix_NewMtx(GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(Matrix_NewMtx, 0x800AB900, 0x80181A40);

extern void func_80094C50(GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_80094C50, 0x8007E978, 0x8012C8FC);

// TODO: Move
extern void EffectSsDtBubble_SpawnCustomColor(
    struct GlobalContext* globalCtx, struct Vec3f* pos, struct Vec3f* velocity, struct Vec3f* accel, struct Color_RGBA8* primColor, struct Color_RGBA8* envColor, int16_t scale, int16_t life,
    int16_t randXZ);
SYMBOL_VERSION_CONFIG(EffectSsDtBubble_SpawnCustomColor, 0x8001D18C, 0x80000180);

extern void Item_DropCollectibleRandom(struct GlobalContext* globalCtx, struct Actor* fromActor, struct Vec3f* spawnPos, int16_t params);
SYMBOL_VERSION_CONFIG(Item_DropCollectibleRandom, 0x80013A84, 0x80000180);

extern void func_800D1FD4(MtxF* mf);
SYMBOL_VERSION_CONFIG(func_800D1FD4, 0x800ABE54, 0x80000180);

extern void Matrix_RotateZ(float z, uint8_t mode);
SYMBOL_VERSION_CONFIG(Matrix_RotateZ, 0x800AAD4C, 0x80000180);

extern void func_80093D84(GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_80093D84, 0x8007E2C0, 0x80000180);

extern void func_80026608(GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_80026608, 0x8001A468, 0x80000180);

extern void func_80026A6C(GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_80026A6C, 0x8001A83C, 0x80000180);

extern void func_80026400(GlobalContext* globalCtx, struct Color_RGBA8* color, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80026400, 0x8001A288, 0x80000180);

extern void func_80026860(GlobalContext* globalCtx, struct Color_RGBA8* color, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80026860, 0x8001A654, 0x80000180);

extern void func_800D1694(float x, float y, float z, struct Vec3s* vec);
SYMBOL_VERSION_CONFIG(func_800D1694, 0x800AB510, 0x80000180);


#endif