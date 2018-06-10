#ifndef SICT_CRA_Account_H
#define SICT_CRA_Account_H

using namespace std;
//cannot "using namespace XXX" before we defining it

namespace sict {

	int const max_name_length = 40;
	int const min_sin = 100000000;
	int const max_sin = 999999999;

	int const max_yrs = 4; //max number of tax year(home)


	class CRA_Account
	{
		char familyName[max_name_length];
		char givenName[max_name_length];
		int sin;// no need to initialize

		int year[max_yrs];
		double balance[max_yrs];
		int date;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

		void set(int year, double balance);
		//void set(const char* familyName, const char* givenName, int sin);
	};

}
#endif