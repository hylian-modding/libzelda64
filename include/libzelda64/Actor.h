#ifndef ACTOR_FUNC_H
#define ACTOR_FUNC_H

#include "types/Actor.h"
#include "types/ActorFunc.h"
#include "types/ActorInit.h"
#include "types/ActorOverlay.h"
#include "types/SkelAnime.h"
#include "zelda64_version.h"
#include <inttypes.h>

//extern ? func_800B3AD0();
//SYMBOL_VERSION_CONFIG(func_800B3AD0, 0x80000180, 0x800B3AD0);

extern void ActorShadow_Draw(Actor* actor, Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_Draw, 0x8001EC44, 0x800B3BC8);

extern void ActorShadow_DrawCircle(Actor* actor, Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawCircle, 0x8001EFF4, 0x800B3FC0);

//extern ? func_800B4024();
//SYMBOL_VERSION_CONFIG(func_800B4024, 0x80000180, 0x800B4024);

extern void ActorShadow_DrawWhiteCircle(Actor* actor, Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawWhiteCircle, 0x8001F01C, 0x800B4088);

extern void ActorShadow_DrawHorse(Actor* actor, Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawHorse, 0x8001F04C, 0x800B40B8);

extern void ActorShadow_DrawFoot(struct GlobalContext* globalCtx, Light* light, MtxF* arg2, s32 arg3, float arg4, float arg5, float arg6);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawFoot, 0x8001F074, 0x800B40E0);

extern void ActorShadow_DrawFeet(Actor* actor, Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawFeet, 0x8001F280, 0x800B42F8);

extern void Actor_SetFeetPos(Actor* actor, int32_t limbIndex, int32_t leftFootIndex, Vec3f* leftFootPos, int32_t rightFootIndex, Vec3f* rightFootPos);
SYMBOL_VERSION_CONFIG(Actor_SetFeetPos, 0x8001F74C, 0x800B4A98);

//extern ? func_800B4AEC();
//SYMBOL_VERSION_CONFIG(func_800B4AEC, 0x80000180, 0x800B4AEC);

//extern ? func_800B4B50();
//SYMBOL_VERSION_CONFIG(func_800B4B50, 0x80000180, 0x800B4B50);

extern void func_8002BE04(struct GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2, float* arg3);
SYMBOL_VERSION_CONFIG(func_8002BE04, 0x8001F7A0, 0x800B4EDC);

extern void func_8002BE64(TargetContext* targetCtx, int32_t index, float arg2, float arg3, float arg4);
SYMBOL_VERSION_CONFIG(func_8002BE64, 0x8001F804, 0x800B4F40);

extern void func_8002BE98(TargetContext* targetCtx, int32_t actorCategory, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002BE98, 0x8001F83C, 0x800B4F78);

extern void func_8002BF60(TargetContext* targetCtx, Actor* actor, int32_t actorCategory, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002BF60, 0x8001F904, 0x800B5040);

extern void func_8002C0C0(TargetContext* targetCtx, Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002C0C0, 0x8001FA68, 0x800B51A4);

extern void func_8002C124(TargetContext* targetCtx, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002C124, 0x8001FACC, 0x800B5208);

extern void func_8002C7BC(TargetContext* targetCtx, Player* player, Actor* actorArg, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002C7BC, 0x80020108, 0x800B5814);

extern int32_t Flags_GetSwitch(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetSwitch, 0x8002049C, 0x800B5BB0);

extern void Flags_SetSwitch(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_SetSwitch, 0x800204D0, 0x800B5BF4);

extern void Flags_UnsetSwitch(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_UnsetSwitch, 0x80020510, 0x800B5C34);

extern int32_t Flags_GetUnknown(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetUnknown, 0x80020554, 0x80000180);

extern void Flags_SetUnknown(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_SetUnknown, 0x80020588, 0x80000180);

extern void Flags_UnsetUnknown(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_UnsetUnknown, 0x800205C8, 0x80000180);

extern int32_t Flags_GetTreasure(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetTreasure, 0x8002060C, 0x800B5C78);

extern void Flags_SetTreasure(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_SetTreasure, 0x80020624, 0x800B5C90);

//extern ? func_800B5CAC();
//SYMBOL_VERSION_CONFIG(func_800B5CAC, 0x80000180, 0x800B5CAC);

//extern ? func_800B5CB8();
//SYMBOL_VERSION_CONFIG(func_800B5CB8, 0x80000180, 0x800B5CB8);

extern int32_t Flags_GetClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetClear, 0x80020640, 0x800B5CC4);

extern void Flags_SetClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_SetClear, 0x80020658, 0x800B5CDC);

extern void Flags_UnsetClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_UnsetClear, 0x80020674, 0x800B5CF8);

extern int32_t Flags_GetTempClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetTempClear, 0x80020694, 0x800B5D18);

extern void Flags_SetTempClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_SetTempClear, 0x800206AC, 0x800B5D30);

extern void Flags_UnsetTempClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_UnsetTempClear, 0x800206C8, 0x800B5D4C);

extern int32_t Flags_GetCollectible(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetCollectible, 0x800206E8, 0x800B5D6C);

extern void Flags_SetCollectible(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_SetCollectible, 0x8002071C, 0x800B5DB0);

