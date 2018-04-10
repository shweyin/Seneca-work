#include "Data.h"

namespace sict {
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		std::cout << "Population change from " << year[0] << " to " << year[n-1]
			<< " is " << std::setprecision(4) 
			<< static_cast<double>(population[n-1] - population[0]) / 1000000 << " million" << std::endl;
		
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		char verdict[10] = "up";
		if (violentCrime[0] > violentCrime[n-1]) { strcpy(verdict, "down"); }
		std::cout << "Violent Crime trend is " <<  verdict << std::endl;

		// Q3 print the GTA number accurate to 0 decimal places

		std::cout << "There are " << std::setprecision(2) << std::fixed << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << std::endl;


		// Q4. Print the min and max violentCrime rates

		std::cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << std::endl
			<< "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << std::endl;
	}
	
}