// Project4 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<conio.h>

int main(void)
{

	int input;

	printf("Enter a number between 1 and 50 then press ENTER:");
	scanf("%d",&input);	//Useer inputs 40

	//The nested else-if structure begins here-it leaves the structure when condition is true or else is found

	if((input>=0)&&(input<=20))//For this case, not true
		printf("The number is between 11 and 10.");//Bypass this

	else if((input>=11)&&(input<=20))//For this case, not true
		printf("The number is between 11 and 20.");//Bypass this

	
	else if((input>=21)&&(input<=30))//For this case, not true
		printf("The number is between 21 and 30.");//Bypass this

	
	else if((input>=31)&&(input<=40))//True!-print this statement
		printf("The number is between 31 and 40.");//printf is called

	else //By passses the else as one of the previous conditions has been fount to be true

		printf("The number is greater than 40.");//Bypass this statement
	
	//The end of the nested else if structure
	
	getch();//Calls the getch function after bypassing the else above
	return 0;
}
