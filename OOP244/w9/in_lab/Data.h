#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH = 15;
	const int HEADING_WIDTH = 20;

	// max returns the largest item in data
	//
	template<typename T>
	T max(T* data_array, int n)
	{
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (data_array[index] < data_array[i])
			{
				index = i;
			}
		}
		return data_array[index];
	}

	// min returns the smallest item in data
	//
	template<typename T>
	T min(T* data_array, int n)
	{
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (data_array[index] > data_array[i])
			{
				index = i;
			}
		}
		return data_array[index];
	}

	// sum returns the sum of n items in data
	//    

	template<typename T>
	T sum(T* data_array, int n)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += data_array[i];
		}
		T mySum = sum;
		return mySum;
	}

	// average returns the average of n items in data
	//
	template<typename T>
	double average(T* data_array, int n)
	{
		double myAvg = sum(data_array, n);
		return myAvg / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(std::istream& input, T* data, int n)
	{
		bool good = !input.bad();
		for (int i = 0; i < n; i++)
		{
			input.ignore(2000, ',');
			input >> data[i];
		}
		return good;
	}
	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* column_name, T* data_array, int n)
	{
		std::cout << std::setw(HEADING_WIDTH) << std::right << column_name;
		for (int i = 0; i < n; i++)
		{
			std::cout << std::setw(COLUMN_WIDTH) << data_array[i];
		}
		std::cout << std::endl;
	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);

	template<typename T>
	bool readRow(std::istream & input, const char * name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
}

