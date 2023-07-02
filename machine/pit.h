/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/*
Port(1.PIT)		Register			Access modes
0x40			Counter 0			write/read
0x43			Control register	write only
*/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

class PIT {
public:
	PIT(const PIT &copy) = delete; // prevent copying
/* Add your code here */ 
private:
	int ir_interval;
	IO_Port ctrl_port;
	IO_Port rw_port;
public:
	PIT(int us) : ctrl_port(0x43), rw_port(0x40){
		interval (us);
	}
	int interval() {
/* Add your code here */ 
//Indicates which interrupt interval was set.
		return ir_interval;
	}
	void interval(int us);
};

#endif
