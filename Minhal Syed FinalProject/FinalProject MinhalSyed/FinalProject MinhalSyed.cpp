/***************************************************/
/*			Final Project-Minhal Syed 			   */
/*                                                 */
/*  This program will be a bibliography maker.     */
/*	The sources you use will be sorted and inputed */
/*  into this bibliography maker and outputted to  */
/*  a text file ready to be used. The output wil   */
/*  be in MLA or APA format.                       */
/*                                                 */
/*          By: Minhal Syed                        */
/*          Run Date: 26/01/2016                   */
/***************************************************/

#include "stdafx.h"
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream.h>

struct information //Declare structure data type above main function
{
	char Title[40];
	char AuthorName[40];
	char PublishingCompany[40];
	char Location[40];
	char SectionTitle[40];
	char WebsiteTitle[40];
	char URL[40];
	char Date[40];
		
	int StartingPageNumber;
	int EndingPageNumber;
};

int main(void)
{

system("TITLE Minhal Syed - Final Project");


//To initialize the structure
struct information book1[30]={"Harry Potter","J.K.Rowling","BloomsBary", "England", "Chapter 5", 1997, 67,68};

//*************************//
//	FUNCTIONS PROTOTYPES   //
//*************************//
char PrintHeading				();											//Function to print the heading

int CitationBook				(struct information book1[30]);				//Function for book citation

void CitationWeb				(struct information book1[30]);				//Function for Web citation

void CitationMedia				(struct information book1[30]);				//Function for CitationMedia

void BookPrint					(struct information book1[30], int);		//Function for BookPrint

void WebPrint					(struct information book1[30]);				//Function for WebPrint

void MediaPrint					(struct information book1[30]);				//Function for MediaPrint

void End						();											//Function for End

//******************//
//		Variables	//
//******************//

char choice1;	//Choice1 as a char

int choice3;	//Choice3 as an int

do{				//do while loop to restart the program if the user makes a mistake

choice1 = PrintHeading();	//Choice1=PrintHeading()

switch(choice1)	//Switch statement for choice1
{

//If Case a then
case 'A': 

case 'a':	

	cout<<"You have chosen A. Opening book citation."<<endl;

	//choice3 in the function is equal to CitationBook(book1)
	choice3=CitationBook(book1);

	//Calling function
	BookPrint(book1, choice3);

	//Break
	break;

//If Case B then
case 'B': 

case 'b':	
	
	
	cout<<"You have chosen B. Opening web citation."<<endl;

	//CitationWeb with structure
	CitationWeb(book1); 
	
	//Calling Function
	WebPrint(book1);

	//Break
	break;

//If Case C then
case 'C': 

case 'c':	
	
	cout<<"You have chosen C. Opening media citation."<<endl;
	
	//CitationMedia with structure
	CitationMedia(book1);
	
	//Calling function
	MediaPrint(book1);

	//Break 
	break;

	//If none of thr options are chosen...
default:cout<<"You entered an invalid character."<<endl;
choice1='1';
	//break
	break;


}//End switch structure

getch();	//To hold the page until the user presses enter

system ("cls");	//Clear screen after user presses enter

//While loop saying if choice1 does not equal a b or c it will restart
}while(choice1=='1');


End();


//return
	return 0;
}

//heading function
char PrintHeading(void)
{
char choice1;

	//Printing the following to the output screen
	cout<<"\t************************************"<<endl;
	cout<<"\t**    **Bibliography Project**    **"<<endl;
	cout<<"\t************************************"<<endl;
    cout<<"\t** The sources you use will be    **"<<endl;
	cout<<"\t** inputted into this program and **"<<endl;
	cout<<"\t** will be outputted to a text    **"<<endl;
	cout<<"\t** file in APA or MLA format.    **"<<endl;
	cout<<"\t** The target users are students  **"<<endl;
	cout<<"\t** who strugle with citations.    **"<<endl;
	cout<<"\t************************************"<<endl<<endl;
	
	//Printing to the screen
	cout<<"The sources this program will take are:"<<endl;

	cout<<"\tBooks"<<endl;

	cout<<"\tWebsites"<<endl;

	cout<<"\tMedia Sources"<<endl;

	cout<<"\nPlease press ENTER to continue..."<<endl;

	//To hold the page until user presses enter
	getch();
	
	//Clear screen after user presses enter
	system("cls");

	cout<<"\t\nPlease press enter in a choice from below"<<endl<<endl;

	cout<<"A\tBook"<<endl;

	cout<<"B\tWebsite"<<endl;

	cout<<"C\tTv/Radio"<<endl;

	//scaning to see the user choice for choice1 variable
	cin>> choice1;

	//returning choice1 to the main function
return (choice1);
}

