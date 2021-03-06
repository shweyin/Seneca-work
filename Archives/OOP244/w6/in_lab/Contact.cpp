#define _CRT_SECURE_NO_WARNINGS
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include "Contact.h"
namespace sict
{
	Contact::Contact()
	{
		Contact::setEmpty();
	}
	long long Contact::cc(long long phoneNum)
	{
		return (phoneNum / 10000000000) % 1000;
	} 
	long long Contact::ac(long long phoneNum)
	{
		return (phoneNum / 10000000) % 1000;
	}
	long long Contact::num1(long long phoneNum)
	{
		return (phoneNum / 10000) % 1000;
	}
	long long Contact::num2(long long phoneNum)
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

		return ((countryCode >= 1 && countryCode < 100) && areaCode > 99 && numCode > 99);
	}
	Contact::Contact(const char * cons_name, long long *cons_numbers, int cons_size)
	{
		Contact::setEmpty();

		if (cons_name)
		{
			std::strncpy(name, cons_name, 20);
			if (cons_size > 0 && cons_numbers)
			{
				int i = 0, valids = 0;
				for (i = 0; i < cons_size ; i++)
				{
					if (isValid(cons_numbers[i]))
					{
						valids++;
					}
				}
				phone_numbers = new long long[valids];
				size = valids;
				int j = 0;
				for (i = 0; i < cons_size; i++)
				{
					if (isValid(cons_numbers[i]))
					{
						phone_numbers[j] = cons_numbers[i];
						j++;
					}
				}
			}
		}
	}
	Contact::~Contact()
	{
		delete [] phone_numbers;
	}
	bool Contact::isEmpty() const
	{
		return (std::strcmp(name, "") ==  0 || name[0] == '\0') && size == 0 && !phone_numbers;
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

			if (phone_numbers)
			{
				int i;

				for (i = 0; i < size; i++)
				{
					if (isValid(phone_numbers[i]))
					{
						std::cout << "(+" << cc(phone_numbers[i]) << ") " << ac(phone_numbers[i]) << " " << num1(phone_numbers[i]) << "-" << std::setfill('0') << std::setw(4) 
							<< num2(phone_numbers[i]) << std::endl;
					}
				}
			}
		}
	}
}
