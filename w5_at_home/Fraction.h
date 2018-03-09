// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
#include <iostream>
using namespace std;
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int gcd() const;
		void reduce();
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		int max() const;
		int min() const;
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction& operator+(const Fraction&);
		Fraction& operator*(const Fraction&);
		Fraction& operator==(const Fraction&);
		Fraction& operator!=(const Fraction&);
		Fraction& operator+=(const Fraction&);

	};

}

#endif