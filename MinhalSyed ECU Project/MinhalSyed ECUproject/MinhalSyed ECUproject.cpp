/***************************************************/
/*			ECU Program-Minhal Syed 			   */ 
/*                                                 */
/*  This program will mimic what an ECU does by    */ 
/*  reading the inputs from the handpicked sensors */ 
/*  and using formulas to determine what is going  */ 
/*  on and what needs to be adjusted so the "car"  */
/*  runs at peak efficiency.                       */
/*                                                 */
/*                                                 */
/*          By: Minhal Syed                        */
/*          Run Date: 13/11/2015                   */
/***************************************************/

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
void PrintHeading				(void);									//Function tot print the heading

void ChangeSpeeds				(int,int[8], int[8]);					//Function to calculate change in speeds

void ThrottleSensor				(int[8],int,float[9]);					//Function to calculate the throttle position sensor

void MAPSensor					(float[9],int[8], int,float[8]);		//Function to calculate the MAP sensor

void CrankshaftSensor			(int[8],int,int[8]);					//Function to calculate the Crankshaft sensor

void airSensor					(int[8],int,int[8]);					//Function to calculate the airSensor

void OxygenSensor				(int[8],int, int[8],int[8]);			//Function to calculate the OxygenSensor

void EngineCoolantSensor		(int[8],int,int[8]);					//Function to calculate the EngineCoolantSensor

void CarAnimation				(int,char[128],char[128],int,int);		//Function that does a small animation

void Results					(int[8],int,int,int[8],int[8],float[8],float[9],int[8], int[8]);	//Function to print the results

void End						(void);									//Function for the end

//*************************************/
//		LOCAL VARIABLES				  //
//*************************************/
int count;				//Counter

int counter=0;			//Counter is equated to 0

int counta;				//Counter2	

int RPM[8];				//Declares rpm as an int array with 8 values

int temperature[8];		//Declares temperature as an int array with 8 values

int speeds[8];			//Number of speeds

int ChangeS[8];			//Change in speeds

int Oxygen[8];			//Declares oxygen as an int array with 8 values.

int air[8];				//Declares air as an int array with 8 values

int a=0;				//Sets a as 0

int b=0;				//sets b as 0

char time1[128];		//string to record time
	
char time2[128];		//string to record time

float AirIntake[8];		//Declares AirIntake as a float array with 8 values

float Angle[9];			//Declares angle as a float array with 8 values





//Changing the title of the project and the colours
	system("TITLE Minhal Syed - ECU Project");

	WORD wOldColorAttrs;                                                                                              
	
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                                                             
	
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);  
	
	GetConsoleScreenBufferInfo(h, &csbiInfo); 
	
	wOldColorAttrs = csbiInfo.wAttributes;
	
	SetConsoleTextAttribute ( h, BACKGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY );
	
	system("cls");



//Calling the CarAnimation and the PrintHeading function
//These are out of the for loop as you don't want these to run everytime.

CarAnimation(counter,time1,time2,a,b);
PrintHeading();

//*********************/
//	Reading File      //
//*********************/
//Code to read the file into the program

FILE*inputFile;

inputFile=fopen("E:speeds.txt","r");

//If no sensor than the program will end
if(inputFile==NULL)
{
	printf("\nThe input file is not available.");
	
	printf("\nPress ENTER to exit...");//Once user presses Enter program dumps
	
	getch();
	
	exit(1);
}

for(count=0;!feof(inputFile);count++) //For loop which exits at the end of the file
{

	fscanf(inputFile,"%d",&speeds[count]);//Gets speeds from the disk
	
	fgetc(inputFile);
	
	counter++;
}
	fclose(inputFile);

for(count=0;count<8;count++)

ChangeSpeeds(count,speeds, ChangeS);

printf("Change in Speeds");

for(count=0;count<8;count++)

printf("\n\t%d\t",ChangeS[count]);

printf("\n\nFrom 0 to 10 the car is accelerating and more air is used by the engine.");

