"use strict";
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
var fs = __importStar(require("fs"));
var symbolMap = "sync_sym.txt";
var syncObject = fs.readFileSync("sync.bin");
var syncEntries = [];
function parseSymbols(path) {
    var fileLines = fs.readFileSync(path).toString().split('\n');
    var dataOffsets = [];
    //console.log(fileLines);
    for (var i = 0; i < fileLines.length; i++) {
        if (fileLines[i] !== '') {
            dataOffsets.push(parseInt(fileLines[i].split('=')[1], 16));
        }
    }
    return dataOffsets;
}
;
function writeEntries(func) {
    var copyFields = "";
    switch (func) {
        case 0:
            {
                for (var i = 1; i < syncEntries.length - 1; i++) {
                    var e = syncEntries[i];
                    copyFields += "\tthis.copyFields.push('" + e.nameString + "');\n\t";
                }
            }
            break;
        case 1:
            {
                for (var i = 1; i < syncEntries.length - 1; i++) {
                    var e = syncEntries[i];
                    copyFields += "\tget " + e.nameString + "(): Buffer { return this.ModLoader.emulator.rdramReadBuffer(0x" + e.sourceAddress.toString(16).toUpperCase() + ", 0x" + e.bufferSize.toString(16).toUpperCase() + "); }\n\n";
                    copyFields += "\tset " + e.nameString + "(" + e.nameString + ": Buffer) { this.ModLoader.emulator.rdramWriteBuffer(this.pointer + 0x" + e.destinationAddress.toString(16).toUpperCase() + ", " + e.nameString + "); }\n\n";
                }
            }
            break;
    }
    return copyFields;
}
//console.log(`${process.argv}`);
// Parse Symbols and Extract Sync Data Entries
var syncSymbolData = parseSymbols(symbolMap);
if (syncObject) {
    for (var i = Number(syncSymbolData[0]); i < Number(syncSymbolData[1]); i += 16) {
        var newEntry = {
            namePointer: syncObject.readUInt32BE(i),
            sourceAddress: syncObject.readUInt32BE(i + 4),
            destinationAddress: syncObject.readUInt32BE(i + 8),
            bufferSize: syncObject.readUInt32BE(i + 12)
        };
        syncEntries.push(newEntry);
    }
    for (var i = 0; i < syncEntries.length; i++) {
        var objectName = "";
        for (var j = syncEntries[i].namePointer; syncObject[j] !== 0; j++) {
            objectName += String.fromCharCode(syncObject.readUInt8(j));
        }
        syncEntries[i].nameString = objectName;
    }
    console.log(syncEntries);
}
if (syncEntries) {
    fs.readFile("makeData/template.fts", 'utf8', function (err, data) {
        if (err) {
            return console.log(err);
        }
        var result = data.replace(/push_entries/g, "" + writeEntries(0)).replace(/fields_to_sync/g, "" + writeEntries(1));
        fs.writeFile("../PuppetData.ts", result, 'utf8', function (err) {
            if (err)
                return console.log(err);
        });
    });
    //writeEntries();
}
else {
    console.log("No Sync Entries!");
}