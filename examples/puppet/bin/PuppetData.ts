import { Age, Shield, Sword, Strength, IOOTCore, } from 'modloader64_api/OOT/OOTAPI';
import { IModLoaderAPI } from 'modloader64_api/IModLoaderAPI';
import { ACTOR_T_PADDING } from './PuppetOverlord';
import { bus } from 'modloader64_api/EventHandler';
import { Z64OnlineEvents, RemoteSoundPlayRequest } from '@OotOnline/Z64API/OotoAPI';

export class PuppetData {
	pointer: number;
	ModLoader: IModLoaderAPI;
	core: IOOTCore;

private readonly copyFields: string[] = new Array<string>();

	constructor(pointer: number, ModLoader: IModLoaderAPI, core: IOOTCore) {
		this.copyFields.push('world_pos');
		this.copyFields.push('focus_pos');
	
	}

	get world_pos(): Buffer { return this.ModLoader.emulator.rdReadBuffer(0x801DAA54, 0x14); }

	set world_pos(world_pos: Buffer) { this.ModLoader.emulator.rdWriteBuffer(this.pointer + 0x24, world_pos); }

	get focus_pos(): Buffer { return this.ModLoader.emulator.rdReadBuffer(0x801DAA68, 0x14); }

	set focus_pos(focus_pos: Buffer) { this.ModLoader.emulator.rdWriteBuffer(this.pointer + 0x38, focus_pos); }



toJSON() {
		const jsonObj: any = {};
		for (let i = 0; i < this.copyFields.length; i++) {
			jsonObj[this.copyFields[i]] = (this as any)[this.copyFields[i]];
		}

		return jsonObj;
	}
}
