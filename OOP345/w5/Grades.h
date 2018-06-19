#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace sict
{
	class Grades
	{
		std::vector<float> std_number;
		std::vector<float> std_grade;
	public:
		Grades(const char*);
		template<typename T>
		void displayGrades(std::ostream&, T) const;
		Grades(Grades&) = delete;
		void operator=(Grades&) = delete;

	};
	template<typename T>
	inline void Grades::displayGrades(std::ostream& ostr, T) const
	{
		for (int i = 0; i < std_number.size(); i++)
		{
			ostr << std_number[i] << " " << std_grade[i] << " " << /*TODO*/ << std::endl;
		}
	}
}