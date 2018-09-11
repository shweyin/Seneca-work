#pragma once
#include <iosteam>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename T>
class DataTable {
	std::vector<T> x;
	std::vector<T> y;
public:
	T mean() const;
	T sigma() const;
	T median() const;
	void regression(T& slope, T& y_intercept) const;
	void display(std::ostream&) const;
};
template<typename T>
std::istream& operator<<(std::ostream&, const DataTable<T>&);

template<typename T>
T DataTable<T>::mean() const
{
	T sum = 0;
	for (int i = 0; i < x.size()); i++)
	{
	sum += y[i];
	}
	return sum / x.size();
}

template<typename T>
T DataTable<T>::sigma() const
{
	double sd = 0.0;
	for (int i = 0; i < x.size()); i++)
	{
		sd += std::pow(y[i] - mean(), 2);
	}
	return std::sqrt(sd / x.size());
}

template<typename T>
T DataTable<T>::median() const
{
	return T();
}
