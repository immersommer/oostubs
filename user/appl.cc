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
/* Add your code here */ 
extern CPU cpu;
/* GLOBAL VARIABLES */

extern CGA_Stream kout;
/* Add your code here */ 
extern CGA_Stream cout;
 
void Application::action()
{
/* Add your code here */ 
    // make outputs in an endless loop at a fixed position
    for(;;){
        Secure secure; 
        cout.setpos(15, 15);
        cout << "test" << endl;
        cout.flush();
    }
}
