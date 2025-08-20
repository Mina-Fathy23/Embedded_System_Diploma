/*
 * Timer_Section.c
 *
 *  Created on: Oct 2, 2024
 *      Author:	Mina Fathy
 */

#define F_CPU 8000000UL

//--------------------------------
//includes
//--------------------------------
#include "../Timer Driver/Timer.h"
#include "../PWM Driver/PWM.h"


/*
 *  //===============================WDT CODE========================================//
#define LED_DRR		DDRC
#define LED_PORT	PORTC
#define LED_PIN 	0

void WDT_OFF()
{
	WDTCR |= (1 << WDTOE) | (1 << WDE);
	WDTCR = 0x00;
}

void WDT_ON()
{
	WDTCR |= (1 << WDE) | (1 << WDP1) | (1 << WDP2);
	ClearBit(WDTCR, WDP0);
}

int main(void)
{
	SetBit(LED_DRR, LED_PIN);
	_delay_ms(500);

	while(1)
	{
		WDT_ON();
		ToggleBit(LED_PORT, LED_PIN);
		_delay_ms(1100);
		WDT_OFF();
	}

}
 */


//--------------------------------
//Global and Extern Variables
//--------------------------------


void TOIE_Callback()
{

	PORTA = ~PORTA;
}

int main(void)
{
	DDRA = 0xFF;
	SetBit(DDRB, PIN3);
	sei();
	TIMER0_CALLBACK_Overflow_INTERRUPT(TOIE_Callback);
	ST_TIMER0_CONFIG_t config = {
			Fast_PWM,
			PRESCALING_CLK8,
			OC0_CTC_DISABLE,
			OC0_PWM_NON_INVERTING,
			OCIE0_DISABLE,
			TOIE0_Enable
	};
//	TIMER0_SetCompareValue(122);
	TIMER0_Init(&config);

	//Setting Duty cycle to 90%
	PWM_SetDutyCylce(90, TIMER0);

	while(1)
	{

	}
}
