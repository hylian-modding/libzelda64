#ifndef INTERFACECONTEXT_TYPE_H
#define INTERFACECONTEXT_TYPE_H

#include "View.h"
#include "DmaRequest.h"
#include "Viewport.h"
#include "InterfaceRestrictions.h"
#include <libultra/PR/os.h>
#include <inttypes.h>

typedef struct InterfaceContext {
    /* 0x0000 */ View view;
    /* 0x0128 */ struct Vtx_t* interfaceFrameVtx;
    /* 0x012C */ struct Vtx_t* heartVtx;
    /* 0x0130 */ void* parameterSegment;
    /* 0x0134 */ void* do_ActionSegment;
    /* 0x0138 */ void* icon_itemSegment;
    /* 0x013C */ void* mapSegment;
    /* 0x0140 */ int8_t mapPalette[32];
    /* 0x0160 */ DmaRequest dma0;
    /* 0x0180 */ DmaRequest dma1;
    /* 0x01A0 */ DmaRequest dma2;
    /* 0x01C0 */ OSMesgQueue loadQueue;
    /* 0x01D8 */ OSMesg loadMsg;
    /* 0x01DC */ Viewport viewport;
    /* 0x01EC */ int16_t doActionFlag;
    /* 0x01EE */ uint16_t doAction;
    /* 0x01F0 */ uint16_t doActionBefore;
    /* 0x01F4 */ float doActionRotate;
    /* 0x01F8 */ int16_t naviCalling;
    /* 0x01FA */ int16_t specialActionFlag; // special meaning B button
    /* 0x01FC */ int16_t specialAction;
    /* 0x01FE */ int16_t heartMeter;
    /* 0x0200 */ int16_t beatingMode;
    /* 0x0202 */ int16_t beatingHeartPrim[3];
    /* 0x0208 */ int16_t beatingHeartEnv[3];
    /* 0x020E */ int16_t heartsPrimR[2];
    /* 0x0212 */ int16_t heartsPrimG[2];
    /* 0x0216 */ int16_t heartsPrimB[2];
    /* 0x021A */ int16_t heartsEnvR[2];
    /* 0x021E */ int16_t heartsEnvG[2];
    /* 0x0222 */ int16_t heartsEnvB[2];
    /* 0x0226 */ int16_t heartMax;
    /* 0x0228 */ int16_t heartTimer;
    /* 0x022A */ int16_t heartWait;
    /* 0x022C */ int16_t heartFlag;
    /* 0x022E */ int16_t magicCost; // amount reduced
    /* 0x0230 */ int16_t magicDelta; // amount reduced this frame
    /* 0x0232 */ int16_t counterDigits[4]; // used for key and rupee counter;
    /* 0x023A */ uint8_t carrotCounter; // for epona "lash_ct" in the source
    /* 0x023C */ uint16_t hbaScore0;
    /* 0x023E */ uint16_t hbaAmmo;
    /* 0x0240 */ uint16_t hbaState;
    /* 0x0242 */ uint16_t hbaScore1;
    /* 0x0224 */ uint16_t fillAlpha; // screen fill alpha?
    /* 0x0246 */ uint16_t aAlpha; // also carrots
    /* 0x0248 */ uint16_t bAlpha; // also hba score
    /* 0x024A */ uint16_t cLeftAlpha;
    /* 0x024C */ uint16_t cDownAlpha;
    /* 0x024E */ uint16_t cRightAlpha;
    /* 0x0250 */ uint16_t healthAlpha; // also max C-Up alpha
    /* 0x0252 */ uint16_t magicAlpha; // also Rupee and Key counters alpha
    /* 0x0254 */ uint16_t minimapAlpha;
    /* 0x0256 */ int16_t startAlpha;
    /* 0x0258 */ int16_t mapSpotNum;
    /* 0x025A */ int16_t mapDungeonNum;
    /* 0x025C */ int16_t mapRoomNum;
    /* 0x025E */ int16_t mapPaletteNum;
    /* 0x0260 */ uint8_t rodEquipped; // fishing rod equipped
    /* 0x0261 */ uint8_t marathonFlag;
    /* 0x0262 */ InterfaceRestrictions restrictions;
} InterfaceContext; /* sizeof = 0x270 */

#endif

