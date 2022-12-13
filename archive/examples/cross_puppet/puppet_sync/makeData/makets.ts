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

function parseSymbols(path: string) {
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

function writeEntries(data: any) {
    for (let i = 1; i < syncEntries.length - 1; i++) {
        let e = syncEntries[i];
        data["lengths"][`${e.nameString}`] = e.bufferSize;
        data["sources"][`${e.nameString}`] = e.sourceAddress;
        data["destinations"][`${e.nameString}`] = e.destinationAddress;
    }
    return data;
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
        if (objectName === "sync_end") break;
    }

    let garbled: Array<number> = [];
    for (let i = 0; i < syncEntries.length; i++) {
        if (syncEntries[i].nameString === undefined || syncEntries[i].nameString === "sync_end"){
            garbled.push(i);
        }
    }
    for (let i = 0; i < garbled.length; i++){
        syncEntries.splice(garbled[i], 1);
    }
    console.log(syncEntries);
}

if (syncEntries){
    let result = writeEntries({lengths: {}, sources: {}, destinations: {}});
    fs.writeFile("../PuppetData.json", JSON.stringify(result, null, 2), 'utf8', (err) => {
        if (err) return console.log(err);
    });
} else {
    console.log("No Sync Entries!")
}