//code for sorting acceleration, coast, deceleration
for(counta = 0; counta < count-1; counta++)

	{
		
		if(speeds[counta] > speeds[counta + 1]) // if the first speed is greater than the second (decelerating)
		{
			printf("\n\nFrom %.2d to %.2d the car is decelerating, and less air is being taken into the engine.", 
			
			speeds[counta], speeds[counta+ 1]);
			
			printf("\nPlease press ENTER to continue...");

			getch(); // holds the screen until the user is ready to move on to the next interval
		}

		else if(speeds[counta] == speeds[counta + 1]) // if the two speeds are equal to each other (constant)
		{
			printf("\n\nFrom %2d to %2d the car is staying at a constant speed, and the amount of", speeds[counta], 
			
			speeds[counta + 1]);
			
			printf("\nair in the engine remains the same.\n");

			printf("\nPlease press ENTER to continue...");

			getch(); // holds the screen until the user is ready to move on to the next interval
		}
		else if(speeds[counta] < speeds[counta + 1]) // if the first speed is less than the second speed (accelerating)
		{
			printf("\n\nFrom %2d to %2d the car is accelerating, and more air is used in the engine.\n", 
			
			speeds[counta], speeds[counta + 1]);
			
			printf("\nPlease press ENTER to continue...");

			getch(); // holds the screen until the user is ready to move on to the next interval
		}
		
	
}
//***********************/
// CALLING FUNCTIONS	//
//***********************/
for (count=0;count<counter;count++)
{

ThrottleSensor			(speeds,count,Angle);

MAPSensor				(Angle, speeds, count,AirIntake);

CrankshaftSensor		(speeds,count,RPM);

airSensor				(speeds, count, air);

OxygenSensor			(speeds, count, air,Oxygen);

EngineCoolantSensor		(speeds, count,temperature);

Results					(speeds,counter,count,Oxygen,RPM,AirIntake,Angle,ChangeS,temperature);

printf("\n\nPlease press ENTER to continue...");

getch();		//getch to hold the code
system("cls");	//system cls to clear the screen after output has been read.

}
End ();

	getch();
	return 0;

}
void PrintHeading()
{

system("color 7E");
	//Printing the following to the output screen
	printf("\t************************************\n");
	printf("\t**    **ECU PROJECT**             **\n");
	printf("\t************************************\n");
	printf("\t** Place a file in the E drive    **\n");
	printf("\t** named speeds so the program can**\n");
	printf("\t** read it and determine the most **\n");
	printf("\t**efficent fuel oxygen ratio.     **\n");
	printf("\t************************************\n\n");
	
	printf("This program will take the speeds to calcluate the following");

	printf("\n\n\tChange in speeds (Acceleration, Coasting or Deacceleration)");

	printf("\n\n\tThrottle Postion Sensor");

	printf("\n\n\tM.A.P. Sensor");

	printf("\n\n\tCrankshaft Sensor");

	printf("\n\n\tOxygen Sensor");

	printf("\n\n\tEngine Coolant Sensor\n");
	
	printf("\n\nPlease press ENTER to continue...");
	getch();
	return;
}

	
//Change speeds function is calling down count, speeds and ChangeS
void ChangeSpeeds(int count, int speeds[8], int ChangeS[8])
{	

ChangeS[count]=speeds[count]-speeds[count-1];

system("cls");

if (count==0)

ChangeS[count]=speeds[count]-0;

return;
}	




//ThrottleSensor function is calling down count,speeds and Angle	
void ThrottleSensor(int speeds[8], int count, float Angle[9])
{

float AnglePercentage[9];

AnglePercentage[count]=((float)speeds[count]/220)*100;

Angle[count]=45-(0.45*AnglePercentage[count]); 

printf("\n\nThe angle of the Throttle Position Sensor is %.2f Degrees",Angle[count]);

return;
}




//MAPSensor function is calling down count,speeds and Angle	
void MAPSensor(float Angle[9], int speeds[8],int count,float AirIntake[8])
{

AirIntake[count]=(Angle[count]*speeds[count]);

printf("\nThe Air Volume is %.2f L", AirIntake[count]);

return;
}



//Crankshaft function is calling down count and speeds  
void CrankshaftSensor(int speeds[8],int count,int RPM[8])
{

RPM[count]=(20*speeds[count])*2;

printf("\nThe crankshaft sensor is going %d RPM.", RPM[count]);

return;
}




