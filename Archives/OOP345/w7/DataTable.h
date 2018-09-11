//Shweyin Than 115675175 
//OOP345 Workshop 8 - STL Algorithms

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <fstream>
#include <cmath>

namespace w8 {
	template <class T>
	class DataTable {
		std::vector<T> x;
		std::vector<T> y;
		int FW;
		int prec;
	public:
		DataTable(std::ifstream& ifstr, int, int);
		T mean() const;
		T sigma() const;
		T median() const;
		void regression(T& slope, T& y_intercept) const;
		void display(std::ostream&) const;
	};

	template<class T>
	inline DataTable<T>::DataTable(std::ifstream& ifstr, int fieldWidth, int precision)
	{
		std::string myString;
		while (std::getline(ifstr, myString))
		{		
			std::istringstream myStringStream;
			myStringStream.str(myString);
			T x_val;
			T y_val;
			myStringStream >> x_val >> y_val;
			x.push_back(x_val);
			y.push_back(y_val);
		}
		FW = fieldWidth;
		prec = precision;
	}

	template<class T>
	inline void DataTable<T>::display(std::ostream& ostr) const
	{
		ostr << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;
		for (unsigned int i = 0; i < x.size(); i++)
		{
			ostr << std::setw(FW) << std::fixed << std::setprecision(prec) << x[i];
			ostr << std::setw(FW) << std::fixed << std::setprecision(prec) << y[i] << std::endl;
		}
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& ostr, const DataTable<T>& temp_obj)
	{
		temp_obj.display(ostr);
		return ostr;
	}

	template<class T>
	inline T DataTable<T>::mean() const
	{
		T total = 0;
		for (unsigned int i = 0; i < x.size(); i++)
		{
			total += x[i];
		}
		return total / x.size();
	}

	template<class T>
	inline T DataTable<T>::sigma() const
	{
		T deviation = 0.0;
		for (unsigned int i = 0; i < y.size(); i++) {
			deviation += (y[i] - mean()) * (y[i] - mean());
		}
		return std::sqrt(deviation / y.size());
	}

	template<class T>
	inline T DataTable<T>::median() const
	{
		std::vector <T> temp = y;
		std::sort(temp.begin(), temp.end());
		T median = temp[temp.size() / 2];
		return median;
	}

	template<class T>
	inline void DataTable<T>::regression(T& slope, T& y_intercept) const
	{
		T avg_x = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
		T avg_y = std::accumulate(y.begin(), y.end(), 0.0) / y.size();
		T top = 0.0;
		T bot = 0.0;

		for (int i = 0; i < x.size(); ++i)
		{
			top += (x[i] - avg_x) * (y[i] - avg_y);
			bot += (x[i] - avg_x) * (x[i] - avg_x);
		}
		slope = top / bot;
		y_intercept = avg_y - (slope * avg_x);
	}
}

