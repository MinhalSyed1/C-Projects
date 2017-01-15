// Project3d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)

{

		char name[5];	//Define a String of characters
	
		name[0]='E';//String first position is 0!
		name[1]='d';
		name[2]='d';	
		name[3]='y';	
		name[4]=0;	//Null character-end of text

	printf("The name is %s.\n", name); //Print out whole string
	
	printf("A single letter of the string is %c.\n", name[2]);
			//Note the %c prints out single characters stored in element 2
	
	printf("part of the name is %s.\n",&name[1]);
			//Prints out namke from element 1 onwards, 
			//an ampersand is needed herer as the character string ddoesnt start at first element.

	getch();
	return 0;
}
