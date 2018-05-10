#define _CRT_SECURE_NO_WARNINGS
#include "Cstring.h"

int STORED = w1::MAX;

namespace w1
{
	Cstring::Cstring(char* cons_string/*=""*/)
	{
		if (cons_string)
		{
			strncpy(mystring, cons_string, STORED);
		}
	}
	std::ostream & Cstring::display(std::ostream& ostr)
	{
		ostr << mystring << std::endl;
		return ostr;
	}
	std::ostream & operator<<(std::ostream& ostr, Cstring myCstring)
	{
		myCstring.display(ostr);
		return ostr;
	}
}