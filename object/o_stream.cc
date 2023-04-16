/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#include "object/o_stream.h"
#define CHAR_LEN 50

/* Add your code here */ 
const char O_Stream::numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

//find the position of the first char
int O_Stream::number_to_char_array(unsigned long number, char *char_array, int length){
    int i = length - 1;
    SYSTEM system = this -> system;

    //BIN = 0bXXX, OCT = 0XXX, DEC = XXX, HEX = 0xXXX
    do{
        int remainder = number % system;
        number = number / system;
        char_array[i] = numbers[remainder];
        i--;
    } while(number);

    if(system == BIN){
        char_array[i] = 'b';
        i--;
    }

    if(system == HEX){
        char_array[i] = 'x';
        i--;
    }

    if(system != DEC){
        char_array[i] = '0';
        return i;
    }
    i += 1;
    return i;
}

O_Stream& O_Stream::operator<< (long number){
    bool minus = false;
    char char_array[CHAR_LEN];
    if(number < 0){
        minus = true;
        number = -number;
    }

    int i = number_to_char_array((unsigned long)number, char_array, CHAR_LEN);

    if(minus){
        i -= 1;
        char_array[i] = '-';
    }

    while(i < CHAR_LEN){
        this->put(char_array[i]);
        i++;
    }
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned long number){
    char char_array[CHAR_LEN];
    int i = number_to_char_array(number, char_array, CHAR_LEN);
    while(i < CHAR_LEN){
        this->put(char_array[i]);
        i++;
    }
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned char c){
    return operator<< ((unsigned long) c);
}
O_Stream& O_Stream::operator<< (char c){
    this->put(c);
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number){
    return operator<<((unsigned long)number);
}

O_Stream& O_Stream::operator<< (short number){
    return operator<<((long)number);
}

O_Stream& O_Stream::operator<< (unsigned int number){
    return operator<<((unsigned long)number);
}

O_Stream& O_Stream::operator<< (int number){
    return operator<<((long)number);
}

//Append the pointer in hexadecimal system.
O_Stream& O_Stream::operator<< (void* pointer){
    SYSTEM temp = this->system;
    this->system = HEX;
    operator<<((unsigned long)pointer);
    this->system = temp;
    return *this;
}

//null-terminated string: end with '\0'
O_Stream& O_Stream::operator<< (char* text){
    while(*text != '\0'){
        this->put(*text);
        text++;
    }
    return *this;
}

O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&)){
    return (*fkt)(*this);
}

//insert a new line
O_Stream& endl (O_Stream& os){
    os.put('\n');
    os.flush();
    return os;
}

O_Stream& bin (O_Stream& os){
    os.system = O_Stream::BIN;
    return os;
}

O_Stream& oct (O_Stream& os){
    os.system = O_Stream::OCT;
    return os;
}

O_Stream& dec (O_Stream& os){
    os.system = O_Stream::DEC;
    return os;
}

O_Stream& hex (O_Stream& os){
    os.system = O_Stream::HEX;
    return os;
}