// Project3 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>


int main (void)
{

	char brother[]="Fred, why do you ask?";
		/*In the case of assigning a "string 
		constant" to a character string, you can let the compiler 
		automatically assign the number of elements. This doesnt work if 
		you are inputting data into a characer string later through*/

	char brother2[9+1]="Billy bob";//( chars-Billy Bob and end space for null
	char sister[15];//USer will input characters into this string -spaces must be reserved

	char mother[20];
	char firstName[10];
	char lastName[20];

	printf("\n\nYour brothers name is: %s", brother);
	printf("\nMy other brother is: %s", brother2);

	printf("\n\nEnter your sisters name and press ENTER:");
	scanf("%s", sister);	//No & before sister
	printf("Your sister's name is: %s",sister);

	printf("\n\nEnter your mother's name and press ENTER:");
	scanf("%s", mother); //no & before mother
	printf("Your mothers name is: %s", mother);

	printf("\n\nEnter your first name and press ENTER:");//See NOTE below
	scanf("%s", firstName);
	printf("\nEnter your last name and press ENTER:");
	scanf("%s",lastName);
	printf("\nYour first name is %s and your last name is %s.", firstName, lastName);
	printf("\nYour name is %s %s.", firstName,lastName);//Space left between the
														// %s and %s will leave space between and last names
	
	getch();
	return 0;
}
