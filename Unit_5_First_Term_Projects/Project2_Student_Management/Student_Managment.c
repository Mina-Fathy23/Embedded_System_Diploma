/*
 * fifo.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */


#include "Student_Managment.h"


//initializes FIFO Buffer by setting head & base & tail pointers , sets length and count
FIFO_status FIFO_init(FIFO_buff_t* fifo_buf,element_type* buff,uint32 length)
{
	//buffer is valid? used for memory allocation
	if(buffer == NULL)
		return FIFO_NULL;

	fifo_buf->base = buff;
	fifo_buf->head = buff;
	fifo_buf->tail = buff;
	fifo_buf->length = length;
	fifo_buf->count = 0;

	return FIFO_no_error;
}

//add item to FIFO
FIFO_status FIFO_enqueue(FIFO_buff_t* fifo_buf,element_type item)
{
	//FIFO is initialized?
	if(!fifo_buf->base ||!fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//FIFO is full?
	if(FIFO_is_full(fifo_buf) == FIFO_full)
		return FIFO_full;

	*(fifo_buf->head) = item;

	//Circular FIFO
	if(fifo_buf->head == fifo_buf->base + (fifo_buf->length * sizeof(element_type)))
		fifo_buf->head = fifo_buf->base;
	else
		fifo_buf->head++;

	fifo_buf->count++;

	return FIFO_no_error;
}

//Pops items from FIFO
FIFO_status FIFO_dequeue(FIFO_buff_t* fifo_buf,element_type* item)
{
	//FIFO is initialized?
	if(!fifo_buf->base ||!fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//FIFO is empty?
	if(fifo_buf->head == fifo_buf->tail)
		return FIFO_empty;

	//item dequeue
	*item = *(fifo_buf->tail);

	//Circular FIFO
	if(fifo_buf->tail == fifo_buf->base + (fifo_buf->length * sizeof(element_type)))
		fifo_buf->tail = fifo_buf->base;
	else
		fifo_buf->tail++;

	fifo_buf->count--;

	return FIFO_no_error;
}

//Checks if FIFO is full
FIFO_status FIFO_is_full(FIFO_buff_t* fifo_buf)
{
	//FIFO is initialized?
	if(!fifo_buf->base ||!fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//FIFO is full?
	if(fifo_buf->count == fifo_buf->length)
		return FIFO_full;

	return FIFO_no_error;
}

//Prints all values in FIFO without changing its values
void FIFO_print(FIFO_buff_t* fifo_buf)
{
	element_type* temp;
	if(fifo_buf->count == 0)
	{
		printf("FIFO is empty");
	}
	else
	{
		temp = fifo_buf->tail;
		printf("\n ======FIFO_Print======\n");
		while(temp != fifo_buf->head)
		{
			//it gives warring as %X is not compatible with the element_type MICRO
			//printf("\t %X\n", *temp);
			temp++;
		}
		printf("========================\n");
	}
}

//add item to FIFO entered by user(FIFO_enqueue)
void add_student_manually(FIFO_buff_t* fifo_buf)
{
	//FIFO is full?
	if(FIFO_is_full(fifo_buf) == FIFO_full)
	{
		DPRINT("\n =========System is Full========\n");
	}
	else
	{
		char temp_text[40];
		Sinfo_t new_student;

		DPRINT("\n\t =========Add Student Details========\n");

		//Will keep asking for unique Roll Number
		do
		{
			DPRINT("\n Enter The Roll Number: ");
			gets(temp_text);
		}
		while(check_id(fifo_buf, atoi(temp_text)) != 1);
		new_student.roll = atoi (temp_text);

		DPRINT(" Enter The Student's First Name: ");
		gets(new_student.fname);

		DPRINT(" Enter The Student's Last Name: ");
		gets(new_student.lname);

		DPRINT(" Enter the GPA: ");
		gets(temp_text);
		new_student.gpa = atof (temp_text);

		DPRINT(" Enter the Course ID of Courses\n")
		for(uint16 i = 0; i < 5; i++)
		{
			DPRINT(" Course %i ID: ", i+1);
			gets(temp_text);
			new_student.cid[i] = atoi (temp_text);
		}

		FIFO_enqueue(fifo_buf, new_student);

		DPRINT("\n Details Added Successfully....\n");
		total_students(fifo_buf);
	}
}

//checks if the entered Roll number is already taken
char check_id(FIFO_buff_t* fifo_buf, int id)
{
	element_type* temp;
	if(fifo_buf->count == 0)
	{
		return 1;
	}
	else
	{
		temp = fifo_buf->tail;
		while(temp != fifo_buf->head)
		{
			if(temp->roll == id)
			{
				DPRINT("\n [ERROR] The Roll Number (%d) is already taken", id)
																																																		return 0;
			}
			temp++;
		}
	}
	return 1;
}

//tell user how many students and system & how many empty positions
void total_students(FIFO_buff_t* fifo_buf)
{
	DPRINT("\n===================================================\n");
	DPRINT(" [INFO] The Total number of students: %d\n", fifo_buf->count);
	DPRINT(" [INFO] You can add up to: %d", (fifo_buf->length - fifo_buf->count));
}


//add item to FIFO from file (FIFO_enqueue)
void add_student_file(FIFO_buff_t* fifo_buf)
{
	if(FIFO_is_full(fifo_buf) == FIFO_full)
	{
		DPRINT("\n =========System is Full========\n");
	}
	else
	{
		FILE* in_file = fopen("D:/Mina/Workspace/Project2_Student_Database_Queue/Student_Managment.txt", "r");
		if (in_file == NULL)
		{
			DPRINT("Error! Could not open file\n");
			return;
		}

		DPRINT("\n File is found....Opened\n")
		Sinfo_t new_student;

		while(fscanf(in_file, "%d %s %s %f %d %d %d %d %d"
				,&new_student.roll, new_student.fname, new_student.lname,
				&new_student.gpa, &new_student.cid[0], &new_student.cid[1],
				&new_student.cid[2], &new_student.cid[3], &new_student.cid[4]) == 9)
		{
			if(check_id(fifo_buf, new_student.roll) != 1)
				continue;

			FIFO_enqueue(fifo_buf, new_student);
			DPRINT("\n [INFO] Roll Number (%d) saved successfully", new_student.roll);
		}
		DPRINT("\n [INFO] Students Details Added Successfully....");
		fclose(in_file);
		total_students(fifo_buf);
	}
}

//Prints student info with entered roll number
void find_roll_number(FIFO_buff_t* fifo_buf)
{
	if(fifo_buf->count == 0)
	{
		DPRINT("\n\t =========System is Empty========\n");
	}
	else
	{
		element_type* temp = fifo_buf->tail;
		int id = 0;

		DPRINT("\n Enter The Roll Number of Student: ");
		scanf("%d", &id);

		while(temp != fifo_buf->head)
		{
			if(temp->roll == id)
			{
				DPRINT("\n\t =========Student Details===========\n\
						\n The First name : %s \
						\n The Second name: %s \
						\n The GPA: %0.2f", temp->fname, temp->lname, temp->gpa);
				for(int i = 0; i < 5; i++)
					DPRINT("\n The Course ID: %d", temp->cid[i]);
				return;
			}
			temp++;
		}

		DPRINT("\n\t=========Student not in System========\n");
	}
}

//Prints student info with entered First name
void find_first_name(FIFO_buff_t* fifo_buf)
{
	if(fifo_buf->count == 0)
	{
		DPRINT("\n\t =========System is Empty========\n");
	}
	else
	{
		element_type* temp = fifo_buf->tail;
		char name[40];

		DPRINT("\n Enter The First name of Student: ");
		gets(name);

		while(temp != fifo_buf->head)
		{
			if(stricmp(temp->fname, name) == 0)
			{
				DPRINT("\n\t =========Student Details===========\n\
						\n The Roll Number: %d\
						\n The First name : %s \
						\n The Second name: %s \
						\n The GPA: %0.2f", temp->roll,temp->fname, temp->lname, temp->gpa);
				for(int i = 0; i < 5; i++)
					DPRINT("\n The Course ID: %d", temp->cid[i]);
				return;
			}
			temp++;
		}

		DPRINT("\n\t=========Student not in System========\n");
	}
}

//Prints all students info with entered Course ID
void find_c(FIFO_buff_t* fifo_buf)
{
	if(fifo_buf->count == 0)
	{
		DPRINT("\n\t =========System is Empty========\n");
	}
	else
	{
		element_type* temp = fifo_buf->tail;
		int id;
		char student_no = 1;

		DPRINT("\n Enter The Course ID: ");
		scanf("%d", &id);

		while(temp != fifo_buf->head)
		{
			for(int i = 0; i < 5; i++)
			{
				if(temp->cid[i] == id)
				{
					if(student_no == 1)
					{
						DPRINT("\n\t =========Student Details===========\n");
					}
					DPRINT("\n\t\t Student NO.%d\n \
							\n The Roll Number: %d \
							\n The First name : %s \
							\n The Second name: %s \
							\n The GPA: %0.2f\n", student_no,temp->roll,temp->fname, temp->lname, temp->gpa);
					student_no++;
				}
			}
			temp++;
		}
		if(student_no == 1)
			DPRINT("\n [ERROR] Course ID %d not found....\n", id);
	}
}

//Deletes Student with entered Roll Number
void delete_student(FIFO_buff_t* fifo_buf)
{
	if(fifo_buf->count == 0)
	{
		DPRINT("\n\t =========System is Empty========\n");
	}
	else
	{
		element_type* temp = fifo_buf->tail;
		int id;

		DPRINT("\n Enter The Roll Number of Student: ");
		scanf("%d", &id);

		while(temp != fifo_buf->head)
		{
			if(temp->roll == id)
			{
				//Circular FIFO
				if(fifo_buf->tail == fifo_buf->base + (fifo_buf->length * sizeof(element_type)))
					fifo_buf->tail = fifo_buf->base;
				else
					fifo_buf->tail++;

				fifo_buf->count--;
				DPRINT("\n [INFO] The Roll Number %d is Removed Successfully", id);
				return;
			}
			temp++;
		}

		DPRINT("\n [ERROR] The Roll Number %d is not found\n", id);
	}
}

//Updates the INFO desired of student with entered ID
void update_student(FIFO_buff_t* fifo_buf)
{
	if(fifo_buf->count == 0)
	{
		DPRINT("\n\t =========System is Empty========\n");
	}
	else
	{
		element_type* temp = fifo_buf->tail;
		int id;

		DPRINT("\n Enter The Roll Number of Student: ");
		scanf("%d", &id);

		while(temp != fifo_buf->head)
		{
			if(temp->roll == id)
			{
				int option;
				DPRINT("\n\t Choose one of the following to Change: \n\
						\n 1: First Name \
						\n 2: Last Name\
						\n 3: Roll Number\
						\n 4: GPA \
						\n 5: Courses\
						\n Enter Option Number: ")
				scanf("%d", &option);

				switch(option)
				{
				case 1:
					DPRINT("\n Enter New First Name: ");
					gets(temp->fname);
					break;
				case 2:
					DPRINT("\n Enter New Last Name: ");
					gets(temp->lname);
					break;
				case 3:
					DPRINT("\n Enter New Roll Number: ");
					scanf("%d", &(temp->roll));
					break;
				case 4:
					DPRINT("\n Enter New GPA: ");
					scanf("%f", &(temp->gpa));
					break;
				case 5:
					DPRINT(" Enter the Course ID of Courses\n")
					for(uint16 i = 0; i < 5; i++)
					{
						DPRINT(" Course %i ID: ", i+1);
						scanf("%d", &(temp->cid[i]));
					}
					break;
				default:
					DPRINT("\n [ERROR] Wrong Option")
					return;

				}

				DPRINT("\n [INFO] UPDATED SUCCESSFULLY....");
				return;
			}
			temp++;
		}

		DPRINT("\n [ERROR] The Roll Number %d is not found\n", id);
	}
}

//Application Specific FIFO_Print
void show_students(FIFO_buff_t* fifo_buf)
{
	if(fifo_buf->count == 0)
	{
		DPRINT("\n\t =========System is Empty========\n");
	}
	else
	{
		element_type* temp = fifo_buf->tail;
		char student_no = 1;

		DPRINT("\n\t =========Student Details===========\n");
		while(temp != fifo_buf->head)
		{
			DPRINT("\n\t\t Student NO.%d\n \
					\n The Roll Number: %d \
					\n The First name : %s \
					\n The Second name: %s \
					\n The GPA: %0.2f", student_no,temp->roll,temp->fname, temp->lname, temp->gpa);
			for(uint8 i= 0; i< 5; i++)
			{
				DPRINT("\n Course %i ID: %d", i+1, temp->cid[i]);
			}
			DPRINT("\n")
			student_no++;
			temp++;
		}
	}
}
