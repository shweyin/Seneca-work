// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018
#pragma once
#include <iostream>
#include <string>
#include <fstream>


namespace sict
{
	class Message {
		std::string my_message;
	public:
		Message(std::ifstream& in, char c);
		void display(std::ostream&) const;
	};
}