#pragma once
namespace sict {
	enum Letter { Aplus, A, Bplus, B, Cplus, C, Dplus, D, F };

	const char* letterToGrade(const Letter grade)
	{
		switch (grade)
		{
		case Aplus:
			return "A+";
		case A:
			return "A";
		case Bplus:
			return "B+";
		case B:
			return "B";
		case Cplus:
			return "C+";
		case C:
			return "C";
		case Dplus:
			return "D+";
		case D:
			return "D";
		case F:
			return "F";
		}
		return "NA";
	}
}