//
// Created by Thomas on 9/28/2015.
//

#include "CPU.h"

CPU::CPU(int timeCounter) {
    //Timer  = timer(timeCounter);
    srand(time(NULL));
    PC = 0;
    SP = 999;
}

/* cycle functions */
//return value [0] = where to look,
// value[1] whether to increment PC,
// value[2] whether to read again with operand (3 means store)
//value[3] added operand (for instructions that use SP, X, Y, etc)
int* CPU::toFetch(int code, int* intPtr){
    if(code == 1){
        intPtr[0] = PC + 1;
        intPtr[1] = 1;
        intPtr[2] = 0;
        intPtr[3] = 0;
    } else if(code == 2){
        intPtr[0] = PC + 1;
        intPtr[1] = 1;
        intPtr[2] = 1;
        intPtr[3] = 0;
    } else if(code == 3){
        intPtr[0] = PC + 1;
        intPtr[1] = 1;
        intPtr[2] = 1;
        intPtr[3] = 0;
    } else if (code == 4){
        intPtr[0] = (PC + 1) + X;
        intPtr[1] = 1;
        intPtr[2] = 0;
        intPtr[3] = X;
    } else if(code == 5){
        intPtr[0] = (PC + 1) + Y;
        intPtr[1] = 1;
        intPtr[2] = 0;
        intPtr[3] = Y;
    } else if (code == 6){
        intPtr[0] = SP + X;
        intPtr[1] = 0;
        intPtr[2] = 0;
        intPtr[3] = 0;
    } else if( code == 7) {
        intPtr[0] = PC + 1;
        intPtr[1] = 1;
        intPtr[2] = 3;
        intPtr[3] = AC;
    } else if (code == -1) { //regular read
        intPtr[0] = PC;
        intPtr[1] = 0;
        intPtr[2] = 0;
        intPtr[3] = 0;
    } else { //grabbing operand
        intPtr[0] = PC + 1;
        intPtr[1] = 1;
        intPtr[2] = 0;
        intPtr[3] = 0;
    }
        return intPtr;
}

void CPU::setParam(int parameter){
    param = parameter;
}

void CPU::incPC(){
    PC++;
}

void CPU::decPC(){
    PC--;
}

//takes fetched value and determines what fn it is
//as well as determining if it needs an operand
bool CPU::decode(int code, bool* decodeInfo) {
 bool hasOperand = false;
 bool needsLoad = false;
 switch(code) {
    case 1:
        hasOperand = true;
         //load value
         break;
     case 2:
         hasOperand = true;
         needsLoad = true;
         //load addr
         break;
     case 3:
         hasOperand = true;
         //load ind addr
         break;
     case 4:
         hasOperand = true;
         //lodIdxX addr
         break;
     case 5:
         hasOperand = true;
         //load idxy addr
         break;
     case 6:
         hasOperand = true;
         //load sp x
         break;
     case 7:
         hasOperand = true;
         //store addr
        break;
     case 8:
         //get
     break;
     case 9:
         hasOperand = true;
         //put port
         break;
     case 10:
         //addx
         break;
     case 11:
         //addy
         break;
     case 12:
         //subx
         break;
     case 13:
         //suby
         break;
     case 14:
         //copytox
         break;
     case 15:
         //copyfromx
         break;
     case 16:
         //copytoy
         break;
     case 17:
         //copyfromy
         break;
     case 18:
         //copy to sp
         break;
     case 19:
         //copyfromsp
         break;
     case 20:
         //jump addr
         break;
     case 21:
         //jumpifequal addr
         break;
     case 22:
         //jumpifnotequal addr
         break;
     case 23:
         //call addr
         break;
     case 24:
         //ret
         break;
     case 25:
         //incx
         break;
     case 26:
         //decx
         break;
     case 27:
         //push
         break;
     case 28:
         //pop
         break;
     case 29:
         //int
         break;
     case 30:
         //iret
         break;
     case 50:
         //end
         break;
     default:
         //default
         break;
 }
    decodeInfo[0] = hasOperand;
    decodeInfo[1] = needsLoad;
    return hasOperand;
}

