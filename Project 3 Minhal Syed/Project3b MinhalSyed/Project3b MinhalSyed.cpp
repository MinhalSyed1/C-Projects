// Project3b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	
	char firstName[20];
	char lastName[20];
	char wholeName[30];

	printf("Enter the first name...and press Enter:");//Input Jean
	scanf("%s", firstName);
	printf("Enter the last name...and press Enter:");//Input Rpusseauz
	scanf("%s", lastName);
	fflush(stdin);//Need a to flush characters out of keyboard buffer
	printf("Enter the whole name...include a space...and press ENTER:");
	scanf("%[^\n]",wholeName);
	printf("%s, %s, %s", firstName, lastName, wholeName);
	
	getch();
	return 0;
}
