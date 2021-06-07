## Commandbuffer
An easier to maintain and more managable remake of Glank's command buffer for OOTO and MMO.

### How to install
Actor_SpawnWithAddress, Actor_DestroyHook, Actor_InitHook, Actor_SpawnEntryHook, Actor_SpawnHook, Actor_SpawnTransitionActorHook, Actor_UpdateHook, and CommandBuffer_Update should be allocated and written into memory
Call to Actor_SpawnWithAddress should be patched in CommandBuffer_Update to use its new address

The call to actor->destroy call in Actor_Destroy should be replaced with a call to Actor_DestroyHook (0x80021104 in 1.0)
The call to Actor_Init call in Actor_Spawn should be replaced with a call to Actor_InitHook (0x800210D0 in 1.0)
The call to Actor_SpawnEntry in Actor_UpdateAll should be replaced with a call to Actor_SpawnEntryHook (0x80023DE8 in 1.0)
The call to Actor_Spawn in Actor_SpawnTransitionActors should be replaced with a call to Actor_SpawnTransitionActorHook (0x8002557C in 1.0)
The call to actor->update Actor_UpdateAll should be replaced with a call to Actor_UpdateHook (0x800240D8 in 1.0)
Actor_Spawn should be hijacked to call Actor_SpawnHook (0x80025110 in 1.0)
The call to gameState->main(gameState) in GameState_Update should be replaced with a call to CommandBuffer_Update (0x800A0BF8 in 1.0)



