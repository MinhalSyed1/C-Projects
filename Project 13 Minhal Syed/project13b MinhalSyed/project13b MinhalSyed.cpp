// project13b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

struct gender
{
	char initial;	//last nameinitial
	int age;		//Childs age
	int grade;		//Childs Grade in School
};
int main(void)
{
	struct gender boy,girl;//Declare structure variables
	int count;
	
	boy.initial='R';
	boy.age=15;
	boy.grade=75; //continued next page

	girl.age=boy.age-1;//She is one year younger
	girl.grade=82;
	girl.initial='H';

	printf("%c is %d years old and got a grade of %d\n",
						girl.initial,girl.age,girl.grade);

	printf("%c is %d years old and got a grade of %d\n",
						boy.initial,boy.age,boy.grade);



	getch();
	return 0;
}
