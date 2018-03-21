#pragma once
#define _CRT_SECURE_NO_WARNINGS
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

namespace sict
{
	class Contact
	{
		char name[20];
		int size;
		long long *numbers;
		void setEmpty();
		void copyNumbers(long long*, int);
	public:
		Contact();
		Contact(const Contact&);
		Contact(const char*, long long*, int);
		~Contact();
		bool valid(long long) const;
		bool isEmpty() const;
		void display() const;
		Contact& operator=(const Contact&);
		Contact& operator+=(const Contact&);
	};
}