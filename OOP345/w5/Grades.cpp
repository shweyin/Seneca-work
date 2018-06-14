#include "Grades.h"

namespace sict
{
	Grades::Grades(const char* filename)
	{
		std::fstream fs;
		fs.open(filename);
		if (fs.is_open())
		{
			float temp1;
			float temp2;
			while (!std::cin.eof())
			{
				std::cin >> temp1;
				std_number.push_back(temp1);
				std::cin >> temp2;
				std_number.push_back(temp2);
			}
		}
		else
		{
			throw ("poop");
		}
	}
}