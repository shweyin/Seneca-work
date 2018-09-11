#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

namespace sict
{
	class Grades
	{
		std::vector<double> std_number;
		std::vector<double> std_grade;
	public:
		Grades(const char*);
		template<typename T>
		void displayGrades(std::ostream&, T) const;
		Grades(Grades&) = delete;
		void operator=(Grades&) = delete;

	};
	template<typename T>
	inline void Grades::displayGrades(std::ostream& ostr, T func) const
	{
		for (size_t i = 0; i < std_number.size(); i++)
		{
			ostr << std::fixed << std::setprecision(0) << std_number[i] << " " 
				 << std::setprecision(2) << std_grade[i] << " " << letterToGrade(func(std_grade[i])) << std::endl;
		}
	}
}