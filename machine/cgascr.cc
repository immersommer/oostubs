/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "machine/cgascr.h"

char* const CGA_Screen::CGA_START = (char *)0xb8000;
//const char*: a pointer to const char, the value be pointed can't change but pointer can.
//char* const: a const pointer to char, the value be pointed can change but pointer can't.

const int INDEXREGISTER = 0x3d4;
const int DATAREGISTER = 0x3d5;

CGA_Screen::CGA_Screen(){

}

void CGA_Screen::show (int x, int y, char c, unsigned char attrib){
    char *pos;

    pos = CGA_START + (x + y * CHAR_COUNT_LINE) * 2; // two bytes 
    *pos = c;
    //the second of the two bytes the desired foreground and background color
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos(int x, int y){
    IO_Port index_reg(INDEXREGISTER);
    IO_Port data_reg(DATAREGISTER);

    unsigned short cursor_pos = y * CHAR_COUNT_LINE + x;

    index_reg.outb(REG_CURSOR_LOW);
    //leaves only the value in the last 8 bits
    data_reg.outb((unsigned char)cursor_pos & 0xFF);

    index_reg.outb(REG_CURSOR_HIGH);
    data_reg.outb((unsigned char)(cursor_pos >> 8) & 0xFF);

}
void CGA_Screen::getpos(int &x, int &y){
    IO_Port index_reg(INDEXREGISTER);
    IO_Port data_reg(DATAREGISTER);

    unsigned short cursor_pos = 0;

    index_reg.outb(REG_CURSOR_HIGH);
    cursor_pos = data_reg.inb() << 8;

    index_reg.outb(REG_CURSOR_LOW);
    cursor_pos = cursor_pos | data_reg.inb();

    x = cursor_pos % CHAR_COUNT_LINE;
    y = cursor_pos / CHAR_COUNT_LINE;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib){
    int x, y;
    getpos(x, y);
    
    for(int i = 0; i < length; i++){
        //\n
        if(text[i] == '\n'){
            ++y;
            x = 0;
        } else{
            show(x, y, text[i], attrib);
            ++x;
        }

        //end of the line
        if(x >= CHAR_COUNT_LINE){
            ++y;
            x = 0;
        }

        //end of screen
        if(y >= LINE_COUNT){
            //move all words
            for(int i = 0; i < 2 * CHAR_COUNT_LINE * (LINE_COUNT - 1); i++){
                CGA_START[i] = CGA_START[i + (2 * CHAR_COUNT_LINE)];
            }
            //set zero out last line
            for(int i = 2 * CHAR_COUNT_LINE * (LINE_COUNT - 1); i < 2 * CHAR_COUNT_LINE * LINE_COUNT; i += 2){
                CGA_START[i] = ' ';
                CGA_START[i+1] = 0x0f;
            }
            y = LINE_COUNT - 1;
        }
    }
    setpos(x, y);
}