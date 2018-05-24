/*
Student: Shweyin Than
Assignment: Lab 1
Date: 5/10/2018
Subject: OOP345 SAB
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Cstring.h"

int STORED = w1::MAX;

namespace w1
{
	static int insertion = 0;
	Cstring::Cstring(const char* cons_string/*= ""*/)
	{
		if (cons_string)
		{
			//strncpy(mystring, cons_string, STORED);
			for (int i = 0; i < STORED; i++)
			{
				mystring[i] = cons_string[i];
			}
			mystring[STORED] = '\0';
		}
	}
	std::ostream& Cstring::display(std::ostream& ostr)
	{
		ostr << mystring << std::endl;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, Cstring myCstring)
	{
		ostr << insertion << ": ";
		insertion++;
		myCstring.display(ostr);
		return ostr;
	}
}