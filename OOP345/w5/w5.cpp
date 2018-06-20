// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}


	sict::Grades grades(argv[1]);
	// lambda expression for converting to letter 

	auto gradeToLetter = [](double gradeDouble) 
	{
		Letter gradeEnum;
		if (gradeDouble >= 90)
		{
			gradeEnum = Aplus;
		}
		else if (gradeDouble >= 80)
		{
			gradeEnum = A;
		}
		else if (gradeDouble >= 75)
		{
			gradeEnum = Bplus;
		}
		else if (gradeDouble >= 70)
		{
			gradeEnum = B;
		}
		else if (gradeDouble >= 65)
		{
			gradeEnum = Cplus;
		}
		else if (gradeDouble >= 60)
		{
			gradeEnum = C;
		}
		else if (gradeDouble >= 55)
		{
			gradeEnum = Dplus;
		}
		else if (gradeDouble >= 50)
		{
			gradeEnum = D;
		}
		else
		{
			gradeEnum = F;
		}
		return gradeEnum;
	};



	grades.displayGrades(std::cout, gradeToLetter);


	// report the error message
	std::cerr << argv[0] << ": Failed to open file "
		<< argv[1] << "\n";
	return 2;
}
