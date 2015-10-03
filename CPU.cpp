//
// Created by Thomas on 9/28/2015.
//

#include "CPU.h"

CPU::CPU(int timeCounter) {
    //Timer  = timer(timeCounter);
    srand(time(NULL));
    PC = 0;
}

/* cycle functions */

int CPU::toFetch(){
    return PC;
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
bool CPU::decode(int code) {
    bool hasOperand = false;
 switch(code) {
    case 1:
        hasOperand = true;
         //load value
         break;
     case 2:
         hasOperand = true;
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
    return hasOperand;
}

void CPU::execute(int code) {
 switch(code) {
    case 1:
         //load value
         break;
     case 2:
         //load addr
         break;
     case 3:
         //load ind addr
         break;
     case 4:
         //lodIdxX addr
         break;
     case 5:
         //load idxy addr
         break;
     case 6:
         //load sp x
         break;
     case 7:
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
         //subx
         break;
     case 13:
         //suby
         break;
     case 14:
         CopyToX();
         //copytox
         break;
     case 15:
         //copyfromx
         break;
     case 16:
         CopyToY();
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
         End();
         //end
         break;
     default:
         //default
         break;
 }
}

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

void CPU::CopyToX(){
    X = AC;
    return;
}

void CPU::CopyToY(){
    Y = AC;
    return;
}

void CPU::AddX(){
    AC = AC + X;
    return;
}

void CPU::AddY(){
    AC = AC + Y;
    return;
}

void CPU::End(){
    isRunning = false;
}

/* util tasks */

bool CPU::isStillRunning(){
    return isRunning;
}

