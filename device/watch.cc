/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Handles timer interrupts by managing a time slice and triggering a        */
/* process switch if necessary.                                              */
/*****************************************************************************/

/* Add your code here */ 
#include "device/watch.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"
#include "thread/scheduler.h"

extern Plugbox plugbox;
extern PIC pic;
extern Guarded_Scheduler scheduler;

void Watch::windup(){
    //register with the Plugbox plugbox
    plugbox.assign(Plugbox::timer, *this);
    // allow the interrupts of the timer module
    pic.allow(PIC::timer);
}

	// PROLOGUE: Contains the prologue of the interrupt handler.
bool Watch::prologue(){
    return true;
}

	// EPILOGUE: This method triggers the process switch.
void Watch::epilogue(){
    scheduler.Scheduler::resume();
}