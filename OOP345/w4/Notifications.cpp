// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018

#include "Notifications.h"

namespace sict
{
	Notifications::Notifications(std::ifstream& in)
	{
		for (unsigned int i = 0; i < msg_vector.size(); i++)
		{
			msg_vector.push_back(Message(in, '\n'));
		}
	}
	Notifications::Notifications(Notifications&& target_obj)
	{
		*this = std::move(target_obj);
	}
	Notifications& Notifications::operator=(Notifications&& target_obj)
	{
		if (this != &target_obj)
		{
			msg_vector = target_obj.msg_vector;
		}
		return *this;
	}
	Notifications::~Notifications()
	{
	}
	void Notifications::display(std::ostream& ostr) const
	{
		for (unsigned int i = 0; i < msg_vector.size(); i++)
		{
			msg_vector[i].display;
		}
		ostr << "Press any key to continue...";
		std::cin.ignore();
	}
}