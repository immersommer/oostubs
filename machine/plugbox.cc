/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/

/* Add your code here */ 
#include "machine/plugbox.h"
#include "device/panic.h"

extern Panic panic;
/*In the constructor, the global known Panic object panic is registered for all 
interrupts and exceptions, which provides a minimal interrupt handling.*/
Plugbox::Plugbox (){
    for(int i = 0; i < 64; i++){
        gates[i] = &panic;
    }
}

//Plug in a handler routine at the interrupt number slot, provided in the form of a Gate object.
//在中断编号槽插入一个处理程序，以Gate对象的形式提供。
void Plugbox::assign (unsigned int slot, Gate& gate){
    if(slot >= 64){
        panic.prologue();
    }
    gates[slot] = &gate;
}

//Retrieve the Gate object for the specified slot
Gate& Plugbox::report (unsigned int slot){
    if(slot >= 64){
        panic.prologue();
    }
    return *gates[slot];
}
