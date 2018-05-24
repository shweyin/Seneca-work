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
			str_size++;
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
		*this = std::move(mv_text);
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
			delete[] str;
			str = new std::string[mytxt.str_size];
			str[str_size - 1] = mytxt.str[mytxt.str_size - 1];
		}
		return *this;
	}
	Text& Text::operator=(Text&& mytxt)
	{
		if (this != &mytxt)
		{
			delete[] str;
			str = mytxt.str;
			str_size = mytxt.str_size;
			mytxt.setEmpty();
		}
		return *this;
	}
	int Text::size() const
	{
		return str_size;
	}
}