extern void func_8002CDE4(struct GlobalContext* globalCtx, TitleCardContext* titleCtx);
SYMBOL_VERSION_CONFIG(func_8002CDE4, 0x80020760, 0x800B5DF0);

extern void TitleCard_InitBossName(struct GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, int16_t x, int16_t y, uint8_t width, uint8_t height);
SYMBOL_VERSION_CONFIG(TitleCard_InitBossName, 0x80020780, 0x800B5E0C);

extern void TitleCard_InitPlaceName(struct GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, int32_t x, int32_t y, int32_t width, int32_t height, int32_t delay);
SYMBOL_VERSION_CONFIG(TitleCard_InitPlaceName, 0x800207C4, 0x800B5E50);

extern void TitleCard_Update(struct GlobalContext* globalCtx, TitleCardContext* titleCtx);
SYMBOL_VERSION_CONFIG(TitleCard_Update, 0x80020860, 0x800B5E68);

extern void TitleCard_Draw(struct GlobalContext* globalCtx, TitleCardContext* titleCtx);
SYMBOL_VERSION_CONFIG(TitleCard_Draw, 0x8002091C, 0x800B5F24);

extern int32_t func_8002D53C(struct GlobalContext* globalCtx, TitleCardContext* titleCtx);
SYMBOL_VERSION_CONFIG(func_8002D53C, 0x80020E80, 0x800B6434);

//extern ? func_800B6468();
//SYMBOL_VERSION_CONFIG(func_800B6468, 0x80000180, 0x800B6468);

//extern ? func_800B6474();
//SYMBOL_VERSION_CONFIG(func_800B6474, 0x80000180, 0x800B6474);

//extern ? func_800B648C();
//SYMBOL_VERSION_CONFIG(func_800B648C, 0x80000180, 0x800B648C);

//extern ? func_800B64FC();
//SYMBOL_VERSION_CONFIG(func_800B64FC, 0x80000180, 0x800B64FC);

//extern ? func_800B6584();
//SYMBOL_VERSION_CONFIG(func_800B6584, 0x80000180, 0x800B6584);

//extern ? func_800B6608();
//SYMBOL_VERSION_CONFIG(func_800B6608, 0x80000180, 0x800B6608);

//extern ? func_800B6680();
//SYMBOL_VERSION_CONFIG(func_800B6680, 0x80000180, 0x800B6680);

extern void Actor_Kill(Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_Kill, 0x80020EB4, 0x800B670C);

extern void Actor_SetWorldToHome(Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_SetWorldToHome, 0x80020ED4, 0x800B672C);

extern void Actor_SetFocus(Actor* actor, float offset);
SYMBOL_VERSION_CONFIG(Actor_SetFocus, 0x80020F04, 0x800B675C);

extern void Actor_SetWorldRotToShape(Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_SetWorldRotToShape, 0x80020F48, 0x800B67A0);

extern void Actor_SetShapeRotToWorld(Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_SetShapeRotToWorld, 0x80020F68, 0x800B67C0);

extern void Actor_SetScale(Actor* actor, float scale);
SYMBOL_VERSION_CONFIG(Actor_SetScale, 0x80020F88, 0x800B67E0);

extern void Actor_SetObjectDependency(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_SetObjectDependency, 0x80020FA4, 0x800B67FC);

extern void Actor_Init(DynaPolyActor* dynaActor, int32_t flags);
SYMBOL_VERSION_CONFIG(Actor_Init, 0x80020FDC, 0x800B6834);

extern void Actor_Destroy(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_Destroy, 0x800210F0, 0x800B6948);

//extern ? func_800B6988();
//SYMBOL_VERSION_CONFIG(func_800B6988, 0x80000180, 0x800B6988);

extern void func_8002D7EC(Actor* actor);
SYMBOL_VERSION_CONFIG(func_8002D7EC, 0x80021124, 0x800B69AC);

extern void func_8002D868(Actor* actor);
SYMBOL_VERSION_CONFIG(func_8002D868, 0x800211A4, 0x800B6A10);

extern void Actor_MoveForward(Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_MoveForward, 0x8002121C, 0x800B6A88);

extern void func_8002D908(Actor* actor);
SYMBOL_VERSION_CONFIG(func_8002D908, 0x80021248, 0x800B6AB4);

extern void func_8002D97C(Actor* actor);
SYMBOL_VERSION_CONFIG(func_8002D97C, 0x800212B8, 0x800B6B24);

//extern ? func_800B6B50();
//SYMBOL_VERSION_CONFIG(func_800B6B50, 0x80000180, 0x800B6B50);

//extern ? func_800B6BD8();
//SYMBOL_VERSION_CONFIG(func_800B6BD8, 0x80000180, 0x800B6BD8);

extern void func_8002D9A4(Actor* actor, float arg1);
SYMBOL_VERSION_CONFIG(func_8002D9A4, 0x800212E4, 0x800B6C04);

