// Project2b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	char letter;


	printf("Please enter an upper or a lower case letter and press ENTER:");
	scanf("%C",&letter);//Input and address char value
	fflush(stdin);//Claer keyboard buffer

	printf("\nThe letter you chose %c", letter);//Original Input character
	printf("\nThe letter you inputted in hex is %x.",letter);//Converts to hex
	printf("\nThe letter you inputted in octal is %o.",letter);//Converts to octal
	printf("\nThe letter you inputted in decimal is %d.",letter);//Converts to decimal


	getch();
	return 0;
}
