/*
 * linked_list.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */

#include "linked_list.h"
extern SStudent_t* g_p_FirstStudent;

//APIs
//Student project main functions
void Linked_Add_Student(void)
{
	SStudent_t* p_LastStudent;
	SStudent_t* p_NewStudent;
	if(!g_p_FirstStudent) // The linked list is empty
	{
		//make new record
		p_NewStudent = (SStudent_t*) malloc(sizeof(SStudent_t));

		//p_NewStudent valid?
		if(p_NewStudent != NULL)
		{
			//fill new record
			Linked_Fill_Record(p_NewStudent);
			g_p_FirstStudent = p_NewStudent;
		}
		else
		{
			DPRINT("\n =========Failed to add Student========\n");
		}
	}
	else //The linked list contains Students
	{
		p_LastStudent = g_p_FirstStudent;

		//keep going until the p_LastStudent next pointer points at null (it's at the last item in list)
		while(p_LastStudent->p_NextStudent)
			p_LastStudent = p_LastStudent->p_NextStudent;

		p_NewStudent = (SStudent_t*) malloc(sizeof(SStudent_t));

		//p_NewStudent valid?
		if(p_NewStudent != NULL)
		{
			Linked_Fill_Record(p_NewStudent);
			p_LastStudent->p_NextStudent = p_NewStudent;
		}
		else
		{
			DPRINT("\n =========Failed to add Student========\n");
		}

	}
}

void Linked_Fill_Record(SStudent_t* NewStudent)
{
	char temp_text[40];
	DPRINT("\n Enter Student Name: ");
	gets(NewStudent->student.name);

	DPRINT("\n Enter Student ID: ");
	gets(temp_text);
	NewStudent->student.id = atoi (temp_text);

	DPRINT("\n Enter Student height: ");
	gets(temp_text);
	NewStudent->student.height = atof (temp_text);

	NewStudent->p_NextStudent = NULL;
}

int Linked_Delete_Student(void)
{
	SStudent_t *p_SelectedStudent = g_p_FirstStudent;
	SStudent_t *p_PrevStudent = NULL;
	uint32 selected_id;

	DPRINT("\nEnter Student ID To Be Deleted: ");
	scanf("%u", &selected_id);

	if(g_p_FirstStudent)	//list is not empty
	{
		while(p_SelectedStudent)
		{
			if(p_SelectedStudent->student.id == selected_id)
			{
				if(p_PrevStudent) //1st student != ID
				{
					p_PrevStudent->p_NextStudent = p_SelectedStudent->p_NextStudent;
				}
				else //1st student == ID
				{
					g_p_FirstStudent = g_p_FirstStudent->p_NextStudent;
				}
				free(p_SelectedStudent);
				DPRINT("\nStudent Deleted Successfully....\n")
				return 1;
			}
			p_PrevStudent = p_SelectedStudent;
			p_SelectedStudent = p_SelectedStudent->p_NextStudent;
		}

		DPRINT("\n\tStudent was not found\n");
	}
	else //list is empty
	{
		DPRINT("\n\t List is Empty\n");
	}
	return 0;
}

void Linked_View_Students(void)
{
	SStudent_t* p_CurrentStudent = g_p_FirstStudent;
	uint32 count = 1;

	if(p_CurrentStudent == NULL)
	{
		DPRINT("\n\t List is Empty\n");
	}
	else
	{
		while(p_CurrentStudent)
		{
			DPRINT("\n Record number (%d)", count);
			DPRINT("\n \t Name: %s", p_CurrentStudent->student.name)
			DPRINT("\n \t ID: %d", p_CurrentStudent->student.id);
			DPRINT("\n \t Height: %0.2f", p_CurrentStudent->student.height);
			p_CurrentStudent = p_CurrentStudent->p_NextStudent;
			count++;
		}
	}
}

void Linked_Delete_All(void)
{
	SStudent_t* p_CurrentStudent = g_p_FirstStudent;
	if(p_CurrentStudent == NULL)
	{
		DPRINT("\n\tList is Empty\n");
	}
	else
	{
		while(p_CurrentStudent)
		{
			SStudent_t* p_TempStudent = p_CurrentStudent;
			p_CurrentStudent = p_CurrentStudent->p_NextStudent;
			free(p_TempStudent);
		}
		g_p_FirstStudent = NULL;
		DPRINT("\nAll Students Deleted Successfully....\n")
	}
}

