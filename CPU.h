//
// Created by Thomas on 9/28/2015.
//

#ifndef OSCONCEPTSP1_CPU_H
#define OSCONCEPTSP1_CPU_H
#include <iostream>
#include <iomanip>
using namespace std;

class CPU {
public:
    CPU(void);
private:
    int PC, SP, IR, AC, X, Y;
};


#endif //OSCONCEPTSP1_CPU_H
