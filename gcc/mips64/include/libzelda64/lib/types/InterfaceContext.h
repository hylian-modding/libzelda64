#ifndef INTERFACECONTEXT_TYPE_H
#define INTERFACECONTEXT_TYPE_H

#include "DmaRequest.h"
#include "InterfaceRestrictions.h"
#include "View.h"
#include "Viewport.h"
#include <inttypes.h>
#include <libultra/PR/os.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
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
    /* 0x01F8 */ int16_t fairyCalling;
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
    /* 0x022E */ int16_t magicCost;        // amount reduced
    /* 0x0230 */ int16_t magicDelta;       // amount reduced this frame
    /* 0x0232 */ int16_t counterDigits[4]; // used for key and rupee counter;
    /* 0x023A */ uint8_t carrotCounter;    // for epona "lash_ct" in the source
    /* 0x023C */ uint16_t hbaScore0;
    /* 0x023E */ uint16_t hbaAmmo;
    /* 0x0240 */ uint16_t hbaState;
    /* 0x0242 */ uint16_t hbaScore1;
    /* 0x0224 */ uint16_t fillAlpha; // screen fill alpha?
    /* 0x0246 */ uint16_t aAlpha;    // also carrots
    /* 0x0248 */ uint16_t bAlpha;    // also hba score
    /* 0x024A */ uint16_t cLeftAlpha;
    /* 0x024C */ uint16_t cDownAlpha;
    /* 0x024E */ uint16_t cRightAlpha;
    /* 0x0250 */ uint16_t healthAlpha; // also max C-Up alpha
    /* 0x0252 */ uint16_t magicAlpha;  // also Rupee and Key counters alpha
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

#else /* GAME_VERSION_1_0 */
#warning "InterfaceContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x000 */ View view;
    /* 0x168 */ struct Vtx_t* interfaceFrameVtx;
    /* 0x16C */ struct Vtx_t* heartVtx;
    /* 0x170 */ void* parameterSegment;
    /* 0x174 */ void* do_ActionSegment;
    /* 0x178 */ void* icon_itemSegment;
    /* 0x17C */ void* mapSegment;
    /* 0x180 */ uint8_t* mapPalette;
    /* 0x184 */ DmaRequest dma0;
    /* 0x1A4 */ DmaRequest dma1;
    /* 0x1C4 */ DmaRequest dma2;
    /* 0x1E4 */ OSMesgQueue loadQueue;
    /* 0x1FC */ OSMesg loadMsg;
    /* 0x200 */ Viewport viewport;
    /* 0x210 */ int16_t doActionFlag;
    /* 0x212 */ uint16_t doAction;
    /* 0x214 */ uint16_t doActionBefore;
    /* 0x218 */ float doActionRotate;
    /* 0x21C */ int16_t fairyCalling;
    /* 0x21E */ int16_t specialActionFlag;
    /* 0x220 */ int16_t specialAction;
    /* 0x222 */ int16_t heartMeter;
    /* 0x224 */ int16_t beatingMode;
    /* 0x226 */ int16_t lifeColorChange;
    /* 0x228 */ int16_t lifeColorChangeDirection;
    /* 0x22A */ int16_t beatingHeartPrim[3];
    /* 0x230 */ int16_t beatingHeartEnv[3];
    /* 0x236 */ int16_t heartsPrimR[2];
    /* 0x23A */ int16_t heartsPrimG[2];
    /* 0x23E */ int16_t heartsPrimB[2];
    /* 0x242 */ int16_t heartsEnvR[2];
    /* 0x246 */ int16_t heartsEnvG[2];
    /* 0x24A */ int16_t heartsEnvB[2];
    /* 0x24E */ int16_t heartMax;
    /* 0x250 */ int16_t heartTimer;
    /* 0x252 */ int16_t heartWait;
    /* 0x254 */ int16_t heartFlag; // 1 means shrinking, 0 growing
    /* 0x256 */ int16_t magicCost;
    /* 0x258 */ int16_t magicDelta;
    /* 0x25A */ uint8_t carrotCounter;
    /* 0x25C */ uint16_t hbaScore0;
    /* 0x25E */ uint16_t hbaAmmo;
    /* 0x260 */ uint16_t hbaState;
    /* 0x262 */ uint16_t hbaScore1;
    /* 0x264 */ uint16_t fillAlpha;
    /* 0x266 */ uint16_t aAlpha;
    /* 0x268 */ uint16_t bAlpha;
    /* 0x26A */ uint16_t cLeftAlpha;
    /* 0x26C */ uint16_t cDownAlpha;
    /* 0x26E */ uint16_t cRightAlpha;
    /* 0x270 */ uint16_t healthAlpha;
    /* 0x272 */ uint16_t magicAlpha;
    /* 0x274 */ uint16_t minimapAlpha;
    /* 0x276 */ int16_t startAlpha;
    /* 0x278 */ int16_t mapSpotNum;
    /* 0x27A */ int16_t mapDungeonNum;
    /* 0x27C */ int16_t mapRoomNum;
    /* 0x27E */ uint8_t mapPaletteNum;
    /* 0x27F */ uint8_t marathonFlag;
    /* 0x280 */ uint8_t unk_280;
    /* 0x282 */ int16_t unk_282;
    /* 0x284 */ int16_t unk_284;
    /* 0x286 */ int16_t unk_286;
    /* 0x288 */ int16_t unk_288;
    /* 0x28A */ int16_t unk_28A[8];
    /* 0x29A */ uint16_t unk_29A[8];
    /* 0x2AA */ int16_t unk_2AA[8];
    /* 0x2BC */ float unk_2BC[8];
    /* 0x2DC */ float unk_2DC[8];
    /* 0x2FC */ int16_t unk_2FC[4];
    /* 0x304 */ int16_t unk_304;
    /* 0x306 */ int16_t unk_306;
    /* 0x308 */ int16_t unk_308;
    /* 0x30A */ int16_t unk_30A;
    /* 0x30C */ int16_t unk_30C;
    struct {
        /* 0x30E */ uint8_t unk_30E; // "h_gauge"
        /* 0x30F */ uint8_t bButton;
        /* 0x310 */ uint8_t aButton;
        /* 0x311 */ uint8_t tradeItems;
        /* 0x312 */ uint8_t unk_312;
        /* 0x313 */ uint8_t unk_313;
        /* 0x314 */ uint8_t unk_314;
        /* 0x315 */ uint8_t songOfSoaring;
        /* 0x316 */ uint8_t songOfStorms;
        /* 0x317 */ uint8_t unk_317;
        /* 0x318 */ uint8_t pictographBox;
        /* 0x319 */ uint8_t all; // "another"; enables all item restrictions
    } restrictions;              // size = 0xC
    /* 0x31A */ uint8_t unk_31A;
    /* 0x31B */ uint8_t unk_31B;
    /* 0x31C */ uint8_t unk_31C;
    /* 0x320 */ OSMesgQueue unk_320;
    /* 0x338 */ OSMesg unk_338;
    /* 0x33C */ void* unk_33C;
    /* 0x340 */ uint32_t unk_340;
    /* 0x344 */ uint32_t unk_344;
} InterfaceContext; /* sizeof = 0x348 */
#endif

#endif