extern void func_8002D9F8(Actor* actor, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(func_8002D9F8, 0x80021338, 0x800B6C58);

extern int16_t Actor_WorldYawTowardActor(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_WorldYawTowardActor, 0x800213B4, 0x800B6CD4);

extern int16_t Actor_FocusYawTowardActor(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_FocusYawTowardActor, 0x800213E0, 0x800B6D00);

extern int16_t Actor_WorldYawTowardPoint(Actor* actor, Vec3f* refPoint);
SYMBOL_VERSION_CONFIG(Actor_WorldYawTowardPoint, 0x8002140C, 0x800B6D2C);

extern int16_t Actor_WorldPitchTowardActor(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_WorldPitchTowardActor, 0x80021430, 0x800B6D50);

extern int16_t Actor_FocusPitchTowardActor(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_FocusPitchTowardActor, 0x8002145C, 0x800B6D7C);

extern int16_t Actor_WorldPitchTowardPoint(Actor* actor, Vec3f* refPoint);
SYMBOL_VERSION_CONFIG(Actor_WorldPitchTowardPoint, 0x80021488, 0x800B6DA8);

extern float Actor_WorldDistXYZToActor(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_WorldDistXYZToActor, 0x800214AC, 0x800B6DCC);

extern float Actor_WorldDistXYZToPoint(Actor* actor, Vec3f* refPoint);
SYMBOL_VERSION_CONFIG(Actor_WorldDistXYZToPoint, 0x800214D8, 0x800B6DF8);

extern float Actor_WorldDistXZToActor(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_WorldDistXZToActor, 0x800214FC, 0x800B6E1C);

extern float Actor_WorldDistXZToPoint(Actor* actor, Vec3f* refPoint);
SYMBOL_VERSION_CONFIG(Actor_WorldDistXZToPoint, 0x80021528, 0x800B6E48);

extern void func_8002DBD0(Actor* actor, Vec3f* result, Vec3f* arg2);
SYMBOL_VERSION_CONFIG(func_8002DBD0, 0x8002154C, 0x800B6E6C);

extern float Actor_HeightDiff(Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(Actor_HeightDiff, 0x800215EC, 0x800B6F0C);

//extern ? func_800B6F20();
//SYMBOL_VERSION_CONFIG(func_800B6F20, 0x80000180, 0x800B6F20);

extern float Player_GetHeight(Player* player);
SYMBOL_VERSION_CONFIG(Player_GetHeight, 0x80021600, 0x800B6FC8);

extern float func_8002DCE4(Player* player);
SYMBOL_VERSION_CONFIG(func_8002DCE4, 0x80021660, 0x800B7090);

extern int32_t func_8002DD6C(Player* player);
SYMBOL_VERSION_CONFIG(func_8002DD6C, 0x800216E8, 0x800B7118);

extern int32_t func_8002DD78(Player* player);
SYMBOL_VERSION_CONFIG(func_8002DD78, 0x800216F8, 0x800B7128);

extern int32_t func_8002DDA8(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002DDA8, 0x8002172C, 0x80000180);

extern int32_t func_8002DDE4(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002DDE4, 0x80021768, 0x800B715C);

extern int32_t func_8002DDF4(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002DDF4, 0x8002177C, 0x80000180);

extern void func_8002DE04(struct GlobalContext* globalCtx, Actor* actorA, Actor* actorB);
SYMBOL_VERSION_CONFIG(func_8002DE04, 0x80021790, 0x80000180);

extern void func_8002DE74(struct GlobalContext* globalCtx, Player* player);
SYMBOL_VERSION_CONFIG(func_8002DE74, 0x80021800, 0x800B7170);

extern void Actor_MountHorse(struct GlobalContext* globalCtx, Player* player, Actor* horse);
SYMBOL_VERSION_CONFIG(Actor_MountHorse, 0x80021858, 0x800B71DC);

extern int32_t func_8002DEEC(Player* player);
SYMBOL_VERSION_CONFIG(func_8002DEEC, 0x8002187C, 0x800B7200);

extern void func_8002DF18(struct GlobalContext* globalCtx, Player* player);
SYMBOL_VERSION_CONFIG(func_8002DF18, 0x800218A8, 0x800B722C);

extern int32_t func_8002DF38(struct GlobalContext* globalCtx, Actor* actor, uint8_t csMode);
SYMBOL_VERSION_CONFIG(func_8002DF38, 0x800218C8, 0x800B724C);

extern int32_t func_8002DF54(struct GlobalContext* globalCtx, Actor* actor, uint8_t arg2);
SYMBOL_VERSION_CONFIG(func_8002DF54, 0x800218EC, 0x800B7298);

extern void func_8002DF90(DynaPolyActor* dynaActor);
SYMBOL_VERSION_CONFIG(func_8002DF90, 0x80021928, 0x800B72E0);

extern void func_8002DFA4(DynaPolyActor* dynaActor, float arg1, int16_t arg2);
SYMBOL_VERSION_CONFIG(func_8002DFA4, 0x80021940, 0x800B72F8);

extern int32_t Player_IsFacingActor(Actor* actor, int16_t angle, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Player_IsFacingActor, 0x80021968, 0x800B7320);

extern int32_t Actor_ActorBIsFacingActorA(Actor* actorA, Actor* actorB, int16_t angle);
SYMBOL_VERSION_CONFIG(Actor_ActorBIsFacingActorA, 0x800219C0, 0x800B7378);

extern int32_t Actor_IsFacingPlayer(Actor* actor, int16_t angle);
SYMBOL_VERSION_CONFIG(Actor_IsFacingPlayer, 0x80021A28, 0x800B73E0);

extern int32_t Actor_ActorAIsFacingActorB(Actor* actorA, Actor* actorB, int16_t angle);
SYMBOL_VERSION_CONFIG(Actor_ActorAIsFacingActorB, 0x80021A74, 0x800B742C);

extern int32_t Actor_IsFacingAndNearPlayer(Actor* actor, float range, int16_t angle);
SYMBOL_VERSION_CONFIG(Actor_IsFacingAndNearPlayer, 0x80021AD4, 0x800B748C);

extern int32_t Actor_ActorAIsFacingAndNearActorB(Actor* actorA, Actor* actorB, float range, int16_t angle);
SYMBOL_VERSION_CONFIG(Actor_ActorAIsFacingAndNearActorB, 0x80021B54, 0x800B750C);

//extern ? func_800B75A0();
//SYMBOL_VERSION_CONFIG(func_800B75A0, 0x80000180, 0x800B75A0);

extern int32_t func_8002E234(Actor* actor, float arg1, int32_t arg2);
SYMBOL_VERSION_CONFIG(func_8002E234, 0x80021BE8, 0x800B761C);

extern int32_t func_8002E2AC(GlobalContext* globalCtx, Actor* actor, Vec3f* arg2, int32_t arg3);
SYMBOL_VERSION_CONFIG(func_8002E2AC, 0x80021C60, 0x800B7678);

extern void Actor_UpdateBgCheckInfo(struct GlobalContext* globalCtx, Actor* actor, float wallCheckHeight, float wallCheckRadius, float ceilingCheckHeight, int32_t flags);
SYMBOL_VERSION_CONFIG(Actor_UpdateBgCheckInfo, 0x80021E6C, 0x800B78B8);

extern Gfx* func_8002E830(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx, Gfx* gfx, Hilite** hilite);
SYMBOL_VERSION_CONFIG(func_8002E830, 0x800221EC, 0x800B7E04);

extern Hilite* func_8002EABC(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_8002EABC, 0x800223C8, 0x800B7FE0);

extern Hilite* func_8002EB44(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_8002EB44, 0x80022400, 0x800B8018);

extern void func_8002EBCC(Actor* actor, struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(func_8002EBCC, 0x80022438, 0x800B8050);

extern void func_8002ED80(Actor* actor, struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(func_8002ED80, 0x80022554, 0x800B8118);

extern PosRot* Actor_GetFocus(PosRot* arg0, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_GetFocus, 0x80022670, 0x800B81E0);

extern PosRot* Actor_GetWorld(PosRot* arg0, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_GetWorld, 0x800226A4, 0x800B8214);

extern PosRot* Actor_GetWorldPosShapeRot(PosRot* arg0, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_GetWorldPosShapeRot, 0x800226D8, 0x800B8248);

extern float func_8002EFC0(Actor* actor, Player* player, int16_t arg2);
SYMBOL_VERSION_CONFIG(func_8002EFC0, 0x80022754, 0x800B82EC);

extern uint32_t func_8002F090(Actor* actor, float arg1);
SYMBOL_VERSION_CONFIG(func_8002F090, 0x80022824, 0x800B83BC);

extern int32_t func_8002F0C8(Actor* actor, Player* player, int32_t arg2);
SYMBOL_VERSION_CONFIG(func_8002F0C8, 0x80022860, 0x800B83F8);

extern uint32_t func_8002F194(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F194, 0x80022930, 0x800B84D0);

extern int32_t func_8002F1C4(Actor* actor, struct GlobalContext* globalCtx, float arg2, float arg3, uint32_t arg4);
SYMBOL_VERSION_CONFIG(func_8002F1C4, 0x80022960, 0x800B8500);

extern int32_t func_8002F298(Actor* actor, struct GlobalContext* globalCtx, float arg2, uint32_t arg3);
SYMBOL_VERSION_CONFIG(func_8002F298, 0x80022A34, 0x800B85E0);

extern int32_t func_8002F2CC(Actor* actor, struct GlobalContext* globalCtx, float arg2);
SYMBOL_VERSION_CONFIG(func_8002F2CC, 0x80022A68, 0x800B8614);

extern int32_t func_8002F2F4(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F2F4, 0x80022A90, 0x800B863C);

extern uint32_t func_8002F334(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F334, 0x80022AD0, 0x800B867C);

//extern ? func_800B86C8();
//SYMBOL_VERSION_CONFIG(func_800B86C8, 0x80000180, 0x800B86C8);

extern int8_t func_8002F368(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F368, 0x80022B04, 0x800B8708);

//extern ? func_800B8718();
//SYMBOL_VERSION_CONFIG(func_800B8718, 0x80000180, 0x800B8718);

//extern ? func_800B874C();
//SYMBOL_VERSION_CONFIG(func_800B874C, 0x80000180, 0x800B874C);

//extern ? func_800B8804();
//SYMBOL_VERSION_CONFIG(func_800B8804, 0x80000180, 0x800B8804);

//extern ? func_800B882C();
//SYMBOL_VERSION_CONFIG(func_800B882C, 0x80000180, 0x800B882C);

//extern ? func_800B886C();
//SYMBOL_VERSION_CONFIG(func_800B886C, 0x80000180, 0x800B886C);

extern void func_8002F374(struct GlobalContext* globalCtx, Actor* actor, int16_t* x, int16_t* y);
SYMBOL_VERSION_CONFIG(func_8002F374, 0x80022B14, 0x800B8898);

//extern ? func_800B8934();
//SYMBOL_VERSION_CONFIG(func_800B8934, 0x80000180, 0x800B8934);

extern uint32_t Actor_HasParent(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_HasParent, 0x80022BB0, 0x800B89F8);

extern int32_t func_8002F434(Actor* actor, struct GlobalContext* globalCtx, int32_t getItemId, float xzRange, float yRange);
SYMBOL_VERSION_CONFIG(func_8002F434, 0x80022BD4, 0x800B8A1C);

extern void func_8002F554(Actor* actor, struct GlobalContext* globalCtx, int32_t getItemId);
SYMBOL_VERSION_CONFIG(func_8002F554, 0x80022CF4, 0x800B8B84);

extern void func_8002F580(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F580, 0x80022D20, 0x800B8BB0);

//extern ? func_800B8BD0();
//SYMBOL_VERSION_CONFIG(func_800B8BD0, 0x80000180, 0x800B8BD0);

extern uint32_t Actor_HasNoParent(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_HasNoParent, 0x80022D40, 0x800B8BFC);

extern void func_8002F5C4(Actor* actorA, Actor* actorB, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F5C4, 0x80022D64, 0x800B8C20);

extern void func_8002F5F0(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8002F5F0, 0x80022D94, 0x800B8C50);

extern int32_t Actor_IsMounted(struct GlobalContext* globalCtx, Actor* horse);
SYMBOL_VERSION_CONFIG(Actor_IsMounted, 0x80022DBC, 0x800B8C78);

extern uint32_t Actor_SetRideActor(struct GlobalContext* globalCtx, Actor* horse, int32_t arg2);
SYMBOL_VERSION_CONFIG(Actor_SetRideActor, 0x80022DE0, 0x800B8C9C);

extern int32_t Actor_NotMounted(struct GlobalContext* globalCtx, Actor* horse);
SYMBOL_VERSION_CONFIG(Actor_NotMounted, 0x80022E18, 0x800B8CEC);

extern void func_8002F698(struct GlobalContext* globalCtx, Actor* actor, float arg2, int16_t arg3, float arg4, uint32_t arg5, uint32_t arg6);
SYMBOL_VERSION_CONFIG(func_8002F698, 0x80022E3C, 0x800B8D10);

extern void func_8002F6D4(struct GlobalContext* globalCtx, Actor* actor, float arg2, int16_t arg3, float arg4, uint32_t arg5);
SYMBOL_VERSION_CONFIG(func_8002F6D4, 0x80022E7C, 0x800B8D50);

extern void func_8002F71C(struct GlobalContext* globalCtx, Actor* actor, float arg2, int16_t arg3, float arg4);
SYMBOL_VERSION_CONFIG(func_8002F71C, 0x80022EC4, 0x800B8D98);

extern void func_8002F758(struct GlobalContext* globalCtx, Actor* actor, float arg2, int16_t arg3, float arg4, uint32_t arg5);
SYMBOL_VERSION_CONFIG(func_8002F758, 0x80022F00, 0x800B8DD4);

extern void func_8002F7A0(struct GlobalContext* globalCtx, Actor* actor, float arg2, int16_t arg3, float arg4);
SYMBOL_VERSION_CONFIG(func_8002F7A0, 0x80022F48, 0x800B8E1C);

extern void func_8002F7DC(Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(func_8002F7DC, 0x80022F84, 0x800B8E58);

extern void Audio_PlayActorSound2(Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(Audio_PlayActorSound2, 0x80022FD0, 0x800B8EC8);

extern void func_8002F850(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(func_8002F850, 0x80022FFC, 0x800B8EF4);

extern void func_8002F8F0(Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(func_8002F8F0, 0x800230A0, 0x800B8F98);

extern void func_8002F91C(Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(func_8002F91C, 0x800230D4, 0x800B8FC0);

extern void func_8002F948(Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(func_8002F948, 0x80023108, 0x800B8FE8);

extern void func_8002F974(Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(func_8002F974, 0x8002313C, 0x800B9010);

extern void func_8002F994(Actor* actor, int32_t arg1);
SYMBOL_VERSION_CONFIG(func_8002F994, 0x80023164, 0x800B9038);

//extern ? func_800B9084();
//SYMBOL_VERSION_CONFIG(func_800B9084, 0x80000180, 0x800B9084);

//extern ? func_800B9098();
//SYMBOL_VERSION_CONFIG(func_800B9098, 0x80000180, 0x800B9098);

extern int32_t func_8002F9EC(struct GlobalContext* globalCtx, Actor* actor, CollisionPoly* poly, int32_t bgId, Vec3f* pos);
SYMBOL_VERSION_CONFIG(func_8002F9EC, 0x800231BC, 0x800B90AC);

extern void func_8002FA60(struct GlobalContext* globalCtx) ;
SYMBOL_VERSION_CONFIG(func_8002FA60, 0x80023234, 0x80000180);

extern void Actor_DrawFaroresWindPointer(GlobalContext* globalCtx);
//SYMBOL_VERSION_CONFIG(Actor_DrawFaroresWindPointer, 0x80023384, 0x80000180);

extern void func_80030488(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_80030488, 0x80023BC8, 0x80000180);

extern void func_800304B0(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_800304B0, 0x80023BF0, 0x800B90F4);

//extern ? func_800B9120();
//SYMBOL_VERSION_CONFIG(func_800B9120, 0x80000180, 0x800B9120);

extern void func_800304DC(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, struct ActorEntry* actorEntry);
SYMBOL_VERSION_CONFIG(func_800304DC, 0x80023C1C, 0x800B9170);

//extern ? func_800B9334();
//SYMBOL_VERSION_CONFIG(func_800B9334, 0x80000180, 0x800B9334);

//extern ? func_800B948C();
//SYMBOL_VERSION_CONFIG(func_800B948C, 0x80000180, 0x800B948C);

extern void Actor_UpdateAll(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(Actor_UpdateAll, 0x80023D70, 0x800B9780);

extern void Actor_FaultPrint(Actor* actor, char* command);
SYMBOL_VERSION_CONFIG(Actor_FaultPrint, 0x8002420C, 0x80000180);

extern void Actor_Draw(struct GlobalContext* globalCtx, int32_t arg1, int32_t arg2);
SYMBOL_VERSION_CONFIG(Actor_Draw, 0x80024280, 0x800B9A04);

extern void func_80030ED8(Actor* actor);
SYMBOL_VERSION_CONFIG(func_80030ED8, 0x80024540, 0x800B9D1C);

//extern ? func_800B9E3C();
//SYMBOL_VERSION_CONFIG(func_800B9E3C, 0x80000180, 0x800B9E3C);

//extern ? func_800B9E4C();
//SYMBOL_VERSION_CONFIG(func_800B9E4C, 0x80000180, 0x800B9E4C);

extern void func_80030FA8(GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_80030FA8, 0x80024610, 0x800B9E84);

extern void func_8003115C(struct GlobalContext* globalCtx, int32_t numInvisibleActors, Actor** invisibleActors);
SYMBOL_VERSION_CONFIG(func_8003115C, 0x80024784, 0x800B9EF4);

extern int32_t func_800314B0(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(func_800314B0, 0x800249B8, 0x800BA2D8);

extern int32_t func_800314D4(struct GlobalContext* globalCtx, Actor* actorB, Vec3f* arg2, float arg3);
SYMBOL_VERSION_CONFIG(func_800314D4, 0x800249DC, 0x800BA2FC);

extern void func_800315AC(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(func_800315AC, 0x80024AB4, 0x800BA42C);

extern void func_80031A28(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(func_80031A28, 0x80024CCC, 0x800BA6FC);

extern void Actor_FreezeAllEnemies(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, s32 duration);
SYMBOL_VERSION_CONFIG(Actor_FreezeAllEnemies, 0x80024D68, 0x800BA798);

extern void func_80031B14(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(func_80031B14, 0x80024DB8, 0x800BA8B8);

extern void func_80031C3C(struct ActorContext* actorCtx, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_80031C3C, 0x80024EE0, 0x800BA9B4);

extern void Actor_AddToCategory(struct ActorContext* actorCtx, Actor* actorToAdd, uint8_t actorCategory);
SYMBOL_VERSION_CONFIG(Actor_AddToCategory, 0x80024F98, 0x800BAAB4);

extern Actor* Actor_RemoveFromCategory(GlobalContext* globalCtx, ActorContext* actorCtx, Actor* actorToRemove);
SYMBOL_VERSION_CONFIG(Actor_RemoveFromCategory, 0x80024FE0, 0x800BAB24);

extern void Actor_FreeOverlay(ActorOverlay* actorOverlay);
SYMBOL_VERSION_CONFIG(Actor_FreeOverlay, 0x800250AC, 0x800BABFC);

extern Actor* Actor_Spawn(struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params);
SYMBOL_VERSION_CONFIG(Actor_Spawn, 0x80025110, 0x800BAC60);

//extern ? func_800BACD4();
//SYMBOL_VERSION_CONFIG(func_800BACD4, 0x80000180, 0x800BACD4);

//extern ? func_800BAE14();
//SYMBOL_VERSION_CONFIG(func_800BAE14, 0x80000180, 0x800BAE14);

extern Actor* Actor_SpawnAsChild(struct ActorContext* actorCtx, Actor* parent, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params);
SYMBOL_VERSION_CONFIG(Actor_SpawnAsChild, 0x800253F0, 0x800BB0C0);

extern void Actor_SpawnTransitionActors(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(Actor_SpawnTransitionActors, 0x80025488, 0x800BB140);

extern Actor* Actor_SpawnEntry(struct ActorContext* actorCtx, struct ActorEntry* actorEntry, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_SpawnEntry, 0x800255C4, 0x800BB2D0);

extern Actor* Actor_Delete(struct ActorContext* actorCtx, Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_Delete, 0x80025648, 0x800BB498);

extern int32_t func_80032880(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(func_80032880, 0x8002574C, 0x800BB59C);

extern void func_800328D4(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, Player* player, uint32_t actorCategory);
SYMBOL_VERSION_CONFIG(func_800328D4, 0x800257A0, 0x800BB604);

extern Actor* func_80032AF0(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, Actor** actorPtr, Player* player);
SYMBOL_VERSION_CONFIG(func_80032AF0, 0x800259BC, 0x800BB8EC);

extern Actor* Actor_Find(struct ActorContext* actorCtx, int32_t actorId, int32_t actorCategory);
SYMBOL_VERSION_CONFIG(Actor_Find, 0x80025B0C, 0x80000180);

extern void Enemy_StartFinishingBlow(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(Enemy_StartFinishingBlow, 0x80025B4C, 0x800BBA88);

extern int16_t func_80032CB4(int16_t* arg0, int16_t arg1, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80032CB4, 0x80025B84, 0x800BBAC0);

//extern ? func_800BBB74();
//SYMBOL_VERSION_CONFIG(func_800BBB74, 0x80000180, 0x800BBB74);

extern int16_t func_80032D60(int16_t* arg0, int16_t arg1, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80032D60, 0x80025C38, 0x800BBC20);

//extern ? func_800BBCEC();
//SYMBOL_VERSION_CONFIG(func_800BBCEC, 0x80000180, 0x800BBCEC);

extern void BodyBreak_Alloc(struct BodyBreak* bodyBreak, int32_t count, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(BodyBreak_Alloc, 0x80025D04, 0x80000180);

extern void BodyBreak_SetInfo(struct BodyBreak* bodyBreak, int32_t limbIndex, int32_t minLimbIndex, int32_t maxLimbIndex, uint32_t count, Gfx** dList, int16_t objectId);
SYMBOL_VERSION_CONFIG(BodyBreak_SetInfo, 0x80025DFC, 0x80000180);

extern int32_t BodyBreak_SpawnParts(Actor* actor, struct BodyBreak* bodyBreak, struct GlobalContext* globalCtx, int16_t type);
SYMBOL_VERSION_CONFIG(BodyBreak_SpawnParts, 0x80025F04, 0x80000180);

extern void Actor_SpawnFloorDustRing(struct GlobalContext* globalCtx, Actor* actor, Vec3f* posXZ, float radius, int32_t amountMinusOne, float randAccelWeight, int16_t scale, int16_t scaleStep, uint8_t useLighting);
SYMBOL_VERSION_CONFIG(Actor_SpawnFloorDustRing, 0x800260E8, 0x800BBDAC);

extern void func_80033480(struct GlobalContext* globalCtx, Vec3f* arg1, float arg2, int32_t arg3, int16_t arg4, int16_t arg5, uint8_t arg6);
SYMBOL_VERSION_CONFIG(func_80033480, 0x80026308, 0x800BBFB0);

extern Actor* Actor_GetCollidedExplosive(struct GlobalContext* globalCtx, Collider* collider);
SYMBOL_VERSION_CONFIG(Actor_GetCollidedExplosive, 0x800264C8, 0x80000180);

extern Actor* func_80033684(struct GlobalContext* globalCtx, Actor* explosiveActor);
SYMBOL_VERSION_CONFIG(func_80033684, 0x8002650C, 0x80000180);

extern void Actor_ChangeCategory(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, Actor* actor, uint8_t actorCategory);
SYMBOL_VERSION_CONFIG(Actor_ChangeCategory, 0x800265D4, 0x800BC154);

extern Actor* Actor_GetProjectileActor(struct GlobalContext* globalCtx, Actor* refActor, float radius);
SYMBOL_VERSION_CONFIG(Actor_GetProjectileActor, 0x80026614, 0x80000180);

extern void Actor_SetTextWithPrefix(struct GlobalContext* globalCtx, Actor* actor, int16_t textIdLower);
SYMBOL_VERSION_CONFIG(Actor_SetTextWithPrefix, 0x800267D4, 0x80000180);

//extern ? func_800BC188();
//SYMBOL_VERSION_CONFIG(func_800BC188, 0x80000180, 0x800BC188);

//extern ? func_800BC1B4();
//SYMBOL_VERSION_CONFIG(func_800BC1B4, 0x80000180, 0x800BC1B4);

//extern ? func_800BC270();
//SYMBOL_VERSION_CONFIG(func_800BC270, 0x80000180, 0x800BC270);

//extern ? func_800BC444();
//SYMBOL_VERSION_CONFIG(func_800BC444, 0x80000180, 0x800BC444);

extern int16_t Actor_TestFloorInDirection(Actor* actor, struct GlobalContext* globalCtx, float distance, int16_t angle);
SYMBOL_VERSION_CONFIG(Actor_TestFloorInDirection, 0x80026850, 0x800BC4EC);

extern int32_t Actor_IsTargeted(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_IsTargeted, 0x8002691C, 0x800BC5B8);

extern int32_t Actor_OtherIsTargeted(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_OtherIsTargeted, 0x80026950, 0x800BC5EC);

extern float func_80033AEC(Vec3f* arg0, Vec3f* arg1, float arg2, float arg3, float arg4, float arg5);
SYMBOL_VERSION_CONFIG(func_80033AEC, 0x80026984, 0x80000180);

extern void func_80033C30(Vec3f* arg0, Vec3f* arg1, uint8_t alpha, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_80033C30, 0x80026AD0, 0x800BC620);

extern void func_80033DB8(struct GlobalContext* globalCtx, int16_t arg1, int16_t arg2);
SYMBOL_VERSION_CONFIG(func_80033DB8, 0x80026C1C, 0x800BC770);

extern void func_80033E1C(struct GlobalContext* globalCtx, int16_t arg1, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80033E1C, 0x80026C84, 0x800BC7D8);

extern void func_80033E88(Actor* actor, struct GlobalContext* globalCtx, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80033E88, 0x80026CF4, 0x800BC848);

extern float Rand_ZeroFloat(float f);
SYMBOL_VERSION_CONFIG(Rand_ZeroFloat, 0x80026D64, 0x80000180);

extern float Rand_CenteredFloat(float f);
SYMBOL_VERSION_CONFIG(Rand_CenteredFloat, 0x80026D90, 0x80000180);

extern void Actor_DrawDoorLock(struct GlobalContext* globalCtx, int32_t arg1, int32_t arg2);
SYMBOL_VERSION_CONFIG(Actor_DrawDoorLock, 0x80026DC8, 0x800BC8B8);

extern void func_8003424C(struct GlobalContext* globalCtx, Vec3f* arg1);
SYMBOL_VERSION_CONFIG(func_8003424C, 0x80027070, 0x800BCB50);

extern void Actor_SetColorFilter(Actor* actor, int16_t colorFlag, int16_t colorIntensityMax, int16_t xluFlag, int16_t duration);
SYMBOL_VERSION_CONFIG(Actor_SetColorFilter, 0x80027090, 0x800BCB70);

extern Hilite* func_800342EC(Vec3f* object, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_800342EC, 0x80027114, 0x800BCBF4);

extern Hilite* func_8003435C(Vec3f* object, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(func_8003435C, 0x80027188, 0x800BCC68);

//extern ? func_800BCCDC();
//SYMBOL_VERSION_CONFIG(func_800BCCDC, 0x80000180, 0x800BCCDC);

extern int32_t func_800343CC(struct GlobalContext* globalCtx, Actor* actor, int16_t* arg2, float arg3, uint16_t (*unkFunc1)(struct GlobalContext*, Actor*), int16_t (*unkFunc2)(struct GlobalContext*, Actor*));
SYMBOL_VERSION_CONFIG(func_800343CC, 0x800271FC, 0x800BD2B4);

extern void func_800344BC(Actor* actor, struct struct_80034A14_arg1* arg1, int16_t arg2, int16_t arg3, int16_t arg4, int16_t arg5, int16_t arg6, int16_t arg7, uint8_t arg8);
SYMBOL_VERSION_CONFIG(func_800344BC, 0x800272EC, 0x800BD384);

extern int16_t func_800347E8(int16_t arg0);
SYMBOL_VERSION_CONFIG(func_800347E8, 0x80027620, 0x800BD6B8);

extern int16_t func_80034810(Actor* actor, struct struct_80034A14_arg1* arg1, float arg2, int16_t arg3, int16_t arg4);
SYMBOL_VERSION_CONFIG(func_80034810, 0x8002764C, 0x800BD6E4);

extern void func_80034A14(Actor* actor, struct struct_80034A14_arg1* arg1, int16_t arg2, int16_t arg3);
SYMBOL_VERSION_CONFIG(func_80034A14, 0x80027854, 0x800BD888);

extern Gfx* func_80034B28(GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_80034B28, 0x8002796C, 0x80000180);

extern Gfx* func_80034B54(GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(func_80034B54, 0x80027990, 0x800BD9A0);

extern void func_80034BA0(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct OverrideLimbDraw overrideLimbDraw, struct PostLimbDraw postLimbDraw, Actor* actor, int16_t alpha);
SYMBOL_VERSION_CONFIG(func_80034BA0, 0x800279CC, 0x800BD9E0);

extern void func_80034CC4(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct OverrideLimbDraw overrideLimbDraw, struct PostLimbDraw postLimbDraw, Actor* actor, int16_t alpha);
SYMBOL_VERSION_CONFIG(func_80034CC4, 0x80027AC4, 0x800BDAA0);

extern int16_t func_80034DD4(Actor* actor, struct GlobalContext* globalCtx, int16_t arg2, float arg3);
SYMBOL_VERSION_CONFIG(func_80034DD4, 0x80027BA8, 0x800BDB6C);

extern void func_80034EC0(SkelAnime* skelAnime, struct struct_80034EC0_Entry* animations, int32_t index);
SYMBOL_VERSION_CONFIG(func_80034EC0, 0x80027C98, 0x800BDC5C);

extern void func_80034F54(struct GlobalContext* globalCtx, int16_t* arg1, int16_t* arg2, int32_t arg3);
SYMBOL_VERSION_CONFIG(func_80034F54, 0x80027D30, 0x800BDCF4);

extern ActorInit* Actor_LoadOverlay(ActorContext* actorCtx, int16_t index);
SYMBOL_VERSION_CONFIG(Actor_LoadOverlay, 0, 0x800BACD4);

extern Actor* Actor_SpawnAsChildAndCutscene(ActorContext* actorCtx, struct GlobalContext* globalCtx, s16 index, f32 x, f32 y, f32 z, s16 rotX, s16 rotY, s16 rotZ, s32 params, u32 cutscene, s32 arg11, Actor* parent);
SYMBOL_VERSION_CONFIG(Actor_SpawnAsChildAndCutscene, 0, 0x800BAE14);

#endif