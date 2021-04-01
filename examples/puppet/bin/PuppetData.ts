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
		this.pointer = pointer;
		this.ModLoader = ModLoader;
		this.core = core;
		this.copyFields.push('pos');
		this.copyFields.push('rot');
		this.copyFields.push('fpos');
		this.copyFields.push('xz_speed');
		this.copyFields.push('boots');
		this.copyFields.push('shield');
		this.copyFields.push('sword');
		this.copyFields.push('mask');
		this.copyFields.push('anim');
		this.copyFields.push('action_a');
		this.copyFields.push('action_b');
		this.copyFields.push('state1');
		this.copyFields.push('state2');
		this.copyFields.push('state3');
		this.copyFields.push('str');
		this.copyFields.push('ears');
	
	}

	get pos(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAA54, 0x14); }

	set pos(pos: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x24, pos); }

	get rot(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAAE4, 0x6); }

	set rot(rot: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0xB4, rot); }

	get fpos(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAA68, 0x14); }

	set fpos(fpos: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x38, fpos); }

	get xz_speed(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAA98, 0x4); }

	set xz_speed(xz_speed: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x68, xz_speed); }

	get boots(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAB6F, 0x1); }

	set boots(boots: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x397, boots); }

	get shield(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAB6E, 0x1); }

	set shield(shield: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x396, shield); }

	get sword(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAB6D, 0x1); }

	set sword(sword: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x395, sword); }

	get mask(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAB7F, 0x1); }

	set mask(mask: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x398, mask); }

	get anim(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x80600000, 0x86); }

	set anim(anim: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x2EC, anim); }

	get action_a(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAB71, 0x1); }

	set action_a(action_a: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x399, action_a); }

	get action_b(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DAB74, 0x1); }

	set action_b(action_b: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x39A, action_b); }

	get state1(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DB09C, 0x4); }

	set state1(state1: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x39C, state1); }

	get state2(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DB0A0, 0x4); }

	set state2(state2: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x3A0, state2); }

	get state3(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x801DB0B2, 0x4); }

	set state3(state3: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x3A4, state3); }

	get str(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x806FFF00, 0x1); }

	set str(str: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x394, str); }

	get ears(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x803AF180, 0xC); }

	set ears(ears: Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x3A8, ears); }



toJSON() {
		const jsonObj: any = {};
		for (let i = 0; i < this.copyFields.length; i++) {
			jsonObj[this.copyFields[i]] = (this as any)[this.copyFields[i]];
		}

		return jsonObj;
	}
}
