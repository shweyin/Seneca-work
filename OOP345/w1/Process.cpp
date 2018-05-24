/*
Student: Shweyin Than
Assignment: Lab 1
Date: 5/10/2018
Subject: OOP345 SAB
*/
#include "Cstring.h"
#include "Process.h"

void process(char* process_string)
{
	w1::Cstring myCstring(process_string);
	//myCstring.display(std::cout);
	std::cout << myCstring;
}
