#include <iostream>
#include "CPU.h"
#include "Memory.h"
#include <unistd.h>
using namespace std;

//flow for cpu
// fetch
// check if operand
// if so fetch operand as wel
// decode
// load
// 2nd load ONLY for ind load, interrupt return,
// execute
// store
// interrupt

int main(int argc, char *argv[]) {
    //args file and timer/
    ///    pid_t pID = fork();
    Memory memory = Memory(argv[1]);
    CPU cpu = CPU(atoi(argv[2]));
    int nextAddr, valueFromMemory;
    while (cpu.isStillRunning()) {
        int intArray[4];
        nextAddr = cpu.toFetch(-1, intArray)[0];
        valueFromMemory = memory.read(nextAddr);
        bool decodeInfo[2];
        bool *decodePtr = decodeInfo;
        cpu.decode(valueFromMemory, decodePtr);
        if (decodeInfo[0]) { //has operand or special operation
            int shouldIncPc; //whether PC should be incremented or not (for example, to read operand)
            int param; //CPU register for certain params needed by functions
            int *intArray = cpu.toFetch(valueFromMemory, intArray);
            nextAddr = intArray[0];
            shouldIncPc = intArray[1];
            if (shouldIncPc == 1) {
                cpu.incPC();
            }
            if (intArray[2] == 1) { //double read AKA read and then read again
                param = memory.read(memory.read(nextAddr) + intArray[3]);
            } else if (intArray[2] == 2) { //triple read (for instruction 3)
                param = memory.read(memory.read(memory.read(nextAddr)));
            } else { //otherwise the param is simply set on the cpu after first read, with operand (x/y/0) added
                param = memory.read(nextAddr);
            }
            if (intArray[2] == 3) { //store addr
                memory.write(param, intArray[3]);
            }
            cpu.setParam(param);
            cpu.execute(valueFromMemory);
            cpu.incPC();
        } else {
            cpu.execute(valueFromMemory);
            cpu.incPC();
        }
    }
//    Memory memory = Memory();
    return 0;
}