//CitationBook Function
int CitationBook(struct information book1[30])
{
	//Declating new variables
	int choice3;

	int i=0;
	
	//clearing the screen
	system("cls");

	cout<<"Enter in 1 if you would like to cite a particular section."<<endl;
	
	cout<<"Enter in 2 to cite the whole book."<<endl;

	//scaning to see the user choice for choice3 variable
	cin>>choice3;

//Switch structure for the user choice
switch (choice3)
{

//if choice3 is 1 than
case 1:	
{
	//For loop to run the program once
	for(i=1;i<2;i++)
	{
	//clear page
	 system("cls");

	 cout<<"Enter in the name of the source: "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Title);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the author's name(Last, First,Middle): "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].AuthorName);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the publishing company: "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].PublishingCompany);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the location it was published: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Location);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the date it was published: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Date);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the sections title: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].SectionTitle);

	 cout<<"Enter in the starting page number: "<<endl;

	 //Scanning the user choice into the structure
	 cin>>book1[i].StartingPageNumber;

	 cout<<"Enter in the ending page number: "<<endl;

	 //Scanning the user choice into the structure
	 cin>>book1[i].EndingPageNumber;

	}
	
break;


//If choice3 is 2 then
case 2:
{
	//clear page
	 system("cls");

	 cout<<"Enter in the name of the source: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Title);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the author's name(Last, First,Middle): "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].AuthorName);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the publishing company: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].PublishingCompany);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the location it was published: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Location);

	 //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the date it was published: "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Date);
	
}
}
	//break
	break;
//if none of the options are chosen
default:cout<<"You entered an invalid number."<<endl;
	
	//Break
	break;

}
//return choice 3 to main
return (choice3);
}


//CitationWeb
void CitationWeb(struct information book1[30])
{
	//Declaring variables
	int i=0;

	system("cls");


//for loop to run this code once
	for(i=1;i<2;i++)
	{
	//clear system
	 system("cls");

	 cout<<"Enter in the name of the source: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Title);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the author's name(Last, First,Middle): "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].AuthorName);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the publishing company: "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].PublishingCompany);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the date it was published: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Date);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the Website title: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].SectionTitle);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the URL: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].URL);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the Date Acessed<D M Y>: "<<endl;

	 //Scanning the user choice into the structure
	 cin>>book1[i].StartingPageNumber;

}



//return
return;
}

void CitationMedia(struct information book1[30])

{
	int i=0;

	for(i=1;i<2;i++)
	{
	 system("cls");

     cout<<"Enter in the author's name(Last, First,Middle): "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].AuthorName);


	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the name of the source: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Title);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the publishing company: "<<endl;
	
	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].PublishingCompany);

	  //clears keyboard
	 fflush(stdin);

	 cout<<"Enter in the date it was published: "<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].Date);

	 fflush(stdin);

	 cout<<"Enter in if it was TV or Radio :"<<endl;

	 //Scanning the user choice into the structure
	 scanf("%40[^\n]",book1[i].SectionTitle);

	 fflush(stdin);
	}

//return
return;

}

//BookPrint Function with struct and int choice3
void BookPrint(struct information book1[30], int choice3)
{
//declaring a variable
int i;

//code to output to text file
fstream outputfile;

outputfile.open("E:Print.txt",ios::out);

//if statement saying if choice3=1 then
if (choice3==1)
{
//clear system
system("cls");

cout<<"MLA"<<endl;

//repeat for loop once
for(i=1; i<2; i++)
{
cout<<book1[i].AuthorName<<" "<<book1[i].Title<<" "<< book1[i].Location<<" "<< book1[i].PublishingCompany<<" "<< book1[i].Date<<endl;
outputfile<<"MLA"<<endl;
outputfile<<book1[i].AuthorName<<" "<< book1[i].Title<<" "<< book1[i].Location<<" "<< book1[i].PublishingCompany<<" "<< book1[i].Date<<endl;
}

cout<<"APA"<<endl;

//repeat for loop once 
for(i=1; i<2; i++)
{
cout<< book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].Title<<" "<<book1[i].Location<<" "<<book1[i].PublishingCompany<<endl;
outputfile<<"APA"<<endl;
outputfile<< book1[i].AuthorName<<" "<<book1[i].Title<<" "<<book1[i].Location<<" "<<book1[i].PublishingCompany<<" "<<book1[i].Date<<endl;
}
outputfile.close();
}

