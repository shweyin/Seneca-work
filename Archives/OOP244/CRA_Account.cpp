//Student Name: Yawen Deng
//File Name: Workshop 03 at home
//Date:		June 4th 2018
//Description:	contains functions will be used in main function

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//using string library function in c language 
#include "CRA_Account.h"

using namespace std;
using namespace sict;
//no need enclose into {} since it have already been defined in headerfile
void CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
	if ((sin < min_sin) || (sin > max_sin) || familyName[0] == '\0' || givenName[0] == '\0') //check if it is match(home)
	{
		this->familyName[0] = '\0';//need to sign the [0] charater to null terminator 
		this->givenName[0] = '\0';
		sin = 0;
	}
	else
	{
		//use this instead of creating a temp pointer to CRA_Account class
		strncpy(this->familyName, familyName, max_name_length); //strncpy is different from strcpy function, 
																//strncpy has three parameters, the last one is able to limit the numbers of input characters
		strncpy(this->givenName, givenName, max_name_length);
		this->sin = sin;//need to store the value of sin first to make it meaningful

	}
	
	CRA_Account::date = 0;

	for (int i = 0; i < max_yrs; i++)
	{
		CRA_Account::year[i] = 0;
		CRA_Account::balance[i] = 0;
	}
}

//adding a year and a balance
void CRA_Account::set(int year, double balance)
{
	for (int i = 0; i < max_yrs; i++)
	{
		if (CRA_Account::year[i] == 0)
		{
			this->year[i] = year;
			this->balance[i] = balance;
			this->date++;
		}
	}
}

bool CRA_Account::isEmpty() const
{
	const int sinSize = 9;
	int sinA[sinSize];
	int sin = CRA_Account::sin;
	int amount = 0;
	int checker = 0;

	//no need to check weather familyname and givenname are valid here, coz this step has been accomplished in the previous function(avoid repeat)
	if (sin > min_sin && sin < max_sin)
	{
		for (int i = 0; i < sinSize; i++)
		{
			sinA[sinSize - 1 - i] = sin % 10;
			sin = sin / 10;
		}

		int stotal = 0;

		for (int i = 1; i < sinSize - 1; i += 2)
		{
			sinA[i] += sinA[i];
			stotal += (sinA[i] % 10) + (sinA[i] / 10);
			//sinA[i] = sinA[i] / 10 + sinA[i] % 10;
		}

		for (int i = 0; i < sinSize - 1; i+=2)
		{
			stotal += sinA[i];
		}

		return ((10 * ((stotal+10) / 10)) - stotal != sinA[8]);

		/*for (int i = 0; i < sinSize; i++) 
		{
			amount += sinA[i];
		}

		if (amount % 10 == 0)
		{
			checker = 0;
		}
		else
		{
			checker = 10;
		}*/

		//return checker == sinA[sinSize - 1];
	}
	else
	{
		return true;
	}

}

void CRA_Account::display() const
{
	if (familyName[0] != '\0' && givenName[0] != '\0')
	{
		cout << "Family Name: " << familyName << endl;
		cout << "Given Name: " << givenName << endl;
		cout << "CRA Account: " << sin << endl;

		for (int i = 0; i < CRA_Account::date; i++)
		{
			std::cout.precision(2);
			if (CRA_Account::balance[i] > 2)
			{
				cout << "Year (" << CRA_Account::year[i] << ") balance owing: " << fixed << CRA_Account::balance << endl;
			}
			else if (CRA_Account::balance[i] <= 2)
			{
				cout << "Year (" << CRA_Account::year[i] << ") refund due: " << fixed << CRA_Account::balance << endl;
			}
			else
			{
				cout << "Year (" << CRA_Account::year[i] << ") No balance owing or refund due!" << endl;
			}
		}
	}
	else
	{
		cout << "Account object is empty!" << endl;
	}
}
