/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Locker class implements a lock that can be used to protect critical   */
/* sections. However, the variable only indicates whether the critical       */
/* section is free. Potentially necessary waiting, and protection for        */
/* counting functionality, must be implemented elsewhere.                    */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

#include "device/panic.h"
#include "device/cgastr.h"

extern Panic panic;
extern CGA_Stream cout;

class Locker {
private:
	bool is_locked;

public:
	Locker(const Locker &copy) = delete; // prevent copying
/* Add your code here */ 
	//Constructor that initializes the lock variable (free).
	Locker() : is_locked(false) {}
	//must be called when entering the critical section.
	void enter(){
		if(is_locked){
			cout << "Error in critical section" << endl;
			panic.prologue();
		}
		is_locked = true;
	}
	// must be called when leaving the critical section.
	void retne(){
		if(!is_locked){
			cout << "Error out critical section" << endl;
			panic.prologue();
		}
		is_locked = false;
	}
	//Indicates whether the critical section is free.
	bool avail(){
		return !is_locked;
	}
};

#endif
