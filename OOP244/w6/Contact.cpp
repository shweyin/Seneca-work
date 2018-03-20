// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include "Contact.h"
namespace sict
{
	void Contact::setEmpty()
	{
		strcpy(name, "");
		size = 0;
		numbers = nullptr;
	}
	Contact::Contact()
	{
		setEmpty();
	}
	Contact::Contact(const char* con_name, long long* con_numbers, int con_size)
	{
		if(con_name != nullptr)
		{
			strcpy(name, con_name);
			if (con_numbers != nullptr && con_size != 0)
			{
				int i;
				size = 0;
				//counts the number of valid phone numbers
				for (i = 0; i < con_size; i++)
				{
					if (valid(&con_numbers[i]))
					{
						size++;
					}
				}
				//inserts valid numbers into members
				numbers = new long long[size];
				for (i = 0; i < con_size; i++)
				{
					if (valid(&con_numbers[i]))
					{
						numbers[i] = con_numbers[i];
					}
				}
			}
			else
			{
				numbers = nullptr;
				size = 0;
			}
		}
		else
		{
			setEmpty();
		}
	}
	Contact::~Contact()
	{
		delete[] numbers;
	}
	bool Contact::valid(long long* phoneNum) const
	{
		int cc, ac, num;

		cc = (*phoneNum / 10000000000) % 1000;
		ac = (*phoneNum / 10000000) % 1000;
		num = (*phoneNum / 10000) % 1000000;

		return (cc >= 1 && ac > 99 && ac < 1000 && num > 999999 && num < 10000000) ? true : false;
	}
	bool Contact::isEmpty() const
	{
		return (strcmp(name, "") == 0 && numbers == nullptr && size == 0) ? true : false;
	}
	void Contact::display() const
	{
		if (isEmpty())
		{
			cout << "Empty!" << endl;
		}
		else
		{
			cout << name << endl;
			int i;
			for (i = 0; i < size; i++)
			{
				cout << numbers[i];
			}
		}
	}
}