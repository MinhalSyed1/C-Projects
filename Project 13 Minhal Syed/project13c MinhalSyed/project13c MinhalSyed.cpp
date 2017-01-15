// project13c MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

struct array
{
	char initial;
	int age;
	int grade;
};

int main(void)
{

	struct array kids[12];	//Declare array of records
	int count;

	for(count=0; count<12; count++)
	{
		kids[count].initial='A'+count;
		kids[count].age=16;
		kids[count].grade=84;
	}

	kids[3].age=kids[5].age=17;
	kids[2].grade=kids[6].grade=92;
	kids[4].grade=57;

	kids[10]=kids[4];//Structure assignment-all 3 elements of kids[4] overwrite the corresponding elements in kids[10]

	for(count=0;count<12;count++)
		printf("%c is %d years old and got a grade of %d\n",
		kids[count].initial,kids[count].age,kids[count].grade);	
	getch();
	return 0;
}
