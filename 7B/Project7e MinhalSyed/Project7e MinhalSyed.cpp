// Project7e MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{
	char name1[12],name2[12],mixed[25];
	char title[25];

	strcpy(name1,"Moe");//Copy characters into strings
	strcpy(name2,"Barnie");
	strcpy(title,"string Functions");

	printf("%s\n\n",title);//Print strings to screen
	printf("Name1 is %s\n",name1);
	printf("Name2 is %s\n",name2);

	printf("\n\nAre the string identical?");
	if(strcmp(name1,name2)!=0)//Compare strings
		printf("\nThe strings are not the same.");
	else
		printf("\nThe strings are the sane.");
		
	printf("\n\nThe next step might be helpful later when");
	printf("\njoing together a first and last name inputted by the user.");

	strcpy(mixed,name1);//Copy name1 into mixed
	strcat(mixed," ");//Concatenate a space after string in mixed
	strcat(mixed,name2);//join name2 onto string in 'mixed'
	printf("\n\nBoth names Concatenated are:%s\n",mixed);//Printf both names with space betweeen them

	getch();
	return 0;
}
