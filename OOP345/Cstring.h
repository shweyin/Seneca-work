#pragma once
#include <iostream>
#include <cstring>

namespace w1
{
	const int MAX = 3;
	class Cstring
	{
		char mystring[MAX + 1];
	public:
		Cstring(const char* cons_string = "");
		std::ostream& display(std::ostream&);
	};
	std::ostream& operator<<(std::ostream&, Cstring);
}