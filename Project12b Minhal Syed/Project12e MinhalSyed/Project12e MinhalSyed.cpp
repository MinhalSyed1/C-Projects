// Project12e MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	FILE*inputFile;
	FILE*outputFile;	//File pointers, 1 for input, 1 for output
	char lastName[20],stuNum[12];
	int courseCode,semestCode,flag=1;

	inputFile=fopen("E:stugrad.txt","r");	//open the input file to read
	outputFile=fopen("E:stucopy.txt","w");	//Open the output file to write
//File open testing has been left out for space considerations
	//Use previous progeam as sample
printf("Stand by for processing...");
printf("Your File Contents...\n\n");

	while(flag==1)//Checks to see that file copy routine is complete
	{
	while(!feof(inputFile))
	{
	fscanf(inputFile,"%s%s%d%d",lastName,stuNum,&courseCode,&semestCode);

	fgetc(inputFile);
	fprintf(outputFile,"\n%s%s%d%d",lastName,stuNum,courseCode,semestCode);
	printf("\n\n%s %d%d%d",lastName,stuNum,courseCode,semestCode);

	}//End inner while

	fclose(inputFile);
	fclose(outputFile);

	flag=0;
	}//end outer while
	getch();
	return 0;


















	getch();
	return 0;
}
