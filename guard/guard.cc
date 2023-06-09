/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

/* Add your code here */ 
#include "guard/guard.h"
#include "machine/cpu.h"

extern CPU cpu;


//Regular control flow leaves the critical section. Accumulated epilogues can be processed now.
/* if two of the same kind of interrupts follow each other so quickly that the 
associated epilogue has not yet been handled, it is not allowed to add the same gate 
object to the epilogue queue twice. The Gate class provides methods to record or check this.*/
void Guard::leave (){
    while(true){
        //Prologue shouldn't be interrupted
        cpu.disable_int();
        item = (Gate*)queue.dequeue();

        //no item in queue
        if(!item)
            break;
        //items in queue
        item->queued(false);
        cpu.enable_int();
        item->epilogue();
    }
    //still lock
    retne();
    cpu.enable_int();
}
void Guard::relay (Gate* item){
    //not allowed to add the same gate object to the epilogue queue twice
    if(item->queued()) return;
    //the critical section is free, the epilogue is handled immediately
    if(avail()){
        enter();
        //cpu.enable_int();
        item->epilogue();
        leave();
    } else {    
        // the critical section is occupied, only added to the epilogue queue
        item->queued(true);
        queue.enqueue(item);
    }
}