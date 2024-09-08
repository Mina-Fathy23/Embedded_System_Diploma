/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Mina Fathy
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Platform_Types.h"

#define IO_Base 0x20

//GDPIO_Port B
#define DDRB 	*((vuint32_t*)(IO_Base + 0x17))
#define PORTB 	*((vuint32_t*)(IO_Base + 0x18))

//GDPIO_Port D
#define DDRD 	*((vuint32_t*)(IO_Base + 0x11))
#define PORTD 	*((vuint32_t*)(IO_Base + 0x12))


//EXTI
#define MCUCR 	*((vint32_t*)(IO_Base + 0x35))
#define SREG 	*((vint32_t*)(IO_Base + 0x3F))
#define GICR 	*((vint32_t*)(IO_Base + 0x3B))
#define MCUCSR 	*((vint32_t*)(IO_Base + 0x34))
#define GIFR 	*((vint32_t*)(IO_Base + 0x3A))


void GPIO_init()
{
	DDRD |= 0b11110000;
	DDRB |= (0 << 2);
}

void EXTI_init()
{
	//	Set INT0 to any Logical Change
	MCUCR |= (0b01 << 0);

	//	Set INT1 to Rising edge
	MCUCR |= (1 << 3);
	MCUCR |= (1 << 2);

	//	Set INT2 to Falling edge
	MCUCSR |= (0 << 6);

	//	Enable INT0, INT1, INT2
	GICR |= (1 << 7);
	GICR |= (1 << 6);
	GICR |= (1 << 5);

	//	Enable Global Interrupt
	SREG |= (1 << 7);

}

int main()
{
	GPIO_init();
	EXTI_init();

	while(1)
	{
		PORTD |= (1 << 4);
		_delay_ms(200);
		PORTD &= (0 << 4);
		PORTD &= (0 << 5);
		PORTD &= (0 << 6);
		PORTD &= (0 << 7);
		_delay_ms(200);
	}
	return 1;
}

ISR(INT0_vect)
{
	PORTD |= (1 << 5);
	_delay_ms(1000);
	GIFR |= (1 << 6);
}

ISR(INT1_vect)
{
	PORTD |= (1 << 6);
	_delay_ms(1000);
	GIFR |= (1 << 7);
}

ISR(INT2_vect)
{
	PORTD |= (1 << 7);
	_delay_ms(1000);
	GIFR |= (1 << 5);
}
