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

#ifndef __pic_include__
#define __pic_include__

#include "machine/io_port.h"

//ICW=Initialization Control Word
//OCW=Operation Control Word
/*Master:-Port 0x20:ICW1 OCW2 OCW3
         -Port 0x21:ICW2-4 OCW1
  Slave:-Port 0xa0
        -Port 0xa1*/
//OCW1: Inerrupt mask(IMR) via Port 0x21/0xa1(data)

class PIC {
private:
	IO_Port imr_master, imr_slave;
public:
	PIC(const PIC &copy) = delete; // prevent copying
	PIC(): imr_master(0x21), imr_slave(0xa1) {};
/* Add your code here */ 
	enum {
    timer    = 0,
    keyboard = 1
	};

	void allow (int interrupt_device);
	void forbid (int interrupt_device);
	bool is_masked (int interrupt_device);
};

#endif
