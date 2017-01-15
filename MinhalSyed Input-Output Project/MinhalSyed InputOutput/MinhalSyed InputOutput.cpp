/**************************************************/
/*          Input-Output Project                  */ 
/*                                                */
/* This project is designed to help people who    */
/* struggle with basic chemistry as it has all    */ 
/* the elements of the periodic table and will    */
/* output the description with all the basic      */
/* information of that element to a text file     */
/* that will save in the users usb and they can   */ 
/* view it at their leisure.                      */
/*                                                */
/*            By:   Minhal Syed                   */
/*            Date: December 09, 2015             */
/**************************************************/

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<iostream>
int main(void)
{

/*************************/
//	FUNCTIONS PROTOTYPES //
//************************/
void PrintHeading				(void);

void FileRead1					(int[30], int, char[30][20],int);

void FileRead2					(int[30],int,int,int[30],int[30],char[30][10],char[30][10],float[30]);

void Choice						(int,int,int[30],int,int,int[30],int[30],char[30][10],char[30][10],float[30]);

void Mix						(int,char[10][50],int);

void End						(void);

void End						(void);

/**********************/
//	    VARIABLES     //
//*********************/
int count=0;

int counter=0;

int num[30];

int choice1=0;

int choice2=0;

int error=0;

int ElementGroup[30];

int ElementPeriod[30];

char Element[30][20];

char ElementFormula[30][10];

char ElementCharge[30][10];

char ElementMix[10][50]={"Hydrogen+Oxygen","Carbon+Oxygen","Lithium+Oxygen","Nitrogen+Oxygen","Sodium+Oxygen","Potassium+Oxygen","Flourine+Oxygen","Sodium+Water","Magnesium+Water","Aluminum+Water"}; 

float ElementMass[30];


//*********************/
//  FUNCTION CALLS    //
//*********************/
PrintHeading();

FileRead1(num, count,Element,counter);

FileRead2(num,count,counter,ElementGroup,ElementPeriod, ElementFormula,ElementCharge,ElementMass);

Choice(error,choice1,num,count,counter,ElementGroup,ElementPeriod, ElementFormula,ElementCharge,ElementMass);

Mix(choice2,ElementMix,error);

End();

	getch();
	return 0;
}

