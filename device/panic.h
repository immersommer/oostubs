/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/cpu.h"
#include "device/cgastr.h"

class Panic : public Gate
/* Add your code here */ 
{
public:
	Panic (const Panic &copy) = delete; // prevent copying
	Panic () {}
/* Add your code here */ 
	virtual bool prologue() override;
};

#endif
