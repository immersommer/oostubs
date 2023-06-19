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

#ifndef __loop_include__
#define __loop_include__

#include "thread/entrant.h"

class Loop : public Entrant
{
private:
    int i;

public:
    Loop (const Loop &copy) = delete;
    Loop(void* tos, int i): Entrant(tos), i(i){}
    void action ();
};
 
#endif
