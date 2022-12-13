## Commandbuffer
An easier to maintain and more managable remake of Glank's command buffer made for OOTO and MMO. Can be implemented on any frontend with access to game memory.

### Building
Just run `make`.

### Defines

#### GAMESTATE_CAVE
When GAMESTATE_CAVE is defined, the command buffer will use the original method of caving the call to gamestate->main to run the command buffer. The default method was implemented to support Pvp, however may be more difficult to implement.
Append `-DGAMESTATE_CAVE` to make to enable this.

#### OLD_CE_GETNEXTCOLLISION
When OLD_CE_GETNEXTCOLLISION is defined, the CommandBuffer_CommandEvent_GetCollision will use a safer, but slower method to find the collision.
Append `-OLD_CE_GETNEXTCOLLISION` to make to enable this.

### How to install
For refernce code on how to implement this, check out [ModLoader64](https://github.com/hylian-modding/ModLoader64/blob/master/src/modloader/cores/OOT/CommandBuffer/CommandBuffer.ts).
The functions built from each file should be allocated and written into memory
Additionally, depending on the GAMESTATE_CAVE define, you either have to replace the call to `gameState->main`, or `Actor_UpdateAll` with a call to CommandBuffer_Update.
Finally, you have to do relocation on certain symbols (the addresses of allocated functions, the address of the command buffer, etc.)