//AirSensor function is calling down count, speeds and Air	
void airSensor(int speeds[8],int count, int air[8])
{

air[count]=(float)speeds[count]/2+10;

return;
}

//OxygenSensor function is calling down count, speeds and Air	
void OxygenSensor(int speeds[8],int count, int air[8],int Oxygen[8])
{

Oxygen[count]=air[count]/14.7;

printf("\nThe volume of air that is not being used in combustion is %d Liters.", Oxygen[count]);

return;
}

//EngineCoolantSensor function is calling down count and speeds 
void EngineCoolantSensor(int speeds[8], int count, int temperature[8])
{

int temperature1;

temperature1=(36*speeds[count])/60;

temperature[count]=temperature1+36;

printf("\nThe temperature of the engine is %d degrees celsius.",temperature[count]);

return;
}



//The final reults which will be outputtted to a text file. 
void Results(int speeds[8],int counter,int count,int Oxygen[8], int RPM[8], float AirIntake[8], float Angle[9], int ChangeS[8],int temperature[8])
{
//This declares a file and lets us know a file will be used.
FILE*outputFile;

//Declares if the file would be written
outputFile=fopen("E:Results.txt","w");

//Prints to a text file
fprintf(outputFile,"------\t-------------  --------------  ----------  ---  ------------------\n");
fprintf(outputFile,"SPEEDS\tCHANGE SPEEDS  THROTTLE ANGLE  AIR VOLUME  RPM  ENGINE TEMPERATURE\n");
fprintf(outputFile,"------\t-------------  --------------  ----------  ---  ------------------\n");

//prints to a text file
fprintf(outputFile,"SPEEDS 1\t0km/h\t    N/A\t\t45.0Degrees     0\t  0\t36C       \n");
fprintf(outputFile,"--------------------------------------------------------------------------\n");

//a for loop
for(count=0;count<counter;count++)
{


//prints to a text file
fprintf(outputFile,"SPEEDS %d\t%dkm/h\t",count+2,speeds[count]);

//if change in speeds is greater than 0 the car is accelerating
if(ChangeS[count]>0)
//print to a file with the information from the previous line
	fprintf(outputFile,"ACCELERATION\t");
//if change in speed is equal to 0 the car is coasting
else if(ChangeS[count]==0)
//print to a file with the information from the previous line
	fprintf(outputFile,"  COASTING\t");
//if change in speeds is less than 0 the car is deaccelerating
else if (ChangeS[count]<0)
//print to a file with the information from the previous line
	fprintf(outputFile,"DEACCELERATION\t");

//prints to a text file
fprintf(outputFile,"%.1fDegrees   %.2f\t%d\t%dC      \n",Angle[count],AirIntake[count],RPM[count],temperature[count]);
fprintf(outputFile,"-------------------------------------------------------------------------------------\n");
}

//prints to a text file
fprintf(outputFile,"SPEEDS %d\t0km/h\tDEACCELERATION\t\t45.0Degrees     0\t  0\t36C       \n",counter+2);
fprintf(outputFile,"--------------------------------------------------------------------------------------------\n");

//stop writing in the file.
fclose(outputFile);

return;
}

//The end function; doesn't call down anything
void End()
{
	//prints to the program.
	printf("Thank you for using this Program. Your results have been outputted to a \ntext file called Results in your E drive.");
	printf("\n\nPlease press ENTER to exit...");
}


