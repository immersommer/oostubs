/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The toc struct is used to save the values of the non-volatile registers   */
/* in case of a context switch. toc_settle prepares the initial stack and    */
/* the toc struct for the first activation.                                  */
/*****************************************************************************/

#include "machine/toc.h"

// TOC_SETTLE: Prepares a coroutine context for its first activation.
void toc_settle(struct toc *regs, void *tos,
		void (*kickoff)(void *, void *, void *, void *, void *, void *,
				void *),
		void *object)
{
/* Add your code here */ 
	/*register contents (toc) and stack (tos) must be initialized
	 so that on the first activation the execution starts with the function kickoff*/
	//create a stack frame
	void **stack_pointer = (void **)tos;
	*(--stack_pointer) = object;//"object" in 7th parameter on the stack
	*(--stack_pointer) = 0;// (non-existent) caller’s return addr.
	*(--stack_pointer) = kickoff;//kickoff() address

	//write to stack pointer
	regs->rsp = stack_pointer;
}