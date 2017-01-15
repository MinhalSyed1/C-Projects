// Project2 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)

{

	int num1=3,num2=4,num3=5,num4=6,num5=7,num6=8,sum,product;
	float average;
	char one='o';
	char two='k';
	char three='!';

	sum=num1+num2+num3+num4+num5+num6;
	average=(float)(sum/6);
	product=num1*num2*num3*num4*num5*num6;

	printf("Your first 3 numbers are:\t%3d\t%3d\t%3d\n",num1,num2,num3);
	printf("Your second 3 numbers are:\t%3d\t%3d\t%3d\n",num4,num5,num6);
	printf("The sum of your numbers is:\t%3d\n",sum);
	printf("the average of your numbers is:\t%5.2f\n",average);
	printf("The product of your number is:\t%6d\n\n",product);
	printf("This is the end of this program! %c%c%c\n\n",one,two,three);
	printf("\t\tPress ENTER to exit the program!\n");
















	getch();
	return 0;
}
