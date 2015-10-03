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
#include <cstdlib>
using namespace std;

class Memory {
public:
    Memory(string filepath);
    void write(int address, int value);
    int read(int value);
private:
    int memory[2000];
    int userStack = 999;
    int systemStack = 1999;
    void readFile(string filename);
    string grabValue(string line);
};

#endif //OSCONCEPTSP1_MEMORY_H
