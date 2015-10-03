#include <iostream>
#include "CPU.h"
#include "Memory.h"

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
    //args file and timer
    cout << "Hello, World!" << endl;
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    Memory memory = Memory(argv[1]);
    CPU cpu = CPU(atoi(argv[2]));
    int nextAddr, fetched;
    while(cpu.isStillRunning()){
        nextAddr = cpu.toFetch();
        fetched = memory.read(nextAddr);
        bool decodeInfo = cpu.decode(fetched);
        cout<<"decodeInfo as follows"<<endl;
        cout<<decodeInfo<<endl;
        if(decodeInfo == true){
            cpu.incPC();
            int param = memory.read(cpu.toFetch());
            cpu.setParam(param);
            cpu.execute(fetched);
//            if(decodeInfo[2] == 1){
//
//            }
            cpu.incPC();
        } else {
            cpu.execute(fetched);
            cpu.incPC();
        }
    }
//    Memory memory = Memory();
    return 0;
}