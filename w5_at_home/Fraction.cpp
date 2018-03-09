#include <iostream>
// TODO: insert header files
#include "Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict{
	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		numerator = 0;
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numer, int denom)
	{
		if (numer > 0 && denom > 0)
		{
			numerator = numer;
			denominator = denom;
		}
		else
		{
			numerator = 0;
			denominator = 0;
		}
		this->reduce();
	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		int greater;
		if (numerator > denominator)
		{
			greater = numerator;
		}
		else
		{
			greater = denominator;
		}
		return greater;
	}
	// TODO: implement the min query
	int Fraction::min() const
	{
		int lesser;
		if (numerator < denominator)
		{
			lesser = numerator;
		}
		else
		{
			lesser = denominator;
		}
		return lesser;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int tempgcd = gcd();
		numerator = numerator / tempgcd;
		denominator = denominator / tempgcd;
	}
	// TODO: implement the display query
	void Fraction::display() const
	{
		if (numerator == 0 && denominator == 0)
		{
			cout << "no fraction stored";
		}
		else if (denominator == 1)
		{
			cout << numerator;
		}
		else
		{
			cout << numerator << "/" << denominator;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		bool torf = false;
		if (numerator == 0 && denominator == 0)
		{
			torf = true;
		}
		return torf;
	}
	// TODO: implement the + operator
	Fraction& Fraction::operator+(const Fraction& rhs)
	{
		Fraction temp;
		if(!this->isEmpty() && !rhs.isEmpty())
		{
			temp.numerator = numerator*rhs.denominator + denominator*rhs.numerator;
			temp.denominator = denominator * rhs.denominator;
			temp.reduce();
		}
		numerator = temp.numerator;
		denominator = temp.denominator;
		return *this;
	}
	Fraction& Fraction::operator*(const Fraction& rhs)
	{
		Fraction temp;
		if (!this->isEmpty() && !rhs.isEmpty())
		{
			temp.numerator = numerator * rhs.numerator;
			temp.denominator = denominator * rhs.denominator;
		}
		numerator = temp.numerator;
		denominator = temp.denominator;
		return *this;
	}
	bool Fraction::operator==(const Fraction& rhs)
	{
		bool isEqual = false;
		if (!this->isEmpty() && !rhs.isEmpty())
		{
			if ((numerator == rhs.numerator) && (denominator == rhs.denominator))
			{
				isEqual = true;
			}
		}
		return isEqual;
	}
	bool Fraction::operator!=(const Fraction& rhs)
	{
		bool notEqual = false;
		if (!this->isEmpty() && !rhs.isEmpty())
		{
			if (!(*this == rhs))
			{
				notEqual = false;
			}
		}
		return notEqual;
	}
	Fraction& Fraction::operator+=(const Fraction& rhs)
	{
		Fraction temp;
		if (!this->isEmpty() && !rhs.isEmpty())
		{
			*this = *this + rhs;
		}
		return temp;
	}

}
