#pragma once
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include <iostream>
#include <cstring>

namespace sict
{
	class Contact 
	{
		char name[21];
		int size;
		long long *phone_numbers;
	public:
		Contact();
		Contact(const char*, long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
