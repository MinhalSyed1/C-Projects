// Project1d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>

int main(void)
{
cout<<"The decimal(base 10) value of 15 is"<<15
<<"\nThe octal(base 8) value of 15 is"
<<setiosflags(ios::oct)<<15
<<"\nThe hexadecimal(base 16)value of 15 is"
<<setiosflags(ios::hex)<<15
<<endl;
	getch();
	return 0;
}
