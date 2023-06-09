/* Add your code here */ 
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"

#include "device/keyboard.h"
#include "machine/pic.h"
#include "user/appl.h"
#include "machine/cpu.h"
#include "guard/guard.h"
#include "guard/secure.h"

#define TEXTLEN 1000

static void get_string(char* str, int size){
	const char setchar[]="vyuwekfgiugfvyieaklBCWUIGKLBERHvbreui\nfbewuiBIUE3466\n";
	if(size){
		for(int i = 0; i < size - 1; i++){
			//loop
			int j = i % (int) (sizeof setchar - 1);
			str[i] = setchar[j];
		}
	}
}

static void test_cga_screen(){
	CGA_Screen screen;
	char text[TEXTLEN] = {};
	get_string(text, TEXTLEN);
	screen.print(text, TEXTLEN, DEFAULT_ATTRIBUTE);
}

//unsigned char: [0, 255]
//unsigned short value: [0, 65535]
//short value: [-32767, 32767]
//unsigned int value: [0,65535]
//int value: [-32767, 32767]
//unsigned long value: [0, 4,294,967,295]
//long value: [-2,147,483,647, 2,147,483,647]
static void test_cga_stream(){
	CGA_Stream cout;

	unsigned char unsigned_char = 236;
	char char_val = 'h';
	unsigned short unsigned_short = 65456;
	short short_val = 32674;
	unsigned int unsigned_int = 65526;
	int int_val = -32653;
	unsigned long unsigned_long = 500000000;
	long long_val = -500000000;

	int *pointer = (int*)0x121;

	cout << "char value: " << char_val << endl;
	cout << "unsigned char value: " << unsigned_char << endl;
	cout << "unsigned short value: " << unsigned_short << endl;
	cout << "short value: " << short_val<< endl;
	cout << "unsigned int value: " << unsigned_int<< endl;
	cout << "int value: " << int_val << endl;
	cout << "unsigned long value: " << unsigned_long << endl;
	cout << "long value: " << long_val << endl;
	cout << "pointer value(0x121): " << pointer<< endl;

	cout << "binary(10): " << bin << 10 << endl;
	cout << "octar(10): " << oct << 10 << endl;
	cout << "decimal(10): " << dec << 10 << endl;
	cout << "hexadecimal(10): " << hex << 10 << endl;
}

static void test_key_ctrl(){
	CGA_Stream cout;
	Keyboard_Controller keyctrl;
	Key key;
	char a;

	int caps_lock = 4, num_lock = 2, scroll_lock = 1; //led

	keyctrl.set_led(caps_lock, 0);
	keyctrl.set_led(num_lock, 0);
	keyctrl.set_led(scroll_lock, 0);
	keyctrl.set_repeat_rate(25, 2);

	while(true){
		key = keyctrl.key_hit();
		if(key.valid()){
			a = key.ascii();
			cout << a << " test_key_hit ";
			cout.flush();
		}
	}

}

CPU cpu;
Keyboard keyboard;
PIC pic;
Application application;
Guard guard;
Panic panic;
CGA_Stream cout;
Plugbox plugbox;

static void test_interrupt_handling(){

	
	cpu.enable_int();
	keyboard.plugin();
	application.action();
	for(;;);
	
}

int main(){ 
	//test_cga_screen();

	//test_cga_stream();

	//test_key_ctrl();

	test_interrupt_handling();
	return 0;
}
