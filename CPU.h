//
// Created by Thomas on 9/28/2015.
//

#ifndef OSCONCEPTSP1_CPU_H
#define OSCONCEPTSP1_CPU_H
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

class CPU {
public:
    CPU(int time);
    bool decode(int code);
    void execute(int code);
    int toFetch();
    void setParam(int parameter);
    void incPC();
    void decPC();
    bool isStillRunning();
private:
    //program counter, stack pointer, instruction register, accumulator, regs x and y
    int PC, SP, IR, AC, X, Y;
    int param;
    bool isRunning = true;
    int timeCounter;
    void Get(); //8
    void PutPort(); //9
    void AddX(); //10
    void AddY(); //11
    void CopyToX(); //14
    void CopyToY(); //16
    void End(); //50
};


#endif //OSCONCEPTSP1_CPU_H
