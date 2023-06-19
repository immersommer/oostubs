/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "thread/coroutine.h"
#include "thread/entrant.h"
#include "user/loop.h"

class Application : public Entrant
 
{

public:
	Application (const Application &copy) = delete; // prevent copying
/* Add your code here */ 
	Application (void* tos): Entrant(tos){}
	void action ();
};

#endif
