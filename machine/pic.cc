/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

/* Add your code here */ 
#include "machine/pic.h"

//Interrupt numbers(IRQ): 0-7: Master PIC; 8-15: Slave PIC

// forwards interrupts for the device with the number interrupt_device to the CPU.
void PIC::allow (int interrupt_device){
    //nicht maskiert
    //master PIC
    if(interrupt_device < 8)
        imr_master.outb(imr_master.inb() & ~(1 << interrupt_device));
    //slave PIC
    else
        imr_slave.outb(imr_slave.inb() & ~(1 << (interrupt_device - 8)));
}

//suppresses a specific hardware interrupt of the device number interrupt_device.
//配置PIC，使其抑制设备号interrupt_device的特定硬件中断。
void PIC::forbid (int interrupt_device){
    //1=zugehoerige IRQ-Leitung ist maskiert
    //master PIC
    if(interrupt_device < 8)
        imr_master.outb(imr_master.inb() | (1 << interrupt_device));
    //slave PIC
    else
        imr_slave.outb(imr_slave.inb() | (1 << (interrupt_device - 8)));
}

// If interrupts of this device are not forwarded to the CPU, return true, otherwise return false.
bool PIC::is_masked (int interrupt_device){
    if(interrupt_device < 8)
        return(imr_master.inb() & (1 << interrupt_device));
    else
        return(imr_slave.inb() & (1 << (interrupt_device - 8)));
}
