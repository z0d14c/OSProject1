//
// Created by Thomas on 9/28/2015.
//

#include "Memory.h"

void Memory::Memory(string filepath) {
    cout << "reading file into memory" << endl;
    readFile(filepath);
}

int Memory::read(int address) {
    return memory[address];
}

void Memory::write(int address, int value) {
    memory[address] = value;
    return;
}

//reads file from path and places in character array
void Memory::readFile(string filepath) {
    ifstream filestream;
    filestream.open(filepath);
    char output[300];
    while (!filestream.eof()) {
        filestream >> output;
    }
    filestream.close();
    loadInstructions(output);
}

//parses file text and loads instructions 
void Memory::loadInstructions(char filetext[]) {
    char* pch;
    pch = strtok(filetext, "\n");
    while (pch != NULL) {
        pch =
    }
}