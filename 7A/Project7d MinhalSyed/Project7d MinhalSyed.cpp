// Project7d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{

	char sourceString[]="A string to look at";
	char destinationString[20];
	int length;//Length will hold the integer value returned by strlen
	int count;

	length=strlen(sourceString);//Find length of sourceString
	printf("\n\nThe length of the source string is %d.",length);

	strupr(sourceString);//Change sourceString to upper case characters
	printf("\n\nSource String after strupr:%s",sourceString);

	strlwr(sourceString);//Change sourceString to lower case characters
	printf("\nSource String after strlwr:%s",sourceString);

	for(count=0;count<length;count++)
		destinationString[count]=sourceString[count];
	
	printf("\n\nsourceString holds:%s",sourceString);
	printf("\n\nDestinationString holds:%s",destinationString);
	
	getch();
	return 0;
}
