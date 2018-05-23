#include "Text.h"

namespace sict 
{
	void Text::setEmpty()
	{
		str = nullptr;
		str_size = 0;
	}
	Text::Text()
	{
		setEmpty();
	}
	Text::Text(const std::string con_str)
	{
		setEmpty();
		std::fstream fs;
		fs.open(con_str);
		if (fs.is_open())
		{
			str = new std::string[1];
			str[0] = con_str;
		}
	}
	Text::Text(Text& cpy_text)
	{
		setEmpty();
		*this = cpy_text;
	}
	Text::Text(Text&& mv_text)
	{
		setEmpty();
	}
	Text::~Text()
	{
		delete[] str;
	}
	Text& Text::operator=(Text& mytxt)
	{
		if (this != &mytxt)
		{
			str_size = mytxt.str_size;
			if (str)
			{
				delete[] str;
			}
			str = new std::string[mytxt.str_size];
		}
		return mytxt;
	}
	Text& Text::operator=(Text&& mytxt)
	{
		return mytxt;
	}
	int Text::size() const
	{
		return str_size;
	}
}