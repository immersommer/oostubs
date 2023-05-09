/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
/* Add your code here */ 
CPU cpu;
/* GLOBAL VARIABLES */

extern CGA_Stream kout;
/* Add your code here */ 
CGA_Stream cout;
 
void Application::action()
{
/* Add your code here */ 
    // make outputs in an endless loop at a fixed position
    for(;;){
        cpu.disable_int();
        cout.setpos(15, 15);
        cout << "test" << endl;
        cout.flush();
        cpu.enable_int();
    }
}
