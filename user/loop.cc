/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop is a thread that does nothing else but count upwards and print this  */
/* on the screen. In between, it yields the CPU. The Scheduler then decides  */
/* which thread shall run next.                                              */
/*****************************************************************************/

#include "user/loop.h"
#include "thread/scheduler.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "syscall/guarded_scheduler.h"

extern CGA_Stream cout;
extern Guarded_Scheduler scheduler;

void Loop::action(){
    for(;;){
        {Secure secure; 
        cout.setpos(40, 15);
        cout << "I'm Loop" << i << endl;
        cout.flush();
        }
    //removes the first process from the ready list and activates it.
        if(i == 1)
            scheduler.exit();
    //append the currently running process to the end of the ready list and activate the first one.
        scheduler.resume();
    }
}
