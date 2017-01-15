// Project12 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(void)
{
	FILE*outputFile;//Pointer to file memory location-asterisk snug to name
	//FILE must be in capital letters
	char textString[25];
	int count;

	//Use the 'fopen' function to open the file on the a: drive to write
	outputFile=fopen("E://textLines.txt","w");//Open for writing
	strcpy(textString,"This is an example line.");//String copy function <string.g>

	for(count=1; count<=10; count++)
	{
	//The fprintf function prints to the open file on the a:drive
		
		fprintf(outputFile,"%s Line Numbwe %d\n",textString,count);
	
		//Always a good idea to 'echo' file output to the sctreen
		printf("%s Line number%d\n",textString,count);
	}
	fclose(outputFile);//Close the file before ending the program
	
	getch();
	return 0;
}
