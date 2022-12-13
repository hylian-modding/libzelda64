"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    Object.defineProperty(o, k2, { enumerable: true, get: function() { return m[k]; } });
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
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
function writeEntries(data) {
    for (var i = 1; i < syncEntries.length - 1; i++) {
        var e = syncEntries[i];
        data["lengths"]["" + e.nameString] = e.bufferSize;
        data["sources"]["" + e.nameString] = e.sourceAddress;
        data["destinations"]["" + e.nameString] = e.destinationAddress;
    }
    return data;
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
    var result = writeEntries({ lengths: {}, sources: {}, destinations: {} });
    fs.writeFile("../PuppetData.json", JSON.stringify(result, null, 2), 'utf8', function (err) {
        if (err)
            return console.log(err);
    });
}
else {
    console.log("No Sync Entries!");
}
