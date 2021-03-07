#ifndef SKELANIME_FUNC_H
#define SKELANIME_FUNC_H

#include "types/Vec3s.h"
#include "types/SkelAnime.h"
#include "types/SkeletonHeader.h"
#include "types/FlexSkeletonHeader.h"
#include "types/AnimationHeader.h"
#include "types/AnimationHeaderCommon.h"
#include <inttypes.h>

// SkelAnime_DrawFlexOpa_LimbCallback (always return 0?)
typedef int32_t (*OverrideLimbDrawOpa)(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3f* pos, Vec3s* rot, void* actor);
// SkelAnime_DrawFlexOpa_SegTextureCallback (always return 1?)
typedef void (*PostLimbDrawOpa)(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, void* actor);

extern int32_t SkelAnime_Init(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct SkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation, Vec3s* limbDrawTable, Vec3s* morfDrawTable, int32_t limbCount);
asm("SkelAnime_Init = 0x8008C684");

extern int32_t SkelAnime_InitFlex(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct FlexSkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation, Vec3s* limbDrawTable, Vec3s* limbPosTable, int32_t limbCount);
asm("SkelAnime_InitFlex = 0x8008C788");

// SkelAnime_InitLinkAnimation / Skeleton_Info_Rom_SV_ct on Poe's sheet (Decomp renamed, ovl didn't have)
extern void SkelAnime_InitLink(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct FlexSkeletonHeader* skeletonHeaderSeg, struct LinkAnimationHeader* animation, int32_t initFlags, struct Vec3s* jointTable, struct Vec3s* morphTable, int32_t limbCount);
asm("SkelAnime_InitLink = 0x8008BB08");

extern void SkelAnime_ChangeAnim(struct SkelAnime* skelAnime, struct AnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
asm("SkelAnime_ChangeAnim = 0x8008D17C");

extern void SkelAnime_DrawOpa(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* instance);
asm("SkelAnime_DrawOpa = 0x8008993C");

void SkelAnime_DrawFlexOpa(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* instance);
asm("SkelAnime_DrawFlexOpa = 0x80089D8C");

int16_t Animation_GetLength(void* animation);
asm("Animation_GetLength = 0x8008A158");

/* static inline void SkelAnime_InitWrapper(struct GameState *game_state, int is_matrix, struct SkelAnime *sk, uint32_t skeleton)
{
    if (is_matrix)
    {
        SkelAnime_InitFlex(game_state, sk, skeleton, 0, 0, 0, 0);
    }
    else
    {
        SkelAnime_Init(game_state, sk, skeleton, 0, 0, 0, 0);
    }
    SkelAnime_ChangeAnim(sk, 0, 0.0, 0.0, 0, 0, 0.0);
}

static inline void SkelAnime_DrawWrapper(struct GameState *gl, int matrix_limbs, void *instance, struct SkelAnime *sk, SkelAnime_DrawFlexOpa_LimbCallback callback0, SkelAnime_DrawFlexOpa_SegTextureCallback callback1)
{
    if (matrix_limbs)
    {
        SkelAnime_DrawFlexOpa(
            gl, sk->limb_index, sk->draw_table_rot, matrix_limbs, callback0, callback1, instance);
    }
    else
    {
        SkelAnime_DrawOpa(
            gl, sk->limb_index, sk->draw_table_rot, callback0, callback1, instance);
    }
} */

#endif

