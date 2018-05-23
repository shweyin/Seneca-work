#pragma once
#include <iostream>
#include <fstream>
namespace sict
{
	class Text 
	{
		int str_size;
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
		int size() const;
	};
}