//if choice3=2 then
if (choice3==2)
{
//system clear 
system("cls");

cout<<"MLA"<<endl;

//for loop repeating once 
for(i=1; i<2; i++)
{
cout<< book1[i].AuthorName<<" "<<book1[i].SectionTitle<<" "<<book1[i].Title<<" "<<book1[i].Location<<" "<<book1[i].PublishingCompany<<" "<<book1[i].Date<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].EndingPageNumber<<endl;
outputfile<<"MLA"<<endl;
outputfile<<" "<<book1[i].AuthorName<<" "<<book1[i].SectionTitle<<" "<<book1[i].Title<<" "<<book1[i].Location<<" "<<book1[i].PublishingCompany<< book1[i].Date<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].EndingPageNumber<<endl;
}

cout<<"APA"<<endl;

//repeat for loop once 
for(i=1; i<2; i++)
{
cout<<book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].Title<<" "<<book1[i].SectionTitle<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].EndingPageNumber<<" "<<book1[i].Location<<" "<<book1[i].PublishingCompany<<endl;
outputfile<<"APA"<<endl;
outputfile<<book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].Title<<book1[i].SectionTitle<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].EndingPageNumber<<" "<<book1[i].Location<<" "<<book1[i].PublishingCompany<<endl;
}
outputfile.close();
}


return;
}


//function webprint with struct 
void WebPrint(struct information book1[30])
{
//declaring variables 
int i;

//output to text file
fstream outputfile;

outputfile.open("E:Print.txt",ios::out);

//system clear
system("cls");

cout<<"MLA"<<endl;

//repeat for loop once 
for(i=1; i<2; i++)
{
cout<< book1[i].AuthorName<<" "<<book1[i].SectionTitle<<" "<<book1[i].Title<<" "<<book1[i].PublishingCompany<<" "<<book1[i].Date<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].URL<<endl;
outputfile<<"MLA"<<endl;
outputfile<<book1[i].AuthorName<<" "<<book1[i].SectionTitle<<" "<<book1[i].Title<<" "<<book1[i].PublishingCompany<<" "<<book1[i].Date<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].URL<<endl;
}

cout<<"APA"<<endl;

//repeat for loop once 
for(i=1; i<2; i++)
{
cout<<book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].SectionTitle<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].URL<<endl;
outputfile<<"APA"<<endl;
outputfile<<book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].SectionTitle<<" "<<book1[i].StartingPageNumber<<" "<<book1[i].URL<<endl;
}
outputfile.close();
return;
}

//function MediaPrint with struct 
void MediaPrint(struct information book1[30])
{
	//declaring variable 
	int i;
	
	//output to text file
	fstream outputfile;

	outputfile.open("E:Print.txt",ios::out);

	//clear system
	system("cls");

	cout<<"MLA"<<endl;

	//repeat for loop once 
	for(i=1; i<2; i++)
	{	
	cout<<book1[i].AuthorName<<" "<<book1[i].Title<<" "<<book1[i].PublishingCompany<<" "<<book1[i].Date<<" "<<book1[i].SectionTitle<<endl;
	outputfile<<"MLA"<<endl;
	outputfile<<book1[i].AuthorName<<" "<<book1[i].Title<<" "<<book1[i].PublishingCompany<<" "<<book1[i].Date<<" "<<book1[i].SectionTitle<<endl;
	}	
	cout<<"APA"<<endl;

	//repeat for loop once 
	for(i=1; i<2; i++)
	{
	cout<<book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].Title<<" "<<book1[i].SectionTitle<<" "<<book1[i].PublishingCompany<<endl;
	outputfile<<"APA"<<endl;
	outputfile<<book1[i].AuthorName<<" "<<book1[i].Date<<" "<<book1[i].Title<<" "<<book1[i].SectionTitle<<" "<<book1[i].PublishingCompany<<endl;
	}

outputfile.close();
return;
}

//function end
void End()
{

//clear system
system("cls");

cout<<"Thanks you for using my program."<<endl<<endl;

cout <<"Your information will be in a text file named Print in drive E"<<endl<<endl;

cout <<"Make sure to delete the text file after if you wish to run the program again."<<endl<<endl;

cout<<"Press ENTER to exit."<<endl;

return;
}