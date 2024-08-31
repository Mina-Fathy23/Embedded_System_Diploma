/*
 * main.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Mina Fathy
 */

#include "Student_Managment.h"


vuint8_t on = 1;

int main()
{
	FIFO_buff_t students;
	char temp_text[40];
	if(FIFO_init(&students, buffer, width) == FIFO_no_error)
		DPRINT("FIFO Init.....Done\n");

	DPRINT("\n\tWelcome to the Student Management System\n")

	while(on)
	{
		DPRINT("\n ===================================================");
		DPRINT("\n\t Choose one of the following Options: \n");
		DPRINT("\n 1 : Add The Student Details Manually");
		DPRINT("\n 2 : Add The Student Details for a text file");
		DPRINT("\n 3 : Find The Student Details by Roll Number");
		DPRINT("\n 4 : Find The Student Details by First Name");
		DPRINT("\n 5 : Find The Student Details by Course ID");
		DPRINT("\n 6 : Find Total Number of Students");
		DPRINT("\n 7 : Delete The Student Details by Role Number");
		DPRINT("\n 8 : Update The Student Details by Role Number");
		DPRINT("\n 9 : Show All Information");
		DPRINT("\n 10: Exit");
		DPRINT("\n Enter Option Number: ");

		gets(temp_text);
		DPRINT("\n ===================================================");

		switch(atoi(temp_text))
		{
		case 1:
			add_student_manually(&students);
			break;
		case 2:
			add_student_file(&students);
			break;
		case 3:
			find_roll_number(&students);
			break;
		case 4:
			find_first_name(&students);
			break;
		case 5:
			find_c(&students);
			break;
		case 6:
			total_students(&students);
			break;
		case 7:
			delete_student(&students);
			break;
		case 8:
			update_student(&students);
			break;
		case 9:
			show_students(&students);
			break;
		case 10:
			DPRINT("\nProgram Log Out....Done\n")
			on = 0;
			break;
		default:
			DPRINT("\n Wrong Option")
			break;
		}
	}
	return 1;
}
