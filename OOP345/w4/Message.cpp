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
		std::getline(in, msg_user, c);
	}
	void Message::display(std::ostream& ostr) const
	{
		if (!msg_user.empty())
		{
			std::cout << "User : " << msg_user << std::endl;
		}
		if (!msg_reply.empty())
		{
			std::cout << "Reply : " << msg_reply << std::endl;
		}
		if (!msg_tweet.empty())
		{
			std::cout << "Tweet : " << msg_tweet << std::endl;
		}
	}
}