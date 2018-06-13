// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


namespace sict
{
	class Message {
		std::string msg_tweet;
		std::string msg_reply;
		std::string msg_user;
	public:
		Message();
		Message(std::ifstream& in, char c);
		void display(std::ostream&) const;
	};
}