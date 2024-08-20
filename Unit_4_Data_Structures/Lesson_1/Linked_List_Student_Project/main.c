/*
 * main.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */

#include "linked_list.h"

SStudent_t* g_p_FirstStudent = NULL;
uint8 on = 1;

int main(void)
{
	char temp_text[40];
	while(on)
	{
		DPRINT("\n ===================================================");
		DPRINT("\n\t Choose one of the following Options: \n");
		DPRINT("\n 1 : Add_Student");
		DPRINT("\n 2 : Delete_Student");
		DPRINT("\n 3 : View_Students");
		DPRINT("\n 4 : Delete_All");
		DPRINT("\n 5 : Get_Nth");
		DPRINT("\n 6 : Find_Length");
		DPRINT("\n 7 : Value_from_end");
		DPRINT("\n 8 : Middle");
		DPRINT("\n 9 : Reverse_list");
		DPRINT("\n 10: Exit");
		DPRINT("\n Enter Option Number: ");

		gets(temp_text);
		DPRINT("\n ===================================================");

		switch(atoi(temp_text))
		{
		case 1:
			Linked_Add_Student();
			break;
		case 2:
			Linked_Delete_Student();
			break;
		case 3:
			Linked_View_Students();
			break;
		case 4:
			Linked_Delete_All();
			break;
		case 5:
			Linked_Get_Nth();
			break;
		case 6:
			DPRINT("\nNo. of Students: %d", Linked_Find_Length(g_p_FirstStudent));
			break;
		case 7:
			Linked_Value_from_end();
			break;
		case 8:
			Linked_Middle();
			break;
		case 9:
			Linked_Reverse_list();
			break;
		case 10:
			Linked_Delete_All();
			DPRINT("\nProgram Log Out....Done\n")
			on = 0;
			break;
		default:
			DPRINT("\n Wrong Option")
			break;
		}
	}
}


