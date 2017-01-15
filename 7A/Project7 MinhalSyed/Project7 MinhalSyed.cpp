// Project7 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{
	//Declare character strings
	char name1[12],name2[12],title[30];

	//String copy-strcpy
	strcpy(name1,"Moe");//Put moe characters in string name1
	strcpy(name2,"Barney");//Put Barney characters in string name2
	strcpy(title,"String Copy Function");//Put title characters into string title

	printf("	%s\n\n",title);
	printf("Name 1 is %s\n",name1);
	printf("Name 2 is %s\n",name2);

	printf("\nNow we'll put copy name 2 into name 1.");
	strcpy(name1,name2);	//Copyname2 into name1
	printf("\nName 1 is now %s", name1);
	
	getch();
	return 0;
}
