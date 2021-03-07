#ifndef CAMERA_TYPE_H
#define CAMERA_TYPE_H

#include "Vec3f.h"
#include "PosRot.h"
#include "Vec3s.h"
#include <inttypes.h>

// TODO: Add camera params (as union) from decomp!

typedef struct Camera {
    /* 0x000 */ char paramData[0x50];
    /* 0x050 */ Vec3f at;
    /* 0x05C */ Vec3f eye;
    /* 0x068 */ Vec3f up;
    /* 0x074 */ Vec3f eyeNext;
    /* 0x080 */ Vec3f skyboxOffset;
    /* 0x08C */ struct GlobalContext* globalCtx;
    /* 0x090 */ struct Player* player;
    /* 0x094 */ PosRot playerPosRot;
    /* 0x0A8 */ struct Actor* target;
    /* 0x0AC */ PosRot targetPosRot;
    /* 0x0C0 */ float rUpdateRateInv;
    /* 0x0C4 */ float pitchUpdateRateInv;
    /* 0x0C8 */ float yawUpdateRateInv;
    /* 0x0CC */ float xzOffsetUpdateRateInv;
    /* 0x0D0 */ float yOffsetUpdateRateInv;
    /* 0x0D4 */ float fovUpdateRate;
    /* 0x0D8 */ float xzSpeed;
    /* 0x0DC */ float dist;
    /* 0x0E0 */ float speedRatio;
    /* 0x0E4 */ Vec3f posOffset;
    /* 0x0F0 */ Vec3f playerPosDelta;
    /* 0x0FC */ float fov;
    /* 0x100 */ float atLERPStepScale;
    /* 0x104 */ float playerGroundY;
    /* 0x108 */ Vec3f floorNorm;
    /* 0x114 */ float waterYPos;
    /* 0x118 */ int32_t waterPrevCamIdx; // Decomp is WRONG about these!
    /* 0x11C */ int32_t waterPrevCamSetting;
    /* 0x120 */ int32_t waterQuakeId;
    /* 0x124 */ void* data0;
    /* 0x128 */ void* data1;
    /* 0x12C */ int16_t data2;
    /* 0x12E */ int16_t data3;
    /* 0x130 */ int16_t uid;
    /* 0x132 */ int16_t dummy;
    /* 0x134 */ Vec3s inputDir;
    /* 0x13A */ Vec3s camDir;
    /* 0x140 */ int16_t status;
    /* 0x142 */ int16_t setting;
    /* 0x144 */ int16_t mode;
    /* 0x146 */ int16_t bgCheckId;
    /* 0x148 */ int16_t camDataIdx;
    /* 0x14A */ int16_t changeFlag;
    /* 0x14C */ int16_t idFlag;
    /* 0x14E */ int16_t childCamIdx;
    /* 0x150 */ int16_t curTimer; // Should be timer, but conflicts with wrongly named decomp memebr!
    /* 0x152 */ int16_t stretch;
    /* 0x154 */ int16_t prevSetting;
    /* 0x156 */ int16_t nextCamDataIdx;
    /* 0x158 */ int16_t nextBGCheckId;
    /* 0x15A */ int16_t roll;
    /* 0x15C */ int16_t paramFlags;
    /* 0x15E */ int16_t animState;
    /* 0x160 */ int16_t timer; // Should be childTimer!
    /* 0x162 */ int16_t parentCamIdx;
    /* 0x164 */ int16_t thisIdx;
    /* 0x166 */ int16_t prevCamDataIdx;
    /* 0x168 */ int16_t prevId;
    /* 0x16A */ int16_t opDemo;
} Camera; /* sizeof = 0x16C */


// Defines and enums

#define CAM_STAT_CUT        0
#define CAM_STAT_WAIT       1
#define CAM_STAT_UNK3       3
#define CAM_STAT_ACTIVE     7
#define CAM_STAT_UNK100     0x100