void CPU::execute(int code) {
 switch(code) {
    case 1:
        LoadValue();
         //load value
         break;
     case 2:
         LoadAddr();
         //load addr
         break;
     case 3:
         LoadIndAddr();
         //load ind addr
         break;
     case 4:
         LoadIdxXAddr();
         //lodIdxX addr
         break;
     case 5:
         LoadIdxYAddr();
         //load idxy addr
         break;
     case 6:
         LoadSpX();
         //load sp x
         break;
     case 7:
         StoreAddr();
         //store addr
        break;
     case 8:
         //get
         Get();
     break;
     case 9:
         PutPort();
         //put port
         break;
     case 10:
         AddX();
         //addx
         break;
     case 11:
         AddY();
         //addy
         break;
     case 12:
         SubX();
         //subx
         break;
     case 13:
         SubY();
         //suby
         break;
     case 14:
         CopyToX();
         //copytox
         break;
     case 15:
         CopyFromX();
         //copyfromx
         break;
     case 16:
         CopyToY();
         //copytoy
         break;
     case 17:
         CopyFromY();
         //copyfromy
         break;
     case 18:
         CopyToSp();
         //copy to sp
         break;
     case 19:
         CopyFromSp();
         //copyfromsp
         break;
     case 20:
         JumpAddr();
         //jump addr
         break;
     case 21:
         JumpIfEqual();
         //jumpifequal addr
         break;
     case 22:
         JumpIfNotEqual();
         //jumpifnotequal addr
         break;
     case 23:
         CallAddr();
         //call addr
         break;
     case 24:
         Ret();
         //ret
         break;
     case 25:
         IncX();
         //incx
         break;
     case 26:
         DecX();
         //decx
         break;
     case 27:
         Push();
         //push
         break;
     case 28:
         Pop();
         //pop
         break;
     case 29:
         Int();
         //int
         break;
     case 30:
         IRet();
         //iret
         break;
     case 50:
         End();
         //end
         break;
     default:
         End();
         //default
         break;
 }
}

void CPU::LoadValue(){
    AC = param;
    //load value into AC
}

void CPU::LoadAddr(){
    //load value at address into the AC
    AC = param;
}

void CPU::LoadIndAddr(){
    //load value from addr found in given addr
    AC = param;
}

void CPU::LoadIdxXAddr() {
    AC = param;
}

void CPU::LoadIdxYAddr(){
    AC = param;
} //5
void CPU::LoadSpX(){
    AC = param;
} //6
int CPU::StoreAddr(){
    //return AC and store in addr
    return AC;
} //7

/* begin CPU instruction set functions */
void CPU::Get(){
    AC = rand() % 100 + 1;
    return;
}

void CPU::PutPort(){
    if(param == 1){
        cout<<AC<<endl;
    }else if(param == 2){
        char asciiChar = AC;
        cout<<asciiChar<<endl;
    }

}

void CPU::AddX(){
    AC = AC + X;
    return;
}

void CPU::AddY(){
    AC = AC + Y;
    return;
}

void CPU::SubX(){
    AC = AC - X;
}

void CPU::SubY(){
    AC = AC - Y;
}

void CPU::CopyToX(){
    X = AC;
    return;
}

void CPU::CopyFromX() {
    AC = X;
}
void CPU::CopyToY(){
    Y = AC;
    return;
}

void CPU::CopyFromY(){
    AC = Y;
}

void CPU::CopyToSp(){
    SP = AC;
}

void CPU::CopyFromSp(){
    AC = SP;
}

void CPU::JumpAddr(){
    PC = param;
}

void CPU::JumpIfEqual() {
    if(X == 0){
        JumpAddr();
    }
}

void CPU::JumpIfNotEqual() {
    if(X != 0){
        JumpAddr();
    }
}

void CPU::CallAddr(){
    SP = PC;
    PC = param;
}

void CPU::Ret(){
    //TODO: pop return addr from stack
    //jump to address
}

void CPU::IncX(){
    X++;
}

void CPU::DecX(){
    X--;
}

void CPU::Push(){
    //TODO: push AC onto stack
}

void CPU::Pop(){
    //TODO: pop from stack into AC
}

void CPU::Int(){
    //TODO: set system mode, switch stack, push SP and PC, set new SP and PC
}

void CPU::IRet(){
    //TODO: Restore registers,set user mode
}

void CPU::End(){
    isRunning = false;
}

/* util tasks */

bool CPU::isStillRunning(){
    return isRunning;
}