//Extra assignment functions
int Linked_Get_Nth(void)
{
	SStudent_t* p_CurrentStudent = g_p_FirstStudent;
	uint32 count = 0, index = 0;
	DPRINT("\nEnter Index: ");
	scanf("%u", &index);

	if(g_p_FirstStudent)
	{
		while(p_CurrentStudent)
		{
			if(count == index)
			{
				DPRINT("\n Record number (%d)", count + 1);
				DPRINT("\n \t Name: %s", p_CurrentStudent->student.name)
				DPRINT("\n \t ID: %d", p_CurrentStudent->student.id);
				DPRINT("\n \t Height: %0.2f", p_CurrentStudent->student.height);
				return 1;
			}
			else
			{
				p_CurrentStudent = p_CurrentStudent->p_NextStudent;
				count++;
			}
		}
		DPRINT("\n\tIndex is Outside the List\n");
	}
	else //list is empty
	{
		DPRINT("\n\t List is Empty\n");
	}
	return 0;
}

int Linked_Find_Length(SStudent_t* head)
{
	if(head)
		return 1 + Linked_Find_Length(head->p_NextStudent);
	else
		return 0;
}

int Linked_Value_from_end(void)
{
	SStudent_t* p_Front = g_p_FirstStudent;
	SStudent_t* p_End = g_p_FirstStudent;
	uint32 index = 1, count = 1;
	DPRINT("\nEnter Index from the End: ");
	scanf("%d", &index);

	if(g_p_FirstStudent)
	{
		while(p_Front)
		{
			if(count < index) //make difference between front and end = index
			{
				p_Front = p_Front->p_NextStudent;
				count++;
			}
			else if(p_Front->p_NextStudent == NULL) // front reached the last element
			{
				DPRINT("\n Record number (%d) from End", index);
				DPRINT("\n \t Name: %s", p_End->student.name)
				DPRINT("\n \t ID: %d", p_End->student.id);
				DPRINT("\n \t Height: %0.2f", p_End->student.height);
				return 1;
			}
			else
			{
				p_End = p_End->p_NextStudent;
				p_Front = p_Front->p_NextStudent;
				count++;
			}
		}

		DPRINT("\n\tIndex is Outside the List\n");
	}
	else //list is empty
	{
		DPRINT("\n\t List is Empty\n");
	}
	return 0;
}

void Linked_Middle(void)
{
	SStudent_t* p_Fast = g_p_FirstStudent;
	SStudent_t* p_Slow = g_p_FirstStudent;
	uint32 count = 1;
	if(g_p_FirstStudent)
	{
		while(p_Fast->p_NextStudent)
		{
			p_Fast = p_Fast->p_NextStudent;
			//check first if it's the last element
			if(p_Fast->p_NextStudent)
				p_Fast = p_Fast->p_NextStudent;
			p_Slow = p_Slow ->p_NextStudent;
			count++;
		}

		DPRINT("\n Record number (%d)", count);
		DPRINT("\n \t Name: %s", p_Slow->student.name)
		DPRINT("\n \t ID: %d", p_Slow->student.id);
		DPRINT("\n \t Height: %0.2f", p_Slow->student.height);

	}
	else //list is empty
	{
		DPRINT("\n\t List is Empty\n");
	}
}

void Linked_Reverse_list(void)
{
	SStudent_t* p_CurrentStudent = g_p_FirstStudent;
	SStudent_t* p_PrevStudent = NULL;
	SStudent_t* p_NextStudent = NULL;
	if(g_p_FirstStudent)
	{
		/*//to make the first item points at null
		p_NextStudent = p_CurrentStudent->p_NextStudent;
		p_CurrentStudent->p_NextStudent = NULL;
		p_PrevStudent = p_CurrentStudent;
		p_CurrentStudent = p_NextStudent;
*/
		while(p_CurrentStudent)
		{

			p_NextStudent = p_CurrentStudent->p_NextStudent;
			p_CurrentStudent->p_NextStudent = p_PrevStudent;
			p_PrevStudent = p_CurrentStudent;
			p_CurrentStudent = p_NextStudent;

		}
		g_p_FirstStudent = p_PrevStudent;
		DPRINT("\n\tList Reversed Successfully....");
	}
	else //list is empty
	{
		DPRINT("\n\t List is Empty\n");
	}
}
