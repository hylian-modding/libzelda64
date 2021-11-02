#ifndef LINKANIMATION_FUNC_H
#define LINKANIMATION_FUNC_H

#include "types/SkelAnime.h"
#include "types/FlexSkeletonHeader.h"
#include "types/SkeletonHeader.h"
#include "types/LinkAnimationHeader.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void SkelAnime_InitLink(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, LinkAnimationHeader* animation, int32_t flags, Vec3s* jointTable, Vec3s* morphTable, int32_t limbBufCount);
SYMBOL_VERSION_CONFIG(SkelAnime_InitLink, 0x8008BB08, 0x80135F88);

extern void LinkAnimation_SetUpdateFunction(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_SetUpdateFunction, 0x8008BC6C, 0x801360A8);

extern int32_t LinkAnimation_Update(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Update, 0x8008BCA4, 0x801360E0);

extern int32_t LinkAnimation_Morph(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Morph, 0x8008BCC8, 0x80136104);

extern void LinkAnimation_AnimateFrame(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_AnimateFrame, 0x8008BD84, 0x801361BC);

extern int32_t LinkAnimation_Loop(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Loop, 0x8008BE60, 0x80136288);

extern int32_t LinkAnimation_Once(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Once, 0x8008BF00, 0x8013631C);

extern void LinkAnimation_Change(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
SYMBOL_VERSION_CONFIG(LinkAnimation_Change, 0x8008C000, 0x80136414);

extern void LinkAnimation_PlayOnce(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayOnce, 0x8008C178, 0x8013658C);

extern void LinkAnimation_PlayOnceSetSpeed(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayOnceSetSpeed, 0x8008C1D8, 0x801365EC);

extern void LinkAnimation_PlayLoop(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayLoop, 0x8008C23C, 0x80136650);

extern void LinkAnimation_PlayLoopSetSpeed(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayLoopSetSpeed, 0x8008C298, 0x801366AC);

extern void LinkAnimation_CopyJointToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_CopyJointToMorph, 0x8008C2F8, 0x8013670C);

extern void LinkAnimation_CopyMorphToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_CopyMorphToJoint, 0x8008C328, 0x8013673C);

extern void LinkAnimation_LoadToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_LoadToMorph, 0x8008C358, 0x8013676C);

extern void LinkAnimation_LoadToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_LoadToJoint, 0x8008C39C, 0x801367B0);

extern void LinkAnimation_InterpJointMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, float weight);
SYMBOL_VERSION_CONFIG(LinkAnimation_InterpJointMorph, 0x8008C3E0, 0x801367F4);

extern void LinkAnimation_BlendToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation1, float frame1, LinkAnimationHeader* animation2, float frame2, float blendWeight, Vec3s* blendTable);
SYMBOL_VERSION_CONFIG(LinkAnimation_BlendToJoint, 0x8008C418, 0x8013682C);

extern void LinkAnimation_BlendToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation1, float frame1, LinkAnimationHeader* animation2, float frame2, float blendWeight, Vec3s* blendTable);
SYMBOL_VERSION_CONFIG(LinkAnimation_BlendToMorph, 0x8008C4B8, 0x801368CC);

extern void LinkAnimation_EndLoop(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_EndLoop, 0x8008C558, 0x8013696C);

extern int32_t Animation_OnFrameImpl(SkelAnime* skelAnime, float frame, float updateRate);
SYMBOL_VERSION_CONFIG(Animation_OnFrameImpl, 0x8008C57C, 0x80136990);

extern int32_t LinkAnimation_OnFrame(SkelAnime* skelAnime, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_OnFrame, 0x8008C634, 0x80136A48);

#endif
