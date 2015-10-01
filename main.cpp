#include <iostream>
#include "CPU.h"

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

int main() {
    cout << "Hello, World!" << endl;
    CPU cpu = CPU();
    return 0;
}