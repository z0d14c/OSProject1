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

    bool decode(int code, bool *decodeInfo);

    void execute(int code);

    int *toFetch(int code, int *intPtr);

    void setParam(int parameter);

    void incPC();

    void decPC();

    bool isStillRunning();

    int StoreAddr(); //7

private:
    //program counter, stack pointer, instruction register, accumulator, regs x and y
    int PC, SP, IR, AC, X, Y;
    int param;
    bool isRunning = true;
    int timeCounter;

    void LoadValue(); //1
    void LoadAddr(); //2
    void LoadIndAddr(); //3
    void LoadIdxXAddr(); //4
    void LoadIdxYAddr(); //5
    void LoadSpX(); //6
    void Get(); //8
    void PutPort(); //9
    void AddX(); //10
    void AddY(); //11
    void SubX(); //12
    void SubY(); //13
    void CopyToX(); //14
    void CopyFromX(); //15
    void CopyToY(); //16
    void CopyFromY(); //17
    void CopyToSp(); //18
    void CopyFromSp(); //19
    void JumpAddr(); //20
    void JumpIfEqual(); //21
    void JumpIfNotEqual(); //22
    void CallAddr(); //23
    void Ret(); //24
    void IncX(); //25
    void DecX(); //26
    void Push(); //27
    void Pop(); //28
    void Int(); //29
    void IRet(); //30
    void End(); //50
};


#endif //OSCONCEPTSP1_CPU_H
