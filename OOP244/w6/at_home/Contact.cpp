// Student: Shweyin Than, 115675175, shweyin@gmail.com

#include "Contact.h"
namespace sict
{
	Contact::Contact()
	{
		setEmpty();
	}
	Contact::Contact(const Contact& copy_contact)
	{
		//shallow copy
		strcpy(name, copy_contact.name);
		size = copy_contact.size;
		//deep copy

	}
	Contact::Contact(const char* con_name, long long* con_numbers, int con_size)
	{
		setEmpty();
		if (con_name && strcmp(con_name, "") != 0)
		{
			strcpy(name, con_name);
			this->copyNumbers(con_numbers, con_size);
		}
	}
	Contact::~Contact()
	{
		delete[] numbers;
	}
	void Contact::setEmpty()
	{
		strcpy(name, "");
		size = 0;
		numbers = nullptr;
	}
	void Contact::copyNumbers(long long* src_cpy_numbers, int cpy_size)
	{
		if (src_cpy_numbers && cpy_size != 0)
		{
			int i = 0, j = 0;
			//counts the number of valid phone numbers
			for (i = 0; i < cpy_size; i++)
			{
				if (valid(src_cpy_numbers[i]))
				{
					size++;
				}
			}
			//inserts valid numbers into members
			numbers = new long long[size];
			for (i = 0; i < cpy_size; i++)
			{
				if (valid(src_cpy_numbers[i]))
				{
					numbers[j] = src_cpy_numbers[i];
					j++;
				}
			}
		}
	}
	bool Contact::valid(long long phoneNum) const
	{
		return ((/*cc*/(phoneNum / 10 ^ 10) % 1000) >= 1 && 
				(/*ac*/(phoneNum / 10 ^ 7) % 1000) > 99 && (/*ac*/(phoneNum / 10 ^ 7) % 1000) < 1000 &&
				(/*num*/(phoneNum / 10 ^ 4) % 10 ^ 6) > 999999 && (/*num*/(phoneNum / 10 ^ 4) % 10 ^ 6) < 10000000);
	}
	bool Contact::isEmpty() const
	{
		return ((!name || strcmp(name, "") == 0) && !numbers && size == 0);
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
	Contact& Contact::operator=(const Contact& assignment_contact)
	{
		if (this != &assignment_contact)
		{

		}
	}
	Contact& Contact::operator+=(const Contact &)
	{
		// TODO: insert return statement here
	}
}