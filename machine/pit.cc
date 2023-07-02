/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/* Add your code here */ 
#include "machine/pit.h"

/* the timer component is a maximum of 838 nanoseconds
 it regularly triggers interrupts at intervals of approx. us microseconds*/

/*6-7   00  Counter 0
  4-5   11  Low-order, then high-order counter byte
  1-3   010 Periodic interrupt
  0     0   Binary counting of 16 bits
  00110100 = 52 = 0x34*/

void PIT::interval(int us){
    //838 ns into 1 us
    int ns = 1000 * us;
    int micro = ns / 838;
    if((ns % 838) > 419) micro++;

// The first one to transfer the control byte and two more commands with the lower and the higher byte of the counter value.
    ctrl_port.outb(0x34);
    rw_port.outb(micro & 0xFF);
    rw_port.outb((micro >> 8) & 0xFF);
}