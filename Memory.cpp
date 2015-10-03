//
// Created by Thomas on 9/28/2015.
//

#include "Memory.h"
#include <typeinfo>

Memory::Memory(string filepath) {
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
                output = grabValue(output);
                stringstream ss(output);
                if(ss >> x) {
                    memory[index++] = x;
                }
            }
        }
        filestream.close();
    }
}


//grab numbers in string, not comment or whitespace
string Memory::grabValue(string line){
    int strBegin = line.find_first_not_of(" ");
    string strVal = "";
    for(int i = strBegin; i < line.length(); i++){
        if(isdigit(line[i])){
            strVal += line[i];
        } else {
            break;
        }
    }
    //debug cout if needed
//    cout<<"strVal is "<<strVal<<endl;
    return strVal;
}

