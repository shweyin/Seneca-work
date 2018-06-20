#include "Grades.h"

namespace sict
{
	Grades::Grades(const char* filename)
	{
		std::fstream fs;
		fs.open(filename);
		if (fs.is_open())
		{
			double temp1;
			double temp2;
			while (fs>>temp1>>temp2)
			{
				std_number.push_back(temp1);
				std_grade.push_back(temp2);
			}
		}
		else 
		{
			throw ("The file...it's not open");
		}
	}
}