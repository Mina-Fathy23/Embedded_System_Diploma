/*
 * LCD_&_Keypad.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */




#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/Platform_Types.h"
#include "../LIB/Utils.h"
#include "../LCD Driver/LCD.h"
#include "../KeyPad Driver/keypad.h"

#define IO_Base 0x20

//GDPIO_Port B
//#define DDRB 		*((vuint8_t*)(IO_Base + 0x17))
//#define PORTB 	*((vuint8_t*)(IO_Base + 0x18))
//#define PINB		*((vuint8_t*)(IO_Base + 0x16))
//
////GDPIO_Port D
//#define DDRD 		*((vuint8_t*)(IO_Base + 0x11))
//#define PORTD 	*((vuint8_t*)(IO_Base + 0x12))
//#define PIND		*((vuint8_t*)(IO_Base + 0x10))


int main()
{
	LCD_INIT();
	_delay_ms(10);
	KEYPAD_Init();
	LCD_CUSTOM_CHAR();
//	LCD_WRITE_STRING("Mina Fathy & Mina Fathy & Mina & Mina & Mina");
	char pressed_key;

	while(1)
	{
		pressed_key = KEYPAD_GetChar();
		 switch(pressed_key)
		 {
		 case 'C':
			 LCD_clear_screen();
			 break;
		 case 'N':
			 break;
		 default:
			 LCD_WRITE_CHAR(pressed_key);
			 break;
		 }

	}
	return 1;
}


