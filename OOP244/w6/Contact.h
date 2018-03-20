#pragma once
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include <iostream>
#include <cstring>

namespace sict
{
	class Contact 
	{
		char name[20];
		int size;
		long long *phone_numbers;
		int cc(long long); 
		int ac(long long); 
		int num1(long long); 
		int num2(long long);
		void setEmpty();
		bool isValid(long long);
	public:
		Contact();
		Contact(const char*, long long*, int);
		~Contact();
		bool isEmpty() const;
		void display();
	};
}