//The function needed to print the heading
void PrintHeading()
{
//Naming the program
system("TITLE Minhal Syed - Input/Output Project");

//Changing the Colout
system("color 3A");
	//Printing the following to the output screen
	printf("\t*******************************************\n");
	printf("\t**      **INPUT/OUTPUT PROJECT**         **\n");
	printf("\t*******************************************\n");
	printf("\t** Place a file in the E drive and       **\n");
	printf("\t** choose a number representing an       **\n");
	printf("\t** element and see its basic information **\n");
	printf("\t** or choose to see some chemical        **\n"); 
	printf("\t** reactions.                            **\n");
	printf("\t*******************************************\n\n");

printf("   ----                                                                ----\n");
printf("1 | H |                                                               |He |\n");
printf("  |---+----                                       --------------------+---|\n");
printf("2 |Li |Be |                                       | B | C | N | O | F |Ne |\n");
printf("  |---+---|                                       |---+---+---+---+---+---|\n");
printf("3 |Na |Mg |3B  4B  5B  6B  7B |    8B     |1B  2B |Al |Si | P | S |Cl |Ar |\n");
printf("  |---+---+---------------------------------------+---+---+---+---+---+---|\n");
printf("4 | K |Ca |Sc |Ti | V |Cr |Mn |Fe |Co |Ni |Cu |Zn |Ga |Ge |As |Se |Br |Kr |\n");
printf("  |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
printf("5 |Rb |Sr | Y |Zr |Nb |Mo |Tc |Ru |Rh |Pd |Ag |Cd |In |Sn |Sb |Te | I |Xe |\n");
printf("  |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
printf("6 |Cs |Ba |LAN|Hf |Ta | W |Re |Os |Ir |Pt |Au |Hg |Tl |Pb |Bi |Po |At |Rn |\n");
printf("  |---+---+---+------------------------------------------------------------\n");
printf("7 |Fr |Ra |ACT|\n");
printf("  -------------\n");

getch();

system("cls");	//system cls to clear the screen after output has been read.

return;
}

//File1 Read in. calling down num,count,element and counter
void FileRead1(int num[30], int count,char Element[30][20],int counter)
{

	//Declares counter=0
	counter=0;
	
	//The following code will read an input file.
	FILE*inputfile;
	
	//Opening ElementNumbers1 to read
	inputfile=fopen("D:ElementNumbers1.txt","r");

	//if statement saying if the input file isn't in your e drive
	if(inputfile==NULL)

	//File missing
	printf("missing file");

	//scanning the file for information
	for(count=0;!feof(inputfile);count++)
	{
		fscanf(inputfile,"%d%s",&num[count],Element[count]);
	
		fgetc(inputfile);
	
		counter++;
	}
	
	//Closing the file.
	fclose(inputfile);

	//Printing the information scanned from the file.
	for(count=0;count<counter;count++)
	
	printf("%d\t %s\n",num[count],Element[count]);

	getch();
	return;
}

//File2 Read in. calling down num,count, counter, ElementGroup,ElementPeriod,ElementFormula,ElementCharge,ElementMass
void FileRead2(int num[30], int count,int counter,int ElementGroup[30],int ElementPeriod[30],char ElementFormula[30][10],char ElementCharge[30][10],float ElementMass[30])
{

	//Declares counter=0
	 counter=0;

	 //The following code will read an input file.
	FILE*inputfile;

	//Opening 1 to read
	inputfile=fopen("e:1.txt","r");

	//if statement saying if the input file isn't in your e drive
	if(inputfile==NULL)

	//File missing
	printf("missing file");

	//scanning the file for information
	for(count=0;!feof(inputfile);count++)
	{
		fscanf(inputfile,"%d%d%s%s%f",&ElementGroup[count],&ElementPeriod[count],ElementFormula[count],ElementCharge[count],&ElementMass[count]);	
		
		counter++;
	
		fflush(stdin);
	}
	
	fgetc(inputfile);

	//Closing the file.
	fclose(inputfile);

	getch();

	system("cls");	//system cls to clear the screen after output has been read.
	return;
}


//A function called Choice that is calling down variables from above
void Choice(int error,int choice1,int num[30], int count,int counter,int ElementGroup[30],int ElementPeriod[30],char ElementFormula[30][10],char ElementCharge[30][10],float ElementMass[30])
{

//A do loop for error checking
	do
	{
	error=0;
	printf("\nPlease choose a number corresponding to an element to see its desctription:");
	scanf("%d",&choice1);
	
	//If choice scanned above isn't between 1 and 30 its an invalid choice
	if((choice1<1)||(choice1>30))
{
	printf("\nInvalid choice ");
	error=1;
	getch();
	system("cls");	//system cls to clear the screen after output has been read
}
}while (error==1);

	//The following program is going to output to a file
	FILE*outputFile;
	
	//Outputting to the choice file
	outputFile=fopen("e:Choice.txt","w");
	
	//print to the choice file
	fprintf(outputFile,"Group:%d Period:%d Formula:%s Charge:%s Mass:%f ",ElementGroup[choice1-1],ElementPeriod[choice1-1],ElementFormula[choice1-1],ElementCharge[choice1-1],ElementMass[choice1-1]);

	printf("The information you requested is now on your text file Choice");

	printf("\nPlease press Enter to continue...");
	getch();

	//close the choice file
	fclose(outputFile);

return;
}

//A function called Mix calling down variables from above
void Mix(int choice2, char ElementMix[10][50],int error)
{

system("cls");	//system cls to clear the screen after output has been read.


int choice3=0;
//A do loop for error checking
do
{

error=0;
printf("Out of the 30 elements listed there can be an huge amount of reactions between \nthem."); 
printf("Therefore we have limited your number of choices to 10.");
printf("\n\nPlease select one of the pre-chosen elements to see their reaction:");

printf("\n0) Hydrogen + Oxygen	");
printf("\n1) Carbon + Oxygen	");
printf("\n2) Lithium + Oxygen	");
printf("\n3) Nitrogen + Oxygen	");   
printf("\n4) Sodium + Oxygen	");
printf("\n5) Potassium + Oxygen	");
printf("\n6) Flourine + Oxygen	");
printf("\n7) Sodium + Water		");
printf("\n8) Magnesium + Water	");
printf("\n9) Aluminum + Water\n");

scanf("%d",&choice2);

//If choice scanned above isn't between 1 and 10 its an invalid choice
	if((choice2<0)||(choice2>9))
{
	printf("\nInvalid choice. Please Press Enter to Continue... ");
	error=1;
	getch();
system("cls");	//system cls to clear the screen after output has been read.
}
}while (error==1);


	//Going to output to a file.
	FILE*outputFile;
	
	//output to choice1 file
	outputFile=fopen("e:Choice1.txt","w");
	fprintf(outputFile,"\n%s",ElementMix[choice2] );
	
	//if statements saying if they user chooses 1-10 what will happen
	if (choice2==0)
	fprintf(outputFile,"\nHydrogen and Oxygen combine to make Water");
	
	if (choice2==1)
	fprintf(outputFile,"\nCarbon and Oxygen combine to make Carbon Dioxide");
	
	
	if (choice2==2)
	fprintf(outputFile,"\nLithium and Oxygen combine to make Lithium Oxide");
	
	
	if (choice2==3)
	fprintf(outputFile,"\nNitrogen and Oxygen combine to make Nitrogen Oxide");

	 
	if (choice2==4)
	fprintf(outputFile,"\nSodium and Oxygen combine to make Sodium Peroxide");

	 
	if (choice2==5)
	fprintf(outputFile,"\nPotassium and Oxygen combine to make Potassium Oxide");

	 
	if (choice2==6)
	fprintf(outputFile,"\nFlourine and Oxygen combine to make Oxygen Flouride or Oxygen diflouride");
	
	 
	if (choice2==7)
	fprintf(outputFile,"\nSodium and Water combine to make Sodium Hydroxide and  Hydrogen Gas");

	if (choice2==8)
	fprintf(outputFile,"\nMagensium and Water hane no reaction as amagnesium doesn't react with water but vapour.");

	
	if (choice2==9)
	fprintf(outputFile,"Aluminum and Water combine to make Hydrogen Gas");
	
	
	printf("The information you requested is now on your text file Choice1");

	getch();
//close the choice1 file
fclose(outputFile);	

return;
}

//Ending function
void End()
{

system("cls");	//system cls to clear the screen after output has been read.
printf("Thank you for using my program");

return;
}