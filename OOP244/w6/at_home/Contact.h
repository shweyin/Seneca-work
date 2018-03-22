#pragma once
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include <iostream>
#include <cstring>
#include <iomanip>

namespace sict
{
	class Contact
	{
		char name[20];
		int size;
		long long *phone_numbers;
		long long cc(long long);
		long long ac(long long);
		long long num1(long long);
		long long num2(long long);
		void setEmpty();
		bool isValid(long long);
	public:
		Contact();
		Contact(const Contact&);
		Contact(const char*, long long*, int);
		~Contact();
		bool isEmpty() const;
		void display();
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
	};
}
