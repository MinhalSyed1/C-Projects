// project12d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	FILE*inputFile;		//File pointer
	char SIN[12];	//SI number
	char code;		//Employee code

	inputFile=fopen("E:payroll.txt","r");//"r"for read from file

	if(inputFile==NULL)//check to see if file will open or can be found
	{
		printf("\nThe input file is not available.");
		printf("\nPress ENTER to exit...");//Once user presses ENTER program dumps 
		getch();
		exit(1);//Exit function requires<stdlibh>in preprocessing directives
	}

	printf("\n	HOURTLY EMPLOYEES CODE\n\n");
		//Read all the records in the file and print the hourly employees

	while(	!feof	(inputFile))//While fscanf has not reached the end of the file
	{
		fscanf(inputFile,"%s%c",SIN,&code);//Read in text from file and place in variables,
										   //each of which will be overwritten for each loop
		if(code=='H')
				printf("\t%s	\tHOURLY\n",SIN);
		else
			printf("\t%s\tSALARIED\n",SIN);
		
		fgetc(inputFile);//Looks for the ENTER key entered at the end of text file

	}//End while

	fclose(inputFile);//Close the file
	getch();	
	return 0;
}
