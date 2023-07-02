/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements user interface of a thread.                                    */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

/* Add your code here */ 
#include "thread/entrant.h"
 
class Thread : public Entrant
/* Add your code here */ 
 
{
public:
	Thread(const Thread &copy) = delete; // prevent copying
/* Add your code here */ 
	Thread (void* tos) : Entrant(tos){}
};

#endif
