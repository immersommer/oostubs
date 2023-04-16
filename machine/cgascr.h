#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

#define CHAR_COUNT_LINE 80
#define LINE_COUNT 25

#define REG_CURSOR_HIGH 14
#define REG_CURSOR_LOW 15

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GREY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define YELLOW 14
#define WHITE 15

#define FOREGROUND_COLOR_BIT 0
#define BACKGROUND_COLOR_BIT 4
#define BLINKING_BIT 7

#define DEFAULT_ATTRIBUTE (YELLOW << FOREGROUND_COLOR_BIT | GREEN << BACKGROUND_COLOR_BIT | 1 << BLINKING_BIT)

class CGA_Screen {
private:
/* Add your code here */ 
	CGA_Screen(const CGA_Screen &copy); // prevent copying
	static char* const CGA_START;
public:
	CGA_Screen();
/* Add your code here */ 
	void show(int x, int y, char c, unsigned char attrib);
	void setpos(int x, int y);
	void getpos(int &x, int &y);
	void print (char* text, int length, unsigned char attrib);

/* Add your code here */ 
};

/* Add your code here */ 

#endif
