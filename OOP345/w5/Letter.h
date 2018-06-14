#pragma once
namespace sict {
	enum Letter { Aplus, A, Bplus, B, Cplus, C, Dplus, D, F };

	template<typename T>
	char* convert_grade(const T grade)
	{
		char gradestring[3];
		switch (grade)
		{
		case Aplus:
			std::strncpy(gradestring, "A+");
			break;
		case A:
			std::strncpy(gradestring, "A");
			break;
		case Bplus:
			std::strncpy(gradestring, "B+");
			break;
		case B:
			std::strncpy(gradestring, "B");
			break;
		case Cplus:
			std::strncpy(gradestring, "C+");
			break;
		case C:
			std::strncpy(gradestring, "C");
			break;
		case Dplus:
			std::strncpy(gradestring, "D+");
			break;
		case D:
			std::strncpy(gradestring, "D");
			break;
		case F:
			std::strncpy(gradestring, "F");
			break;
		}
		return gradestring;
	}
}