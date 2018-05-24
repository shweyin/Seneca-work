#include "Text.h"

namespace sict
{
	void Text::setEmpty()
	{
		str = nullptr;
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
			int count = 0;
			while (!fs.eof())
			{
				count++;
			}
			str = new std::string[count+1];
			str[0] = con_str;
			for (int i = 1; i < count; i++)
			{
				getline
			}
			fs.close();
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
			delete[] str;
			str = new std::string[mytxt.size()];
			for (int i = 0; i < size(); i++)
			{
				str[i] = mytxt.str[i];
			}
		}
		return *this;
	}
	Text& Text::operator=(Text&& mytxt)
	{
		if (this != &mytxt)
		{
			delete[] str;
			str = mytxt.str;
			mytxt.setEmpty();
		}
		return *this;
	}
	size_t Text::size() const
	{
		return sizeof(str);
	}
}