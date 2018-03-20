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
	public:
		bool valid(long long*) const;
		Contact();
		Contact(const char*, long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
