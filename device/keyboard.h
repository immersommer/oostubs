/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
 
class Keyboard : public Gate, public Keyboard_Controller
/* Add your code here */ 
{
private:
	char key_output;

public:
	Keyboard(const Keyboard &copy) = delete; // prevent copying
/* Add your code here */ 
	Keyboard(){}
/* Add your code here */ 
 
	// PLUGIN: "Plugs in" the keyboard (driver). From now on, keypresses are handled.
	void plugin();

/* Add your code here */ 
	bool prologue ();

	void epilogue ();
};

#endif