typedef enum {
    /* 0x00 */ CAM_SET_NONE,
    /* 0x01 */ CAM_SET_NORMAL0,
    /* 0x02 */ CAM_SET_NORMAL1,
    /* 0x03 */ CAM_SET_DUNGEON0,
    /* 0x04 */ CAM_SET_DUNGEON1,
    /* 0x05 */ CAM_SET_NORMAL3,
    /* 0x06 */ CAM_SET_HORSE0,
    /* 0x07 */ CAM_SET_BOSS_GOMA,
    /* 0x08 */ CAM_SET_BOSS_DODO,
    /* 0x09 */ CAM_SET_BOSS_BARI,
    /* 0x0A */ CAM_SET_BOSS_FGANON,
    /* 0x0B */ CAM_SET_BOSS_BAL,
    /* 0x0C */ CAM_SET_BOSS_SHADES,
    /* 0x0D */ CAM_SET_BOSS_MOFA,
    /* 0x0E */ CAM_SET_TWIN0,
    /* 0x0F */ CAM_SET_TWIN1,
    /* 0x10 */ CAM_SET_BOSS_GANON1,
    /* 0x11 */ CAM_SET_BOSS_GANON2,
    /* 0x12 */ CAM_SET_TOWER0,
    /* 0x13 */ CAM_SET_TOWER1,
    /* 0x14 */ CAM_SET_FIXED0,
    /* 0x15 */ CAM_SET_FIXED1,
    /* 0x16 */ CAM_SET_CIRCLE0,
    /* 0x17 */ CAM_SET_CIRCLE2,
    /* 0x18 */ CAM_SET_CIRCLE3,
    /* 0x19 */ CAM_SET_PREREND0,
    /* 0x1A */ CAM_SET_PREREND1,
    /* 0x1B */ CAM_SET_PREREND3,
    /* 0x1C */ CAM_SET_DOOR0,
    /* 0x1D */ CAM_SET_DOORC,
    /* 0x1E */ CAM_SET_RAIL3,
    /* 0x1F */ CAM_SET_START0,
    /* 0x20 */ CAM_SET_START1,
    /* 0x21 */ CAM_SET_FREE0,
    /* 0x22 */ CAM_SET_FREE2,
    /* 0x23 */ CAM_SET_CIRCLE4,
    /* 0x24 */ CAM_SET_CIRCLE5,
    /* 0x25 */ CAM_SET_DEMO0,
    /* 0x26 */ CAM_SET_DEMO1,
    /* 0x27 */ CAM_SET_MORI1,
    /* 0x28 */ CAM_SET_ITEM0,
    /* 0x29 */ CAM_SET_ITEM1,
    /* 0x2A */ CAM_SET_DEMO3,
    /* 0x2B */ CAM_SET_DEMO4,
    /* 0x2C */ CAM_SET_UFOBEAN,
    /* 0x2D */ CAM_SET_LIFTBEAN,
    /* 0x2E */ CAM_SET_SCENE0,
    /* 0x2F */ CAM_SET_SCENE1,
    /* 0x30 */ CAM_SET_HIDAN1,
    /* 0x31 */ CAM_SET_HIDAN2,
    /* 0x32 */ CAM_SET_MORI2,
    /* 0x33 */ CAM_SET_MORI3,
    /* 0x34 */ CAM_SET_TAKO,
    /* 0x35 */ CAM_SET_SPOT05A,
    /* 0x36 */ CAM_SET_SPOT05B,
    /* 0x37 */ CAM_SET_HIDAN3,
    /* 0x38 */ CAM_SET_ITEM2,
    /* 0x39 */ CAM_SET_CIRCLE6,
    /* 0x3A */ CAM_SET_NORMAL2,
    /* 0x3B */ CAM_SET_FISHING,
    /* 0x3C */ CAM_SET_DEMOC,
    /* 0x3D */ CAM_SET_UO_FIBER,
    /* 0x3E */ CAM_SET_DUNGEON2,
    /* 0x3F */ CAM_SET_TEPPEN,
    /* 0x40 */ CAM_SET_CIRCLE7,
    /* 0x41 */ CAM_SET_NORMAL4,
    /* 0x42 */ CAM_SET_MAX
} CameraSettingType;

typedef enum {
    /* 0x00 */ CAM_MODE_NORMAL,
    /* 0x01 */ CAM_MODE_TARGET, // Original: CAM_MODE_PARALLEL
    /* 0x02 */ CAM_MODE_FOLLOWTARGET, // Original: CAM_MODE_KEEPON
    /* 0x03 */ CAM_MODE_TALK,
    /* 0x04 */ CAM_MODE_BATTLE,
    /* 0x05 */ CAM_MODE_CLIMB,
    /* 0x06 */ CAM_MODE_FIRSTPERSON,  // Original: CAM_MODE_SUBJECT
    /* 0x07 */ CAM_MODE_BOWARROW,
    /* 0x08 */ CAM_MODE_BOWARROWZ,
    /* 0x09 */ CAM_MODE_FOOKSHOT,
    /* 0x0A */ CAM_MODE_BOOMERANG,
    /* 0x0B */ CAM_MODE_SLINGSHOT, // Original: CasdfsAM_MODE_PACHINCO
    /* 0x0C */ CAM_MODE_CLIMBZ,
    /* 0x0D */ CAM_MODE_JUMP,
    /* 0x0E */ CAM_MODE_HANG,
    /* 0x0F */ CAM_MODE_HANGZ,
    /* 0x10 */ CAM_MODE_FREEFALL,
    /* 0x11 */ CAM_MODE_CHARGE,
    /* 0x12 */ CAM_MODE_STILL,
    /* 0x13 */ CAM_MODE_PUSHPULL,
    /* 0x14 */ CAM_MODE_BOOMFOLLLOW, // Original: CAM_MODE_BOOKEEPON
    /* 0x15 */ CAM_MODE_MAX
} CameraModeType;

