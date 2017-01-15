// Project7c MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{

	char forward[]="string";//Declare forward as string with line "string"
	printf("Before strrev():%s\n",forward);//Prints regularly

	strrev(forward);//Calll strrev function-string affected appears in the round brackets

	printf("After strrev(): %s\n",forward);//Prints reverse
	
	getch();
	return 0;
}
