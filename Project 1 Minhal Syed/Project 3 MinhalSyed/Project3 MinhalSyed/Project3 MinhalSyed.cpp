// Project3 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
int a;			//Simple integer type
long int b;		//Long integer type
short int c;	//Short integer type
unsigned int d;	//Unsigned integer type
char e;			//Character type
float f;		//floating point type
double g;		//Double precision floating point

a=1023;
b=2222;
c=123;
d=1234;
e='X';
f=3.14159;
g=3.1315926535898;

printf("a=%d\n",a);		//Decimal output
printf("a=%o\n",a);		//Octal output
printf("a=%x\n",a);		//Hexadecimal output
printf("b=%ld\n",b);	//Decimal long output
printf("c=%d\n",c);		//Unsigned output
printf("d=%u\n",d);		//Unsigned output
printf("e=%c\n",e);		//Character Output
printf("f=%f\n",f);		//float output
printf("g=%f\n",g);		//Double float output- if these seem similar check variable assignment above 

printf("\n");
printf("a=%d\n",a); //Simple int output
printf("a=%7d\n",a); //Use a field width of 7
printf("a=%-7d\n",a);//Left justify in field of 7

c=5;//Note re-assigning of variable values in stored memory location
d=8;

printf("a=%*d\n",c,a);//Use a field width of 5
printf("a=%*d\n",d,a);//Use a field width of 8

printf("\n");
printf("f=%f\n",f);		//Simple float output
printf("f=%12f\n",f);	//Use field width of 12
printf("f=%12.3f\n",f);	//Use 3 decimal places
printf("f=%12.5f\n",f);	//Use 5 decimal places
printf("f=%-12.5f\n",f);//Left justify in field

	getch();
	return 0;
}
