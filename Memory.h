//
// Created by Thomas on 9/28/2015.
//

#ifndef OSCONCEPTSP1_MEMORY_H
#define OSCONCEPTSP1_MEMORY_H
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

class Memory {
public:
    void Memory(string filepath);
    void write(int address, int value);
    int read(int value);
private:
    int memory[2000];
    void readFile(string filename);
};

#endif //OSCONCEPTSP1_MEMORY_H
