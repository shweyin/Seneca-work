#define _CRT_SECURE_NO_WARNINGS
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include "Contact.h"
namespace sict
{
	Contact::Contact()
	{
		Contact::setEmpty();
	}
	int Contact::cc(long long phoneNum)
	{
		return (phoneNum / 10000000000) % 1000;
	}
	int Contact::ac(long long phoneNum)
	{
		return (phoneNum / 10000000) % 1000;
	}
	int Contact::num1(long long phoneNum)
	{
		return (phoneNum / 10000) % 1000;
	}
	int Contact::num2(long long phoneNum)
	{
		return phoneNum % 10000;
	}
	void Contact::setEmpty()
	{
		name[0] = '\0';
		size = 0;
		phone_numbers = nullptr;
	}
	bool Contact::isValid(long long phoneNum)
	{
		int countryCode = cc(phoneNum);
		int areaCode = ac(phoneNum);
		int numCode = num1(phoneNum);

		return ((countryCode >= 1 && countryCode < 100) && areaCode > 99 && numCode > 99) ? true : false;
	}
	Contact::Contact(const char * cons_name, long long *cons_numbers, int cons_size)
	{
		if (cons_name != nullptr)
		{
			std::strncpy(name, cons_name, 20);
			if (cons_size > 0 && cons_numbers != nullptr)
			{
				int i = 0, valids = 0;
				for (i = 0; i < cons_size; i++)
				{
					if (isValid(cons_numbers[i]))
					{
						valids++;
					}
				}
				phone_numbers = new long long[valids];
				size = valids;
				for (i = 0; i < cons_size; i++)
				{
					if (isValid(cons_numbers[i]))
					{
						phone_numbers[i] = cons_numbers[i];
					}
				}
			}
		}
		else
		{
			Contact::setEmpty();
		}
	}
	Contact::~Contact()
	{
		delete [] phone_numbers;
	}
	bool Contact::isEmpty() const
	{
		return ((std::strcmp(name, "") ==  0 || name == nullptr) && size == 0 && phone_numbers == nullptr) ? true : false;
	}
	void Contact::display()
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
				if (isValid(phone_numbers[i]))
				{
					std::cout << "(+" << cc(phone_numbers[i]) << ") " << ac(phone_numbers[i]) << " " << num1(phone_numbers[i]) << "-" << num2(phone_numbers[i]) << std::endl;
				}
			}
		}
	}
}
