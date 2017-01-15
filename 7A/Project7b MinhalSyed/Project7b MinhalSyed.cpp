// Project7b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{

	char letter[10];
	char input[2]="c"; //Double quotes for string, even though one character

	do
	{
		printf("\n\nTry and guess a letter between 'a' and'z'");
		printf("\nEnter your choice and press ENTER:");
		scanf("%s",letter);//remember no & sign for strings!

		if(strcmp(letter,input)!=0)//Not equal to 0?
		printf("\nGuess Again!");

	}while(strcmp(letter,input)!=0);//Not equal to 0?
	//As long as a '0' is not returned, we know the users guess is wrong and loop continues

	printf("\n\nGood GUess!!!");//Reach here after 0 is returned from do while loop
	printf("\nPress ENTER to exit...");
	getch();
	return 0;
}
