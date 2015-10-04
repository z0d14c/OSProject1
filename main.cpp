//Thomas Grice
//tag130230
//OS Concepts Project 1
#include <iostream>
#include "CPU.h"
#include "Memory.h"
#include <unistd.h>
using namespace std;

//flow for cpu
// fetch
// check if operand
// if so fetch operand as well
// decode
// load
// 2nd load ONLY for ind load, interrupt return,
// execute
// store
// interrupt

int main(int argc, char *argv[]) {
    //args file and timer
     pid_t pID = fork();
    int childpipe[2];
    int parentpipe[2];
    bool isRunning = true;
//    pipe(childpipe);
//    pipe(parentpipe);
    if(pID == 0){
        close (childpipe[1]); //close
        close (parentpipe[0]);
        Memory memory = Memory(argv[1]);
        while(isRunning){
            char* buff;
            int returnVal;
            read(parentpipe[2], buff, 5);
            string buff2 = string(buff);
            string val = buff2.substr(1, val.length()-1);
            switch(buff2[0]) {
                case 'r':
                    returnVal = memory.read(atoi(val));
                    break;
                case 'w':
                    char* x = strchr(const_cast<>(val), ',');
                    int index = (int)(x - val);
                    returnVal = memory.write(atoi(val));
                    break;
                case 'q':
                default:
                    isRunning = false;
                    break;
            }
//            write(parentpipe, )
        }
    } else {
        close (childpipe[0]);
        close (parentpipe[1]);
        CPU cpu = CPU(atoi(argv[2]));
        int nextAddr, valueFromMemory;
        while(cpu.isStillRunning()) {
            int intArray[4];
            nextAddr = cpu.toFetch(-1, intArray)[0];
            valueFromMemory = write(childpipe, nextAddr, 0);
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
                    write(childpipe, "r" + nextAddr, 0);
//                    param = memory.read(memory.read(nextAddr) + intArray[3]);

                } else if (intArray[2] == 2) { //triple read (for instruction 3)
                    write(childpipe, "r" + nextAddr, 0);
//                    read(childpipe, buff, )
                    write(childpipe, "r" + nextAddr, 0);
//                    param = memory.read(memory.read(memory.read(nextAddr)));
                } else { //otherwise the param is simply set on the cpu after first read, with operand (x/y/0) added
//                    param = memory.read(nextAddr);
                }
                if (intArray[2] == 3) { //store addr
//                    memory.write(param, intArray[3]);
                }
                cpu.setParam(param);
                cpu.execute(valueFromMemory);
                cpu.incPC();
            } else {
                cpu.execute(valueFromMemory);
                cpu.incPC();
            }
        }
    }

    return 0;
}
