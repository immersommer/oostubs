/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

/* Add your code here */ 
#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "device/cgastr.h"

extern Plugbox plugbox;
extern PIC pic;
extern CGA_Stream cout;

/*the keyboard object must register at the Plugbox object plugbox and
tell the PIC object pic that interrupts of the keyboard should from now on be reported to the processor.*/
void Keyboard::plugin (){
    plugbox.assign(Plugbox::keyboard, *this);
    pic.allow(PIC::keyboard);
}

bool Keyboard::prologue (){
    //Only if the method key_hit of the base class Keyboard_Controller returns a valid Key, a complete scan code could be determined.
    Key key = key_hit();
    //For "normal" keys then a non-zero ASCII code exists.
    if(key.valid()){
        //If Ctrl-Alt-Delete was pressed, spoa reboot should be triggered.
        if(key.ctrl() && key.alt() && key.scancode() == Key::scan::del)
            reboot();
        
        this->key_output = key.ascii();
        return true;
    }
    return false;
}

void Keyboard::epilogue (){
    int x, y;
    cout.flush();
    cout.getpos(x, y);
    cout.setpos(10, 10);
    cout << key_output << endl;
    cout.flush();
    cout.setpos(x, y);
}  