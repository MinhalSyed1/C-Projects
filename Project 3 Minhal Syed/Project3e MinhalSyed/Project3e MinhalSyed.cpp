// Project3e MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{

	char firstName[20];
	char middleName[20];
	char lastName[20];

	printf("Enter your first name and press ENTER: ");//Input Clarence
	gets(firstName);
	printf("Enter your middle name and press ENTER: ");//Input Montgomery
	gets(middleName);
	printf("Enter your last name and press ENTER: ");//Input Burns
	gets(lastName);

	printf("\nYour initials are: %c %c %c",firstName[0],
			middleName[0],lastName[0]);

	printf("\n");//Printf statement needed for nre line character
	puts(firstName);

	puts(middleName);
	puts(lastName);

	printf(firstName);//printf will also display to the screen like puts() although adding formatting wont work ie. 
					  //printf("\n\n", firstName); unless a %s is added
	getch();
	return 0;
}