typedef enum {
    /* 0x00 */ CAM_FUNC_NONE,
    /* 0x01 */ CAM_FUNC_NORM0,
    /* 0x02 */ CAM_FUNC_NORM1,
    /* 0x03 */ CAM_FUNC_NORM2,
    /* 0x04 */ CAM_FUNC_NORM3,
    /* 0x05 */ CAM_FUNC_NORM4,
    /* 0x06 */ CAM_FUNC_PARA0,
    /* 0x07 */ CAM_FUNC_PARA1,
    /* 0x08 */ CAM_FUNC_PARA2,
    /* 0x09 */ CAM_FUNC_PARA3,
    /* 0x0A */ CAM_FUNC_PARA4,
    /* 0x0B */ CAM_FUNC_KEEP0,
    /* 0x0C */ CAM_FUNC_KEEP1,
    /* 0x0D */ CAM_FUNC_KEEP2,
    /* 0x0E */ CAM_FUNC_KEEP3,
    /* 0x0F */ CAM_FUNC_KEEP4,
    /* 0x10 */ CAM_FUNC_SUBJ0,
    /* 0x11 */ CAM_FUNC_SUBJ1,
    /* 0x12 */ CAM_FUNC_SUBJ2,
    /* 0x13 */ CAM_FUNC_SUBJ3,
    /* 0x14 */ CAM_FUNC_SUBJ4,
    /* 0x15 */ CAM_FUNC_JUMP0,
    /* 0x16 */ CAM_FUNC_JUMP1,
    /* 0x17 */ CAM_FUNC_JUMP2,
    /* 0x18 */ CAM_FUNC_JUMP3,
    /* 0x19 */ CAM_FUNC_JUMP4,
    /* 0x1A */ CAM_FUNC_BATT0,
    /* 0x1B */ CAM_FUNC_BATT1,
    /* 0x1C */ CAM_FUNC_BATT2,
    /* 0x1D */ CAM_FUNC_BATT3,
    /* 0x1E */ CAM_FUNC_BATT4,
    /* 0x1F */ CAM_FUNC_FIXD0,
    /* 0x20 */ CAM_FUNC_FIXD1,
    /* 0x21 */ CAM_FUNC_FIXD2,
    /* 0x22 */ CAM_FUNC_FIXD3,
    /* 0x23 */ CAM_FUNC_FIXD4,
    /* 0x24 */ CAM_FUNC_DATA0,
    /* 0x25 */ CAM_FUNC_DATA1,
    /* 0x26 */ CAM_FUNC_DATA2,
    /* 0x27 */ CAM_FUNC_DATA3,
    /* 0x28 */ CAM_FUNC_DATA4,
    /* 0x29 */ CAM_FUNC_UNIQ0,
    /* 0x2A */ CAM_FUNC_UNIQ1,
    /* 0x2B */ CAM_FUNC_UNIQ2,
    /* 0x2C */ CAM_FUNC_UNIQ3,
    /* 0x2D */ CAM_FUNC_UNIQ4,
    /* 0x2E */ CAM_FUNC_UNIQ5,
    /* 0x2F */ CAM_FUNC_UNIQ6,
    /* 0x30 */ CAM_FUNC_UNIQ7,
    /* 0x31 */ CAM_FUNC_UNIQ8,
    /* 0x32 */ CAM_FUNC_UNIQ9,
    /* 0x33 */ CAM_FUNC_DEMO0,
    /* 0x34 */ CAM_FUNC_DEMO1,
    /* 0x35 */ CAM_FUNC_DEMO2,
    /* 0x36 */ CAM_FUNC_DEMO3,
    /* 0x37 */ CAM_FUNC_DEMO4,
    /* 0x38 */ CAM_FUNC_DEMO5,
    /* 0x39 */ CAM_FUNC_DEMO6,
    /* 0x3A */ CAM_FUNC_DEMO7,
    /* 0x3B */ CAM_FUNC_DEMO8,
    /* 0x3C */ CAM_FUNC_DEMO9,
    /* 0x3D */ CAM_FUNC_SPEC0,
    /* 0x3E */ CAM_FUNC_SPEC1,
    /* 0x3F */ CAM_FUNC_SPEC2,
    /* 0x40 */ CAM_FUNC_SPEC3,
    /* 0x41 */ CAM_FUNC_SPEC4,
    /* 0x42 */ CAM_FUNC_SPEC5,
    /* 0x43 */ CAM_FUNC_SPEC6,
    /* 0x44 */ CAM_FUNC_SPEC7,
    /* 0x45 */ CAM_FUNC_SPEC8,
    /* 0x46 */ CAM_FUNC_SPEC9,
    /* 0x47 */ CAM_FUNC_MAX
} CameraFuncType;


#endif

