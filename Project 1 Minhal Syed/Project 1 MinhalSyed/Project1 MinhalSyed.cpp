// Project1 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<conio.h>
int main(void)

{

	//One method of declaring variables
	int num1=3, num2=4, num3=5, num4=6, num5=7, num6=8,sum,product;
	//Second method of declaring variables
	float average;
	char one='o';
	char two='k';
	char three='!';

			//Note the different methods of declaring variables

	sum=num1+num2+num3+num4+num5+num6;
	average=(float)(sum/6); //The (float) is an example of csdting, see later
	product=num1*num2*num3*num4*num5*num6;

	//You can print out more than 1 variable on a line...
	//Spacing of printed out integers has been done manually by leaving spaces between %3d's

	printf("Your first 3 numbers are: %3d %3d %3d\n", num1, num2, num3);
	printf("Your second 3 numbers are: %3d %3d %3d\n", num4, num5,num6);
	printf("The sum of your numbers is: %3d\n",sum);
	printf("The average of your numbers is: %5.2f\n",average);
	printf("The product of your number is %3d\n\n",product);
	printf("This is the end of this program! %c%C%C\n\n",one,two,three);
	printf("\t\tPress ENTER to exit the program!\n"); 
	//Not the tab escape sequences	
	
	
	
	getch();
	return 0;
}
