/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/
/* Add your code here */ 
#include "device/panic.h"

extern CGA_Stream cout;
extern CPU cpu;

void Panic::trigger(){
    cout << "Error! CPU stops!" << endl;
    cpu.halt();
}

