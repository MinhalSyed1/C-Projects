// Project13b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
struct sales //structure name sales

{
int recordNumber;		//Member name for record number
int IDnumber;			//Member name for ID number
char salesfName[10];	//Member for salesperson's first name
char sales1Name[15];	//Member for salesperson's last name
float totalSales;		//Member name for total sales
float costSales;		//Member name for cost of sales
float proft;			//Member name for profit derived value
};
struct sales record[100];	//create 100 records in structure

//SET UP HEADINGS

char heading{}="Your Name \tSALES PROFIT REPORT\tDate\n";

//MAIN FUNCTION

int main(void)
{
	//DECLARE FUNCTIONS

	int menuChoicefn(void);							//user chooses option
	void updateSalesfn(int,struct sales record[]);	//update members of structure
	void addSalesfn(int,struct sales record[]);		//add sales record
	void deleteSalesfn(int,struct sales record[]);	//delete member values in row
	void displaySalesfn(int,struct sales record[]);	//display records in struct
	void profitSalesfn(int,struct sales record[]);	//calculate profits
	void exitProgram(int,struct sales record[]);	//exit, print txt file

	//DECLARE VARIABLES
	
	FILE*salesPtr;		//Create pointer for input text file
	int sub, sub1;		//Counter loops
	int sub2=0;			//Counter for number of records updated
	int choice;			//Input variable for choice
	int sentinerl=1;	//Sentinel int for do while loop

//Open text file to read

	salesPtr=fopen("E:assnsales.txt","r");
	if (salesPtr==NULL)
	{
		printf("\nFile E:assnsales.txt could not be opened. Program will exit.");
		getch();
		exit(1);
	}



	while(!feof(salesPtr))//Load structure from text file
	{
		for(sub=0;sub<5; sub++)//put fscanf code all on one line
		{
			fscanf(salesPtr, "%d %d %s %s %f %f",&record[sub].recordNumber,
			&record[sub].IDnumber,record[sub].salesfName, record[sub].sales1Name,
			&record[sub].totalSales,&record[sub].costSales);

			fgetc(salesPtr);
			sub2++;	//Counter to keep track of number of records
		}
	}//End while loop

	fclose(salesPtr);	//Close file
	printf(heading);	//Print Heading

	for(sub1=0; sub1<sub2;sub1++)	//Show user the current file records
	{					//before going to menu
		printf("\n%2d\t%3d\t%7s\t%9s\t %8.2f\t%8.3f\n",record[sub1].recordNumber,
			record[sub1].IDnumber, record[sub1].salesfName,record[sub1].sales1Name,
			record[sub1].totalSales,record[sub1].costSales);
	}

	printf("\n\tBEFORE YOU START................");
	printf("\n\n\tThere are now %d recordsi n your file.",sub2);
	printf("\n\tRemember or write down the row numbers....");
	printf('\n\n\tPlease press ENTER to reach main menu.");
		getch();

	do	//do while loop for error checking
	{	//call to menu function for user selection

		choice=menuChoicefn();	//Call menu user choice function

		switch(choice)		//switch structure for user options
		{
		case 1:
			updateSalesfn(sub2,record);	//Call to update sales function
			break;

		case 2:
			addSalesfn(sub2,record);	//Call to add sales row function
			sub2=sub2+1;
			break;

		case 3:
			deleteSalesfn(sub2,record);	//Call to delete row values function
			break;

		case 4:
			displaySalesfn(sub2,record);//Call to display sales records function
			break;

		case 5:
			profitSalesfn(sub2,record);	//Call to calculate profit function
			break;

		case 6:
			exitProgram(sub2,record);	//copy to output file, close proram
			sentinel=0;		
			break;

		default:
			printf("You have chosen an invalid option. Press Enter and try again.");
			getch();	//option checker
			break;

		}//end switch structure
	}//end do while loop
	while(sentinel!=0);
	return 0;
	
}//end of main function

	//FUNCTION DEFINITIONS
	//Menu Function

	int menuChoicefn(void)
	{
		int choice;

		//Prompt user for menu choice options

		system("cls");

	printf(heading);
		printf("\n\nPlease enter a number 1 -6 for your choice of options");
		printf("\n\nUpdate Sales Records>>>>1");
		printf("\n\nAdd Sales Records>>>>>>>2");
		printf("\n\nDelete Sales Records>>>>3");
		printf("\n\nDisplay Sales Records>>>>4");
		printf("\n\nView Sales Profits>>>>>>5");
		printf("\n\nExit the program>>>>>>>>6");
		printf("\n\nPlease enter tour option and press Enter: ");
		scanf("%d",&choice);
		fflush(stdin);
		return(choice);

	}//End function


	//Option 1 UPDATE MEMBERS IN SALES STRUCTURE

	void updateSalesfn(int sub2, struct sales record[])
	{
		//declare variables
		int recNum; //User input record number
		int sub;	//for loop counter

		//Prompt user for input information

		system("cls");
		printf(heading);
		printf("\nPlease Enter the record number of the row to be updated:");
		scanf("%d",&recNum);

		for(sub=0;sub<sub2+1;sub++)
		{
			if(record[sub].recordNumber==recNum)
			{
				system("cls");

				printf("\nYou are updating record # %d"< record[SUB].recordNumber);
				printf("\n\nPlese enter the salesperson's ID number:");
				scanf("%d",&record[sub].IDnumber);
				printf("\nPlease enter the salesperson's first name:");
				scanf("%s",record[sub].salesfName);
				printf("\nPlease enter the salesperons last name:");
				scanf("%s",record[sub].sales1Name);
				printf("\nPlease enter the total sales:");
				scanf("%f", &record[sub].totalSales);
				printf("\nPlease enter the cost of sales:");
				scanf("%f",&record[sub].costSales(;

				//Show user updated information

				system("cls");
				printf("\n\n\tYour updated record:");
				printf("\n ID#FirstName\LastName\t Sales Costs\n");
				printf("\n%2d%3d%7s%9s%8.2f%8.2f",record[sub].recordNumber,
				record[sub].IDnumber,record[sub].salesfName,record[sub].sales1Name,
				record[sub].totalSales, record[sub].costSales);
				printf("\n\n\tPress ENTER to return to main menu:");
			}
		}
		getch();
		return;
	}

	//Option 2 ADD SALES FIGURES TO ROW MEMBERS

	void add Salesfn(int sub2, struct sales record[])
	{
		//Declare variables
		int sub;		//Counter for for loop

		//Give user look at current situation of files
		system("cls");
		printf("\n\nHere are your current file records.\n\n");
		printf("\n ID#FirstName\LastName\t Sales Costs\n");
		for(sub=0;sub<sub2;sub++)
		{
			printf("\n%2d %3d %7s %9s %8.2f %8.2f\n", record[sub].recordNumber,
				record[sub].IDnumber,record[sub].salesfName, record[sub].sales1Name,
				record[sub].totalSales,record[sub].costSales);

		}
		printf("\n\nPress ENTER to continue:");
		fflush(stdin);
		getch();
		system("cls");
		print(heading);

		//user inputs new values
		system("cls");
	
		printf("\n\nPlease enter the new record number:");
		scanf("%d",&record[sub].recordNumber);
		printf("\nPlease enter the salesperon's ID number:");
		scanf("%d",&record[sub].IDnumber);
		printf("{;ease enter the salesperson's first name:");
		scanf("%s",record[sub].salesfName);
		printf("\nPlease enter the salesperson's last name:");
		scanf("%s",record[sub].sales1Name);
		printf("\nPlease enter the total sales:");
		scanf("%f",&record[sub].totalSales);
		printf("\nPlease enter the cost of sales:");
		scanf("%f",&record[sub].costSales);

		//New values are put on screen for confirmation

		fflush(stdin);
		system("cls");

		printf("\n\n\tYour added record");
		printf("\n   ID#FirstName\LastName\t   Sales   Costs\n");
		printf("\n%2d %3d %7s %9s %8.2f %8.2f",record[sub].recordNumber,
		record[sub].IDnumber, record[sub].salesfName,record[sub].sales1Name,
		record[sub].totalSales,record[sub].costSales);
						printf("\n\n\tPress ENTER To return to see records:");
				getch();

				//Updated records are displayed

				system("cls");
				printf("\n\nHere is your updated file of records.\n");
				printf("\n");
					printf("\n ID#FirstName\LastName\t Sales Costs\n");
					for(sub=0;sub<2+1;sub++)
					{
						printf("\n%2d%3d%7s%9s%8.2f\n",record[sub].recordNumber,
							record[sub].IDnumber,record[sub].salesfName, record[sub].sales1Name,
							record[sub].totalSales,record[sub].costSales);
					}
					printf("\n\nPlease press ENTER to return to main menu:");
					getch();

					return;
	}

	//Option 3 DELETE VALUES FROM A RECORD ROW

	void deleteSalesfn(int sub2, struct sales record[])
	{
		//declare variables
		int entry;	//User input record number
		int sub;	//counter for loop

		system("cls");
		printf("\nPlease enter the record number for row deletion:");
		scanf("%d",&entry);
		fflush(stdin);


		for(sub=0;sub<2+1;sub++)
		{
			if(record[sub].recordNumber==entry)
			{

				record[sub].IDnumber=0;
				strcpy(record[sub].salesfName,"null");
				strcpy(record[sub].sales1Name,"null");
				record[sub].totalSales=0;
				record[sub].costSales=0;
				record[sub].proft=0;
			}
		}//end for loop
		//Show user updated recprds woth delete
		system("cls");
		printf("\n\nHere is your updated file of records.\n");
		printf("\n   ID#FirstName\LastName\t   Sales   Costs\n");

		for(sub=0;sub<sub2;sub++)
		{
			printf("\n%2d %2d %7s %9s %7.2f %8.2f\n",record[sub].recordNumber,
			record[sub].IDnumber,record[sub].salesfName, record[sub].sales1Name,
			record[sub].totalSales,record[sub].costSales);
		}

		printf("\n\nPlease press ENTER to return to main menu:");
		getch();
		return;
	}

	//Option 4 DISLPAY SALES RECORDS

	void deleteSalesfn(int sub2, struct sales record[])
	{
		//Declare variables
		int sub;   //Counter for loop
			
		//Read and print structure elements to the screen
		system("cls");

		printf("\n\nHere is your updated file of records.");
		
		printf("\n   ID#FirstName\LastName\t   Sales   Costs\n");
		


		for(sub=0;sub<sub2+1;sub++)
		{
			printf("\n%2d %2d %7s %9s %7.2f %8.2f\n",record[sub].recordNumber,
			record[sub].IDnumber,record[sub].salesfName, record[sub].sales1Name,
			record[sub].totalSales,record[sub].costSales);

		}//end for loop

		printf("\n\nPlease press ENTER to return to main menu:");
		getch();
		return;
	}
	//Option 5 SHOW SALES RECORDS AND PROFIT FIGURES
		
	void profitSalesfnint sub2, struct sales record[])
	{
		//declare variables
		int sub;//counter for for loop


		for(sub=0;sub<2+1;sub++)	//calc.derived value profit for each rec
		{
			record[sub].profit=record[sub].totalsales-record[sub].costSales;
		}
		//display updated files to user

