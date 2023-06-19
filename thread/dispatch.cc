/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Dispatcher implementation.                                                */
/* The Dispatcher maintains the life pointer that points to the currently    */
/* active coroutine. go() initializes the life pointer and starts the first  */
/* coroutine, all further context switches are triggered by dispatch().      */
/* active() returns the life pointer.                                        */
/*****************************************************************************/

/* Add your code here */ 
#include "thread/dispatch.h"
#include "thread/coroutine.h"

//With this method the coroutine first is put in the life pointer and started.
void Dispatcher::go (Coroutine& first){
    life_pointer = &first;
    life_pointer->go();
}
//This method sets the life pointer to next and performs a coroutine switch from the old to the new life pointer.
void Dispatcher::dispatch (Coroutine& next){
    Coroutine* current = life_pointer;
    life_pointer = &next;
    current->resume(next);
}