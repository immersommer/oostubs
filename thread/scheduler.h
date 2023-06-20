/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
#include "object/queue.h"
/* Add your code here */ 

class Entrant;

class Scheduler : public Dispatcher
/* Add your code here */ 
{
private:
	Queue ready_list;
public:
	Scheduler (const Scheduler &copy) = delete; // prevent copying
/* Add your code here */ 
    Scheduler(){}
	void ready (Entrant& that);
	void schedule ();
	void exit ();
	void kill (Entrant& that);
	void resume ();
};

#endif
