/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#include "thread/scheduler.h"
#include "thread/entrant.h"
#include "device/cgastr.h"

extern CGA_Stream cout;

//registers the process that with the scheduler. It is appended to the end of the ready list.
void Scheduler::ready (Entrant& that){
    ready_list.enqueue(&that);
}

//starts up scheduling by removing the first process from the ready list and activating it.
void Scheduler::schedule (){
    Entrant *first = static_cast<Entrant *>(ready_list.dequeue()); 
    if(first){
        go(*first);
    } else {
        cout.setpos(10, 25);
        cout << "scheduling error!" << endl;
    }
        
}
void Scheduler::exit (){
    // process can terminate itself
    //The scheduler does not append it again to the end of the ready list. 
    //removes the first process from the ready list and activates it.
    Entrant *first = static_cast<Entrant *>(ready_list.dequeue()); 
    if(first){
        dispatch(*first);
    } else {
        cout.setpos(25, 25);
        cout << "Scheduler::exit error!!" << endl;
    }
        
}
void Scheduler::kill (Entrant& that){
    //a process can terminate another one (that)
    //The process "that" is simply removed from the ready list and is thereby never scheduled again.
    Entrant* other_process = static_cast<Entrant *>(active());
    if(&that == other_process)
        exit();
    ready_list.remove(&that);
}
void Scheduler::resume (){
    Entrant* current_ptr = static_cast<Entrant *>(active());
    //append the currently running process to the end of the ready list
    ready_list.enqueue(current_ptr);
    //activate the first one.
    current_ptr = static_cast<Entrant *>(ready_list.dequeue());
    if(current_ptr){
        dispatch(*current_ptr);
    } else {
        cout.setpos(40, 25);
        cout << "Scheduler::resume error!!" << endl;
    }  
}
