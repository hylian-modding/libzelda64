#ifndef ACTOR_TYPE_H
#define ACTOR_TYPE_H

#include "../zelda64_version.h"
#include "ActorFunc.h"
#include "ActorShape.h"
#include "CollisionCheckInfo.h"
#include "PosRot.h"
#include "Vec3f.h"
#include "Vec3s.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct Actor {
    /* 0x000 */ int16_t id;                        // Actor ID
    /* 0x002 */ uint8_t category;                  // Actor category. Refer to the corresponding enum for values
    /* 0x003 */ int8_t room;                       // Room number the actor is in. -1 denotes that the actor won't despawn on a room change
    /* 0x004 */ uint32_t flags;                    // Flags used for various purposes
    /* 0x008 */ PosRot home;                       // Initial position/rotation when spawned. Can be used for other purposes
    /* 0x01C */ int16_t params;                    // Configurable variable set by the actor's spawn data; original name: "args_data"
    /* 0x01E */ int8_t objBankIndex;               // Object bank index of the actor's object dependency; original name: "bank"
    /* 0x01F */ int8_t targetMode;                 // Controls how far the actor can be targeted from and how far it can stay locked on
    /* 0x020 */ uint16_t sfx;                      // SFX ID to play. Sound plays when value is set, then is cleared the following update cycle
    /* 0x024 */ PosRot world;                      // Position/rotation in the world
    /* 0x038 */ PosRot focus;                      // Target reticle focuses on this position. For player this represents head pos and rot
    /* 0x04C */ float targetArrowOffset;           // Height offset of the target arrow relative to `focus` position
    /* 0x050 */ Vec3f scale;                       // Scale of the actor in each axis
    /* 0x05C */ Vec3f velocity;                    // Velocity of the actor in each axis
    /* 0x068 */ float speedXZ;                     // How fast the actor is traveling along the XZ plane
    /* 0x06C */ float gravity;                     // Acceleration due to gravity. Value is added to Y velocity every frame
    /* 0x070 */ float minVelocityY;                // Sets the lower bounds cap on velocity along the Y axis
    /* 0x074 */ struct CollisionPoly* wallPoly;    // Wall polygon the actor is touching
    /* 0x078 */ struct CollisionPoly* floorPoly;   // Floor polygon directly below the actor
    /* 0x07C */ uint8_t wallBgId;                  // Bg ID of the wall polygon the actor is touching
    /* 0x07D */ uint8_t floorBgId;                 // Bg ID of the floor polygon directly below the actor
    /* 0x07E */ int16_t wallYaw;                   // Y rotation of the wall polygon the actor is touching
    /* 0x080 */ float floorHeight;                 // Y position of the floor polygon directly below the actor
    /* 0x084 */ float yDistToWater;                // Distance to the surface of active waterbox. Negative value means above water
    /* 0x088 */ uint16_t bgCheckFlags;             // See comments below actor struct for wip docs. TODO: macros for these flags
    /* 0x08A */ int16_t yawTowardsPlayer;          // Y rotation difference between the actor and the player
    /* 0x08C */ float xyzDistToPlayerSq;           // Squared distance between the actor and the player in the x,y,z axis
    /* 0x090 */ float xzDistToPlayer;              // Distance between the actor and the player in the XZ plane
    /* 0x094 */ float yDistToPlayer;               // Dist is negative if the actor is above the player
    /* 0x098 */ CollisionCheckInfo colChkInfo;     // Variables related to the Collision Check system
    /* 0x0B4 */ ActorShape shape;                  // Variables related to the physical shape of the actor
    /* 0x0E4 */ Vec3f projectedPos;                // Position of the actor in projected space
    /* 0x0F0 */ float projectedW;                  // w component of the projected actor position
    /* 0x0F4 */ float uncullZoneForward;           // Amount to increase the uncull zone forward by (in projected space)
    /* 0x0F8 */ float uncullZoneScale;             // Amount to increase the uncull zone scale by (in projected space)
    /* 0x0FC */ float uncullZoneDownward;          // Amount to increase uncull zone downward by (in projected space)
    /* 0x100 */ Vec3f prevPos;                     // World position from the previous update cycle
    /* 0x10C */ uint8_t isTargeted;                // Set to true if the actor is currently being targeted by the player
    /* 0x10D */ uint8_t targetPriority;            // Lower values have higher priority. Resets to 0 when player stops targeting
    /* 0x10E */ uint16_t textId;                   // Text ID to pass to link/display when interacting with the actor
    /* 0x110 */ uint16_t freezeTimer;              // Actor does not update when set. Timer decrements automatically
    /* 0x112 */ uint16_t colorFilterParams;        // Set color filter to red, blue, or white. Toggle opa or xlu
    /* 0x114 */ uint8_t colorFilterTimer;          // A non-zero value enables the color filter. Decrements automatically
    /* 0x115 */ uint8_t isDrawn;                   // Set to true if the actor is currently being drawn. Always stays false for lens actors
    /* 0x116 */ uint8_t dropFlag;                  // Configures what item is dropped by the actor from `Item_DropCollectibleRandom`
    /* 0x117 */ uint8_t naviEnemyId;               // Sets what 0600 dialog to display when talking to navi. Default 0xFF
    /* 0x118 */ struct Actor* parent;              // Usage is actor specific. Set if actor is spawned via `Actor_SpawnAsChild`
    /* 0x11C */ struct Actor* child;               // Usage is actor specific. Set if actor is spawned via `Actor_SpawnAsChild`
    /* 0x120 */ struct Actor* prev;                // Previous actor of this category
    /* 0x124 */ struct Actor* next;                // Next actor of this category
    /* 0x128 */ ActorFunc init;                    // Initialization Routine. Called by `Actor_Init` or `Actor_UpdateAll`
    /* 0x12C */ ActorFunc destroy;                 // Destruction Routine. Called by `Actor_Destroy`
    /* 0x130 */ ActorFunc update;                  // Update Routine. Called by `Actor_UpdateAll`
    /* 0x134 */ ActorFunc draw;                    // Draw Routine. Called by `Actor_Draw`
    /* 0x138 */ struct ActorOverlay* overlayEntry; // Pointer to the overlay table entry for this actor
} Actor;                                           /* sizeof = 0x13C */


