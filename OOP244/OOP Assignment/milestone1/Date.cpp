// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name Shweyin              Date 3/16/2018                Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	Date::Date()
	{
		year = 0000;
		month = 00;
		day = 00;
		comparator = 0;
		errCode(NO_ERROR);
	}
	Date::Date(int cons_year, int cons_month, int cons_day)
	{
		if (year < min_year || year > max_year)
		{
			year = 0000;
			month = 00;
			day = 00;
			comparator = 0;
			errCode(YEAR_ERROR);
		}
		else if (month < 1 || month > 12)
		{
			year = 0000;
			month = 00;
			day = 00;
			comparator = 0;
			errCode(MON_ERROR);
		}
		else if(cons_day < 1 || cons_day > mdays(cons_month, cons_year))
		{
			year = 0000;
			month = 00;
			day = 00;
			comparator = 0;
			errCode(DAY_ERROR);
		}
		else
		{
			year = cons_year;
			month = cons_month;
			day = cons_day;
			comparator = year * 372 + month * 13 + day;
			errCode(NO_ERROR);
		}
	}
	int Date::errCode() const
	{
		return errorState;
	}
	bool Date::bad() const
	{
		return errorState == NO_ERROR ? true : false;
	}
	istream & Date::read(std::istream &)
	{
		// TODO: insert return statement here
	}
	ostream & Date::write(std::ostream &) const
	{
		// TODO: insert return statement here
	}
	istream & Date::operator>>(Date &)
	{
		// TODO: insert return statement here
	}
	ostream & Date::operator<<(Date &)
	{
		// TODO: insert return statement here
	}
	void Date::errCode(int errorCode)
	{
		errorState = errorCode;
	}
	bool Date::operator==(const Date& rhs) const
	{
		return comparator == rhs.comparator ? true : false;
	}
	bool Date::operator!=(const Date& rhs) const
	{
		return comparator != rhs.comparator ? true : false;
	}
	bool Date::operator<(const Date& rhs) const
	{
		return comparator < rhs.comparator ? true : false;
	}
	bool Date::operator>(const Date& rhs) const
	{
		return comparator > rhs.comparator ? true : false;
	}
	bool Date::operator<=(const Date& rhs) const
	{
		return comparator <= rhs.comparator ? true : false;
	}
	bool Date::operator>=(const Date& rhs) const
	{
		return comparator >= rhs.comparator ? true : false;
	}
}