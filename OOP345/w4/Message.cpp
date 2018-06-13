// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018

#include "Message.h"

namespace sict
{
	Message::Message()
	{
	}
	Message::Message(std::ifstream& in, char c)
	{
		std::string my_temp;
		std::getline(in, my_temp, c);

		size_t first_space = my_temp.find(' ');
		size_t first_at = my_temp.find('@');
		size_t second_space = my_temp.find(' ', first_space + 1);

		if (first_space != std::string::npos)
		{
			msg_user = my_temp.substr(0, first_space);
			if (first_at != std::string::npos)
			{
				msg_reply = my_temp.substr(first_at + 1, second_space - first_at -1);
				msg_tweet = my_temp.substr(second_space);
			}
			else
			{
				msg_tweet = my_temp.substr(first_space);
			}
		}
		else
		{
			msg_user = my_temp;
		}
	}
	void Message::display(std::ostream& ostr) const
	{
		if (!msg_tweet.empty())
		{
			ostr << "Message" << std::endl;
			ostr << " User : " << msg_user << std::endl;
			if (!msg_reply.empty())
			{
				ostr << " Reply : " << msg_reply << std::endl;
			}
			ostr << " Tweet : " << msg_tweet << std::endl;
		}
	}
}