#include "Perishable.h"
#include "Date.h"


namespace AMA
{
	Perishable::Perishable() : Product('P')
	{
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Product::store(file, false);
		file << ",";
		expiry_date.write(file);
		if (newLine)
		{
			file << std::endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file)
	{
		char trash = '\0';
		Product::load(file);
		expiry_date.read(file);
		file.get(trash);
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		if (!expiry_date.bad())
		{
			Product::write(os, linear);
			if (linear)
			{
				//os << "|";
				expiry_date.write(os);
			}
			else
			{
				os << /*std::endl <<*/ "Expiry date: ";
				expiry_date.write(os);
			}
		}
		else
		{
			std::cout << message();
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is)
	{
		Product::read(is);
		if (!is.fail())
		{
			Date temp;
			std::cout << "Expiry date (YYYY/MM/DD): ";
			temp.read(is);
			if (temp.bad())
			{
				if (temp.errCode() == 1)
				{
					expiry_date.errCode(1);
					message("Invalid Date Entry");
				}
				else if (temp.errCode() == 2)
				{
					expiry_date.errCode(2);
					message("Invalid Year in Date Entry");
				}
				else if (temp.errCode() == 3)
				{
					expiry_date.errCode(3);
					message("Invalid Month in Date Entry");
				}
				else if (temp.errCode() == 4)
				{
					expiry_date.errCode(4);
					message("Invalid Day in Date Entry");
				}
				is.setstate(std::ios::failbit);
			}
			else
			{
				expiry_date = temp;
			}
		}
		return is;
	}

	const Date& Perishable::expiry() const
	{
		return expiry_date;
	}
}