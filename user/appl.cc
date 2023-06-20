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
#include "thread/scheduler.h"
/* Add your code here */ 
extern CPU cpu;
/* GLOBAL VARIABLES */

extern CGA_Stream kout;
/* Add your code here */ 
extern CGA_Stream cout;
extern Scheduler scheduler;

static char stack_loop1[2048];
static char stack_loop2[2048];
static char stack_loop3[2048];
 
void Application::action()
{
/* Add your code here */ 
    Loop loop1(stack_loop1 + sizeof(stack_loop1), 1);
    Loop loop2(stack_loop2 + sizeof(stack_loop2), 2);
    Loop loop3(stack_loop3 + sizeof(stack_loop3), 3);

    //appended to the end of the ready list
    scheduler.ready(loop1);
    scheduler.ready(loop2);
    scheduler.ready(loop3);
    // make outputs in an endless loop at a fixed position
    for(;;){
        {Secure secure; 
        cout.setpos(15, 15);
        cout << "test" << endl;
        cout.flush();
        }
        
    
        scheduler.resume();
        scheduler.kill(loop2);
    }
}
