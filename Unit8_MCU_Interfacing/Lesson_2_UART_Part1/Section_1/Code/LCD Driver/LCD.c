/*
 * LCD.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#include "LCD.h"


//	RS
//	 0:  (Command Mode) Instruction register (for write) Busy flag
//	 1: Data register (for write and read)

//	RW
//	 Selects read or write.
//	 0:Write
//	 1:Read

//	E
//	1:Starts data read/write.

void LCD_KICK(void)

{
	LCD_CTRL |= (1 << Enable_Switch);
	//Delay Between Writing Each Letter
	_delay_ms(20);
	LCD_CTRL &= ~(1 << Enable_Switch);
	_delay_ms(20);

}

void LCD_check_lcd_isbusy(void)
{
	//Read Mode
	LCD_DataDir_PORT &= ~(0xFF << DATA_shift);

	//Instruction Mode
	SetBit(LCD_CTRL, RW_Switch);
	ClearBit(LCD_CTRL, RS_Switch);

	LCD_KICK();

	//Write Mode
	LCD_DataDir_PORT |= (0xFF << DATA_shift);
	ClearBit(LCD_CTRL, RW_Switch);
}

void LCD_clear_screen(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_INIT()
{
	_delay_ms(20);
	LCD_check_lcd_isbusy();

	//Write Mode
	LCD_DataDir_CTRL |= (1 << Enable_Switch) | (1 << RW_Switch) | (1 << RS_Switch);
	LCD_CTRL &= ~((1 << Enable_Switch) | (1 << RW_Switch) | (1 << RS_Switch));

	LCD_DataDir_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();

#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02); //command to tell LCD we are using D4 -> D7
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
#endif

	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR );
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	LCD_check_lcd_isbusy();
#ifdef EIGHT_BIT_MODE
	LCD_PORT = command;
	LCD_CTRL &= ~((1 << RW_Switch) | (1 << RS_Switch));
	LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	//First Stage
	LCD_PORT =   (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~((1 << RW_Switch) | (1 << RS_Switch));
	LCD_KICK();

	//Second Stage
//	LCD_PORT =   (LCD_PORT & 0x0F) | ((command & 0x0F) << 4);
	LCD_PORT =   (LCD_PORT & 0x0F) | ((command << 4) & 0xF0);
	LCD_CTRL &= ~((1 << RW_Switch) | (1 << RS_Switch));
	LCD_KICK();
#endif
}

void LCD_WRITE_CHAR(unsigned char character)
{
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = character;
	SetBit(LCD_CTRL, RS_Switch);
	ClearBit(LCD_CTRL, RW_Switch);
	LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
//	LCD_check_lcd_isbusy();
	//First Stage
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= (1 << RS_Switch);
	LCD_CTRL &= ~(1 << RW_Switch);
	LCD_KICK();
	_delay_ms(1);

	//Second Stage
//	LCD_PORT = (LCD_PORT & 0x0F) | ((character & 0x0F) << DATA_shift);
	LCD_PORT = (LCD_PORT & 0x0F) | ((character << DATA_shift) & 0xF0);
	LCD_CTRL |= (1 << RS_Switch);
	LCD_CTRL &= ~(1 << RW_Switch);
	LCD_KICK();
	_delay_ms(2);
#endif

}

void LCD_WRITE_STRING(char* string)
{
	int count = 0;
	while(*string > 0)
	{
		LCD_WRITE_CHAR(*string++);
		count ++;
		if(count == 16)
		{
			LCD_GOTO_XY(2, 0);
		}
		else if(count == 32)
		{
			//_delay_ms(); add delay here before Clearing Screen
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}

void LCD_GOTO_XY(uint8 line, uint8 position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_CUSTOM_CHAR(void)
{
	LCD_WRITE_COMMAND(64);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_CHAR(0);
	_delay_ms(10);
}

