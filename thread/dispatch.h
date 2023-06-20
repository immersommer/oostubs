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

#ifndef __dispatch_include__
#define __dispatch_include__

/* Add your code here */ 
#include "thread/coroutine.h"

class Dispatcher {
private:
	Coroutine* life_pointer;

public:
	Dispatcher(const Dispatcher &copy) = delete; // prevent copying
/* Add your code here */ 
//initializes the life pointer with null
	Dispatcher () : life_pointer(0){}
	void go (Coroutine& first);
	void dispatch (Coroutine& next);
// used to determine which coroutine is currently in control of the processor
	Coroutine* active (){
		return life_pointer;
	}
};

#endif
