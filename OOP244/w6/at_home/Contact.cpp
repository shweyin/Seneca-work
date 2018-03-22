#define _CRT_SECURE_NO_WARNINGS
// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include "Contact.h"
namespace sict
{
	Contact::Contact()
	{
		setEmpty();
	}
	Contact::Contact(const Contact& cpycon_contact)
	{
		*this = cpycon_contact;
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
		long long countryCode = cc(phoneNum);
		long long areaCode = ac(phoneNum);
		long long numCode = num1(phoneNum);

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
				for (i = 0; i < cons_size; i++)
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
		delete[] phone_numbers;
	}
	bool Contact::isEmpty() const
	{
		return (std::strcmp(name, "") == 0 || name[0] == '\0') || size == 0 && !phone_numbers;
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
	Contact& Contact::operator=(const Contact& assignment_contact)
	{
		if (this != &assignment_contact)
		{
			int i;
			strcpy(name, assignment_contact.name);
			size = assignment_contact.size;
			if (phone_numbers)
			{
				delete[] phone_numbers;
			}
			phone_numbers = new long long[size];
			for (i = 0; i < size; i++)
			{
				phone_numbers[i] = assignment_contact.phone_numbers[i];
			}
		}
		return *this;
	}
	Contact& Contact::operator+=(long long mylonglong)
	{
		if (isValid(mylonglong))
		{
			int i;
			if (phone_numbers)
			{
				long long* temp;
				temp = new long long[size];
				for (i = 0; i < size; i++)
				{
					temp[i] = phone_numbers[i];
				}
				delete[] phone_numbers;

				size += 1;
				phone_numbers = new long long[size];
				for (i = 0; i < size; i++)
				{
					phone_numbers[i] = temp[i];
				}
				phone_numbers[size - 1] = mylonglong;
				delete[] temp;
			}
			else
			{
				size += 1;
				phone_numbers = new long long[size];
				phone_numbers[size - 1] = mylonglong;
			}
		}
		return *this;
	}
}