#else /* GAME_VERSION_1_0 */
#warning "Actor is not defined for this game version!"

#endif
#elif defined GAME_MM /* GAME_OOT */

typedef struct Actor {
    /* 0x000 */ int16_t id;          // Actor ID
    /* 0x002 */ uint8_t category;    // Actor category. Refer to the corresponding enum for values
    /* 0x003 */ int8_t room;         // Room number the actor is in. -1 denotes that the actor won't despawn on a room change
    /* 0x004 */ uint32_t flags;      // Flags used for various purposes
    /* 0x008 */ PosRot home;         // Initial position/rotation when spawned. Can be used for other purposes
    /* 0x01C */ int16_t params;      // Configurable variable set by the actor's spawn data; original name: "args_data"
    /* 0x01E */ int8_t objBankIndex; // Object bank index of the actor's object dependency; original name: "bank"
    /* 0x01F */ int8_t targetMode;   // Controls how far the actor can be targeted from and how far it can stay locked on
    /* 0x020 */ int16_t unk20;
    /* 0x024 */ PosRot world; // Position/rotation in the world
    /* 0x038 */ int8_t cutscene;
    /* 0x039 */ int8_t unk39;
    /* 0x03C */ PosRot focus;                      // Target reticle focuses on this position. For player this represents head pos and rot
    /* 0x050 */ uint16_t sfx;                      // SFX ID to play. Sound plays when value is set, then is cleared the following update cycle
    /* 0x054 */ float targetArrowOffset;           // Height offset of the target arrow relative to `focus` position
    /* 0x058 */ Vec3f scale;                       // Scale of the actor in each axis
    /* 0x064 */ Vec3f velocity;                    // Velocity of the actor in each axis
    /* 0x070 */ float speedXZ;                     // How fast the actor is traveling along the XZ plane
    /* 0x074 */ float gravity;                     // Acceleration due to gravity. Value is added to Y velocity every frame
    /* 0x078 */ float minVelocityY;                // Sets the lower bounds cap on velocity along the Y axis
    /* 0x07C */ struct CollisionPoly* wallPoly;    // Wall polygon the actor is touching
    /* 0x080 */ struct CollisionPoly* floorPoly;   // Floor polygon directly below the actor
    /* 0x084 */ uint8_t wallBgId;                  // Bg ID of the wall polygon the actor is touching
    /* 0x085 */ uint8_t floorBgId;                 // Bg ID of the floor polygon directly below the actor
    /* 0x086 */ int16_t wallYaw;                   // Y rotation of the wall polygon the actor is touching
    /* 0x088 */ float floorHeight;                 // Y position of the floor polygon directly below the actor
    /* 0x08C */ float yDistToWater;                // Distance to the surface of active waterbox. Negative value means above water
    /* 0x090 */ uint16_t bgCheckFlags;             // See comments below actor struct for wip docs. TODO: macros for these flags
    /* 0x092 */ int16_t yawTowardsPlayer;          // Y rotation difference between the actor and the player
    /* 0x094 */ float xyzDistToPlayerSq;           // Squared distance between the actor and the player in the x,y,z axis
    /* 0x098 */ float xzDistToPlayer;              // Distance between the actor and the player in the XZ plane
    /* 0x09C */ float yDistToPlayer;               // Dist is negative if the actor is above the player
    /* 0x0A0 */ CollisionCheckInfo colChkInfo;     // Variables related to the Collision Check system
    /* 0x0BC */ ActorShape shape;                  // Variables related to the physical shape of the actor
    /* 0x0EC */ Vec3f projectedPos;                // Position of the actor in projected space
    /* 0x0F8 */ float projectedW;                  // w component of the projected actor position
    /* 0x0FC */ float uncullZoneForward;           // Amount to increase the uncull zone forward by (in projected space)
    /* 0x100 */ float uncullZoneScale;             // Amount to increase the uncull zone scale by (in projected space)
    /* 0x104 */ float uncullZoneDownward;          // Amount to increase uncull zone downward by (in projected space)
    /* 0x108 */ Vec3f prevPos;                     // World position from the previous update cycle
    /* 0x114 */ uint8_t isTargeted;                // Set to true if the actor is currently being targeted by the player
    /* 0x115 */ uint8_t targetPriority;            // Lower values have higher priority. Resets to 0 when player stops targeting
    /* 0x116 */ uint16_t textId;                   // Text ID to pass to link/display when interacting with the actor
    /* 0x118 */ uint16_t freezeTimer;              // Actor does not update when set. Timer decrements automatically
    /* 0x11A */ uint16_t colorFilterParams;        // Set color filter to red, blue, or white. Toggle opa or xlu
    /* 0x11C */ uint8_t colorFilterTimer;          // A non-zero value enables the color filter. Decrements automatically
    /* 0x11D */ uint8_t isDrawn;                   // Set to true if the actor is currently being drawn. Always stays false for lens actors
    /* 0x11E */ uint8_t dropFlag;                  // Configures what item is dropped by the actor from `Item_DropCollectibleRandom`
    /* 0x11F */ uint8_t naviEnemyId;               // Sets what 0600 dialog to display when talking to navi. Default 0xFF
    /* 0x120 */ struct Actor* parent;              // Usage is actor specific. Set if actor is spawned via `Actor_SpawnAsChild`
    /* 0x124 */ struct Actor* child;               // Usage is actor specific. Set if actor is spawned via `Actor_SpawnAsChild`
    /* 0x128 */ struct Actor* prev;                // Previous actor of this category
    /* 0x12C */ struct Actor* next;                // Next actor of this category
    /* 0x130 */ ActorFunc init;                    // Initialization Routine. Called by `Actor_Init` or `Actor_UpdateAll`
    /* 0x134 */ ActorFunc destroy;                 // Destruction Routine. Called by `Actor_Destroy`
    /* 0x138 */ ActorFunc update;                  // Update Routine. Called by `Actor_UpdateAll`
    /* 0x13C */ ActorFunc draw;                    // Draw Routine. Called by `Actor_Draw`
    /* 0x140 */ struct ActorOverlay* overlayEntry; // Pointer to the overlay table entry for this actor
} Actor;                                           /* sizeof = 0x144 */

#endif /* GAME_MM */

#endif
