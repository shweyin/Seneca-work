#pragma once
#include <iostream>
#include <fstream>
#include <string>
namespace sict
{
	class Text
	{
		std::string* str;
	public:
		Text();
		Text(const std::string con_str);
		Text(Text&);
		Text(Text&&);
		~Text();
		void setEmpty();
		Text& operator=(Text&);
		Text& operator=(Text&&);
		size_t size() const;
	};
}