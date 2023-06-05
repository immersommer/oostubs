/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.                                  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

/* Add your code here */ 
#include "object/chain.h"

class Gate : public Chain{
    bool epilogue_is_enqueued;

public:
    Gate(){}
    virtual bool prologue () = 0;
    virtual void epilogue (){}
    virtual ~Gate(){}
    //Sets a flag that remembers whether the epilogue is enqueued.
    void queued (bool q){
        epilogue_is_enqueued = q;
    }
    //Checks whether the epilogue is enqueued.
    bool queued (){
        return epilogue_is_enqueued;
    }
};

#endif
