// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
#include <iostream>
using namespace std;
// TODO: create namespace
namespace sict {
	class Fraction {
		int numerator;
		int denominator;
		int gcd() const;
		void reduce();
	public:
		Fraction();
		Fraction(int, int);
		int max() const;
		int min() const;
		bool isEmpty() const;
		void display() const;
		bool are_empty(const Fraction&);
		Fraction operator+(const Fraction&);
		Fraction operator*(const Fraction&);
		bool operator==(const Fraction&);
		bool operator!=(const Fraction&);
		Fraction operator+=(const Fraction&);
	};

}

#endif