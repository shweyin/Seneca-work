// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018

#include "Notifications.h"

namespace sict
{
	Notifications::Notifications(std::ifstream& ifstr)
	{
		while ()
		{

		}
	}
	Notifications::Notifications(Notifications &&)
	{
	}
	Notifications & Notifications::operator=(Notifications &&)
	{
		// TODO: insert return statement here
	}
	Notifications::~Notifications()
	{
		delete[] msg_array;
	}
	void Notifications::display(std::ostream &) const
	{
	}
}