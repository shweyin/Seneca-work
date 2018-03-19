#define _CRT_SECURE_NO_WARNINGS
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include "Contact.h"
namespace sict
{
	Contact::Contact()
	{
		std::strncpy(name, "", 20);
		size = 0;
		phone_numbers = NULL;
	}
	Contact::Contact(const char * cons_name, long long *cons_numbers, int cons_size)
	{
		phone_numbers = new long long[cons_size];
		std::strncpy(name, cons_name, 20);
		size = cons_size;
	}
	Contact::~Contact()
	{
		delete [] phone_numbers;
	}
	bool Contact::isEmpty() const
	{
		//	return ((std::strcmp(name, "") ==  0) && size == 0 && phone_numbers == NULL) ? true : false;
		return (size == 0) ? true : false;
	}
	void Contact::display() const
	{
		if (isEmpty())
		{
			std::cout << "Empty contact!" << std::endl;
		}
		else
		{
			std::cout << name << std::endl;
			int i;
			for (i = 0; i < size; i++)
			{
				std::cout << phone_numbers[i];
			}
		}
	}
}
