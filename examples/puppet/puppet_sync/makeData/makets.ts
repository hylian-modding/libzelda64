import * as fs from 'fs';

interface ISyncEntry {
    namePointer: number;
    sourceAddress: number;
    destinationAddress: number;
    bufferSize: number;
    nameString?: string;
}

let symbolMap: string = "sync_sym.txt"
let syncObject: Buffer = fs.readFileSync("sync.bin");
let syncEntries: Array<ISyncEntry> = [];

function parseSymbols(path) {
    let fileLines: Array<string> = fs.readFileSync(path).toString().split('\n');
    let dataOffsets: Array<number> = [];
    //console.log(fileLines);

    for (let i = 0; i < fileLines.length; i++) {
        if (fileLines[i] !== '') {
            dataOffsets.push(parseInt(fileLines[i].split('=')[1], 16));
        }
    }

    return dataOffsets;
};

function writeEntries(func: number) {
    let copyFields = "";
    switch (func) {
        case 0: {
            for (let i = 1; i < syncEntries.length - 1; i++) {
                let e = syncEntries[i];
                copyFields += `\tthis.copyFields.push('${e.nameString}');\n\t`;
            }
        } break;
        case 1: {
            for (let i = 1; i < syncEntries.length - 1; i++) {
                let e = syncEntries[i];
                copyFields += `\tget ${e.nameString}(): Buffer { return this.ModLoader.emulator.rdReadBuffer(0x${e.sourceAddress.toString(16).toUpperCase()}, 0x${e.bufferSize.toString(16).toUpperCase()}); }\n\n`;
                copyFields += `\tset ${e.nameString}(${e.nameString}: Buffer) { this.ModLoader.emulator.rdWriteBuffer(this.pointer + 0x${e.destinationAddress.toString(16).toUpperCase()}, ${e.nameString}); }\n\n`;
            }
        } break;
    }
    return copyFields;
}

//console.log(`${process.argv}`);

// Parse Symbols and Extract Sync Data Entries
let syncSymbolData: Array<number> = parseSymbols(symbolMap);
if (syncObject) {
    for (let i = Number(syncSymbolData[0]); i < Number(syncSymbolData[1]); i += 16) {
        let newEntry: ISyncEntry = {
            namePointer: syncObject.readUInt32BE(i),
            sourceAddress: syncObject.readUInt32BE(i+4),
            destinationAddress: syncObject.readUInt32BE(i+8),
            bufferSize: syncObject.readUInt32BE(i+12)
        };
        syncEntries.push(newEntry);
    }

    for (let i = 0; i < syncEntries.length; i++) {
        let objectName: string = "";
        for (let j = syncEntries[i].namePointer; syncObject[j] !== 0; j++) {
            objectName += String.fromCharCode(syncObject.readUInt8(j));
        }
        syncEntries[i].nameString = objectName;
    }

    console.log(syncEntries);
}

if (syncEntries){
    fs.readFile("/home/nick/Zelda/libzelda64/examples/puppet/puppet_sync/makeData/template.ts", 'utf8', (err, data) => {
        if (err) {
            return console.log(err);
        }
        let result = data.replace(/push_entries/g, `${writeEntries(0)}`).replace(/fields_to_sync/g, `${writeEntries(1)}`);

        fs.writeFile("../PuppetData.ts", result, 'utf8', (err) => {
            if (err) return console.log(err);
        });
    });
    //writeEntries();
} else {
    console.log("No Sync Entries!")
}