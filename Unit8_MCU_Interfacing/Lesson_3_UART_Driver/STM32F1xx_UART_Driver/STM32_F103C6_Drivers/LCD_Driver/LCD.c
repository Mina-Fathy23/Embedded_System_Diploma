/*
 * LCD.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#include "LCD.h"

GPIO_PinConfig_t PinCfg;

/*  RS & RW Values from LCD SPECS
	RS
	 0:  (Command Mode) Instruction register (for write) Busy flag
	 1: Data register (for write and read)

	RW
	 Selects read or write.
	 0:Write
	 1:Read

	E
	1:Starts data read/write.
 */


/**================================================================
 * @Fn				- LCD_KICK
 * @breif			- Makes the LCD Display the input Char/Command
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void LCD_KICK(void)

{
	//ClearBit(LCD_CTRL, EN_Switch);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	wait(20); //Delay Between Writing Each Letter
	//SetBit(LCD_CTRL, EN_Switch);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);

}

/**================================================================
 * @Fn				- LCD_check_lcd_isbusy
 * @breif			- Checks if the LCD is Busy/free to execute command
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void LCD_check_lcd_isbusy(void)
{
	//Read Mode
	//LCD_DataDir_PORT &= ~(0xFF << DATA_shift);

	//Set PIN 0 >> 7 Set as Input Floating Point
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);


	//Instruction Mode
	//SetBit(LCD_CTRL->, RW_SWITCH);
	//ClearBit(LCD_CTRL, RS_SWITCH);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	LCD_KICK();

	//Write Mode
	//	LCD_DataDir_PORT = 0xFF;
	//	SetBit(LCD_CTRL, RS_SWITCH);
	//	ClearBit(LCD_CTRL, RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

}

/**================================================================
 * @Fn				- LCD_clear_screen
 * @breif			- Clears Screen from any characters and moves cursor to Line: 1 Position: 0
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void LCD_clear_screen(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

/**================================================================
 * @Fn				- LCD_clear_screen
 * @breif			- Initializes LCD's Port
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void LCD_INIT()
{
	wait(20);
	//Write Mode
	//	LCD_DataDir_CTRL |= (1 << EN_Switch) | (1 << RW_SWITCH) | (1 << RS_SWITCH);
	//	LCD_CTRL &= ~((1 << EN_Switch) | (1 << RW_SWITCH) | (1 << RS_SWITCH));

	//EN_Switch, RW_SWITCH, RS_SWITCH Set as Output Push-Pull
	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	//=====================================================
	//Set PIN 0 >> 7 Set as Output Push-Pull
	//LCD_DataDir_PORT = 0xFF;
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	//============================================================

	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

	//=======================================================
	wait(15);
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
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

/**================================================================
 * @Fn				- LCD_WRITE_COMMAND
 * @breif			- Executes a Command from LCD's Functionality
 * @param [in]		- command: Specifies the Command code according to @ref LCD_define
 * @retval			- None
 * Note				- None
 */
void LCD_WRITE_COMMAND(vuint8_t command)
{
	//	LCD_check_lcd_isbusy();
#ifdef EIGHT_BIT_MODE
	//	LCD_CTRL  = command;
	//	LCD_CTRL &= ~((1 << RW_SWITCH) | (1 << RS_SWITCH));
	MCAL_GPIO_WritePort(LCD_CTRL, command);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	wait(1);
	LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	//First Stage
	LCD_CTRL  = (LCD_CTRL  & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~((1 << RW_SWITCH) | (1 << RS_SWITCH));
	wait(10);
	LCD_KICK();

	//Second Stage
	LCD_CTRL  = (LCD_CTRL  & 0x0F) | (command << DATA_shift);
	LCD_CTRL &= ~((1 << RW_SWITCH) | (1 << RS_SWITCH));
	wait(10);
	LCD_KICK();
#endif
}

/**================================================================
 * @Fn				- LCD_WRITE_CHAR
 * @breif			- Writes ASCII Characters on LCD
 * @param [in]		- character: Specifies the character cod be written on LCD
 * @retval			- None
 * Note				- None
 */
void LCD_WRITE_CHAR(vuint8_t character)
{
	//  LCD_check_lcd_isbusy();
#ifdef EIGHT_BIT_MODE
	//	LCD_CTRL  = character;
	//	SetBit(LCD_CTRL, RS_SWITCH);
	//	ClearBit(LCD_CTRL, RW_SWITCH);
	MCAL_GPIO_WritePort(LCD_CTRL , character);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);

	wait(1);
	LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	//First Stage
	LCD_CTRL  = (LCD_CTRL  & 0x0F) | (character & 0xF0);
	SetBit(LCD_CTRL, RS_SWITCH);
	ClearBit(LCD_CTRL, RW_SWITCH);
	wait(10);
	LCD_KICK();

	//Second Stage
	LCD_CTRL  = (LCD_CTRL  & 0x0F) | (character << DATA_shift);
	SetBit(LCD_CTRL, RS_SWITCH);
	ClearBit(LCD_CTRL, RW_SWITCH);
	wait(10);
	LCD_KICK();
#endif
}
/**================================================================
 * @Fn				- LCD_WRITE_STRING
 * @breif			- Writes a Senctence on LCD
 * @param [in]		- string: Specifies the string to be written on LCD
 * @retval			- None
 * Note				- None
 */
void LCD_WRITE_STRING(char* string)
{
	vuint8_t count = 0;
	while(*string > 0)
	{
		LCD_WRITE_CHAR(*(string)++);
		count ++;
		if(count == 16)
		{
			LCD_GOTO_XY(2, 0);
		}
		else if(count == 32)
		{
			//wait(); add delay here before Clearing Screen
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}

/**================================================================
 * @Fn				- LCD_GOTO_XY
 * @breif			- Moves cursor to Sepcific location
 * @param [in]		- line: Specifies the line to be written on LCD can be (1 0R 2)
 * @param [in]		- position : Specifies the position to be written on LCD can be from the right boarder of screen
 * 								 value [0:16]
 * @retval			- None
 * Note				- None
 */
void LCD_GOTO_XY(vuint8_t line, vuint8_t position)
{
	if(line == 1)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
	}
	else if(line == 2)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
	}
}

/**================================================================
 * @Fn				- LCD_CUSTOM_CHAR
 * @breif			- adds a Custom character to LCD SRAM
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
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
	wait(10);
}

