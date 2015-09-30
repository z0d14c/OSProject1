//
// Created by Thomas on 9/28/2015.
//

#include "Memory.h"

void Memory::Memory(string filepath) {
    cout << "reading file into memory" << endl;
    readFile(filepath);
}

//cpu read from memory
int Memory::read(int address) {
    return memory[address];
}

//cpu write to memory
void Memory::write(int address, int value) {
    memory[address] = value;
    return;
}

//reads file from path and places in character array
void Memory::readFile(string filepath) {
    int index = 0;
    ifstream filestream;
    filestream.open(filepath);
    if (filestream.is_open()) {
        string output;
        while (getline(filestream, output)) {
            int x;
            if (output[0] == '.') {
                output.erase(0, 1);
                stringstream ss(output);
                if(ss >> x)
                    index = x;
            } else {
                stringstream ss(output);
                if(ss >> x)
                    memory[index++] = x;
            }
        }
        filestream.close();
    }
}

