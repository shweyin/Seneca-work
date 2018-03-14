// Final Project Milestone 1
//
// Revision History
// -----------------------------------------------------------
// Name Shweyin          Date 3/16/2018            Reason 
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

	class Date {
		int year;
		int month;
		int day;
		int comparator;
		int errorState;
		int mdays(int, int)const;
		void errCode(int);
	public:
		Date();
		Date(int, int, int);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		bool bad() const;

	};





}
#endif