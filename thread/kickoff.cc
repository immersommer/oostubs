/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K I C K O F F                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Function to start a coroutine.                                            */
/* Since this function is not really called, but only jumped to by a clever  */
/* initialization of the stack of the coroutine, it must never terminate.    */
/* Otherwise a meaningless value would be interpreted as a return address    */
/* and the computer would crash.                                             */
/*****************************************************************************/

#include "thread/kickoff.h"
#include "thread/coroutine.h"
/* Add your code here */ 
extern "C" void kickoff (void *dummy1, void *dummy2, void *dummy3, void *dummy4, void *dummy5, void *dummy6, void* object){
    //by simply calling the method action() of the coroutine object object found as parameter.
    Coroutine* object_cpp = (Coroutine*)object;
    object_cpp->action();

    // it must never terminate
    for(;;){}
}
