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

class Application : public Coroutine
 
{

public:
	Application (const Application &copy) = delete; // prevent copying
/* Add your code here */ 
	Application (void* tos): Coroutine(tos){}
	void action ();
};

#endif
