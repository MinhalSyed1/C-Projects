// MinhalSyed 7e.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char name[50];//string variable can hold up to 49 characters
	int counter;//For loop increment variable

	printf("Enter in a name in lowecase characters\n");
	scanf("%s",name);
	for(counter=0;name[counter]!=0;counter++)
		
		//The variable counter in [] counts the number of letters in the string in the for loop limit

			name[counter]=toupper(name[counter]);
	//The for statement limit, name [counter]!=0; shows the string of characters will be 
	//read until the null character is found at the end of the string

		printf("The name is in uppercase is %s",name);

	getch();
	return 0;
}