//The car animation function; calls down a counter, 2 times (time 1 and time 2), int a and int b
void CarAnimation(int counter,char time1[128], char time2[128], int a, int b)
{
a=0;
b=0;
counter=0;

HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
//Counter that changes the colour of the text
		for(counter=0; counter<10; counter++)
{
			switch(counter)
{ 
				case 1: SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		//message printed on screen
printf("                  @@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("           @@@@@@       @@@@@            @@@@@\n");
printf("          @@@@         @@@@@@              @@@@\n");
printf("       @@@@@          @@@@@@@@               @@@@\n");					
printf("     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("    @@@@@@@@@@      @@@@@ @@@@@@@ @@      @@@      @@@@@@@@@@@@@@@@@@@\n");
printf("  .@@@@@@@@@@@ @@@@@@@@@@@@ @@@@@ @@@ @@@@@@@@ @@@@@ @@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@ @@@@@@@@@@@@@ @@@ @@@@ @@@@@@@@ @@@@@ @@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@       @@@@@@@@@ @@@@@@     @@@@ @@@@@ @@@@@@@@@@@@@@@@@@\n");
printf("   @@@@@@@@@@@@@@@@@ @@@@@@@@@ @@@@@@ @@@@@@@@ @@@@ @@@@@@@@@@@@@@@@@\n");
printf("    @@@@@@@@@@       @@@@@@@@@ @@@@@@     @@@@    @@@@@@@@@@@@@@@@@@\n");
printf("           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("           @@@@@@@@@@                                   @@@@@@@@@\n");
printf("            @@@@@@@@                                      @@@@@@\n");


				break;

				case 2: SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY ); 

printf("\t                  @@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t           @@@@@@       @@@@@            @@@@@\n");
printf("\t          @@@@         @@@@@@              @@@@\n");
printf("\t       @@@@@          @@@@@@@@               @@@@\n");					
printf("\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t           @@@@@@@@@@                                   @@@@@@@@@\n");
printf("\t            @@@@@@@@                                      @@@@@@\n");
				
				break;

				case 3: SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_RED | FOREGROUND_INTENSITY );
printf("\t\t                  @@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t           @@@@@@       @@@@@            @@@@@\n");
printf("\t\t          @@@@         @@@@@@              @@@@\n");
printf("\t\t       @@@@@          @@@@@@@@               @@@@\n");					
printf("\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t           @@@@@@@@@@                       @@@@@@@@@\n");
printf("\t\t            @@@@@@@@                          @@@@@@\n");
					
				break;

				case 4:	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

printf("\t\t\t                  @@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t                @@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t           @@@@@@       @@@@@       @@@@@\n");
printf("\t\t\t          @@@@         @@@@@@         @@@@\n");
printf("\t\t\t       @@@@@          @@@@@@@@          @@@@\n");					
printf("\t\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t           @@@@@@@@@@                       \n");
printf("\t\t\t            @@@@@@@@                          \n");
				
				break;

				case 5: SetConsoleTextAttribute (h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					


printf("\t\t\t\t                 @@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t                @@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t           @@@@@@       @@@@@       @@@@@\n");
printf("\t\t\t\t          @@@@         @@@@@@         @@@@\n");
printf("\t\t\t\t       @@@@@          @@@@@@@@          @@@\n");					
printf("\t\t\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t           @@@@@@@@@@          \n");
printf("\t\t\t\t            @@@@@@@@            \n");


			break;


				case 6: SetConsoleTextAttribute (  h, FOREGROUND_GREEN |FOREGROUND_RED | FOREGROUND_INTENSITY );
					


printf("\t\t\t\t\t                  @@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t                @@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t           @@@@@@       @@@       @@@\n");
printf("\t\t\t\t\t          @@@@         @@@@       @@@\n");
printf("\t\t\t\t\t       @@@@@          @@@@@@@     @@\n");					
printf("\t\t\t\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t           @@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t           @@@@@@@@@@	\n");
printf("\t\t\t\t\t            @@@@@@@@           \n");


			break;

				case 7: SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY  );
					


printf("\t\t\t\t\t\t               \n");
printf("\t\t\t\t\t\t                @\n");
printf("\t\t\t\t\t\t           @@@@@@ \n");
printf("\t\t\t\t\t\t          @@@@    \n");
printf("\t\t\t\t\t\t       @@@@@        \n");					
printf("\t\t\t\t\t\t     @@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t           @@@@@@@@@@@@@@@\n");
printf("\t\t\t\t\t\t           @@@@@@\n");
printf("\t\t\t\t\t\t            @@@@@\n");


			break;

				case 8: SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
			printf("");
			break;

}

	//delay function 
	_strtime( time1 );
	 do
{
	_strtime( time2 ); 
	a=(strcmp(time2, time1));
	if (a!=0)
{
	b=b+1;
	_strtime(time1);
}
							
}	while(b!=1);//changing number 1 to higher number increases time lag
	b=0;
	a=0; 
	system("cls");
}
return;
}