/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The system's central interrupt handling routine.                          */
/* The parameter specifies the number of the interrupt that occurred.        */
/*****************************************************************************/

/* INCLUDES */
#include "machine/plugbox.h"
#include "guard/guard.h"

/* FUNCTIONS */
extern Plugbox plugbox;
extern Guard guard;

extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot)
{
    /*the corresponding Gate object is determined with the help of the interrupt 
    number in the global Plugbox object plugbox  and its prologue() method is executed.*/
    Gate &gate = plugbox.report(slot);

    if(gate.prologue())
        guard.relay(&gate);
}
