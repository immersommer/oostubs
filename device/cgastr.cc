/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#include "device/cgastr.h"

// output/print the buffer contents of base class Stringbuffer
void CGA_Stream::flush (){
    if(size){
        print(buffer, size, DEFAULT_ATTRIBUTE);
        size = 0;
    }
}
