#include "Product.h"

namespace AMA
{
	void Product::name(const char *)
	{
	}

	const char* Product::name() const
	{
		char* temp = nullptr;
		if (strcmp(product_name, "") != 0)
		{
			strcpy(temp, product_name);
		}
		return temp;
	}

	const char* Product::sku() const
	{
		return sku;
	}

	const char* Product::unit() const
	{
		return unit;
	}

	bool Product::taxed()
	{
		return taxable;
	}

	double Product::price() const
	{
		return unit_price;
	}

	double Product::cost() const
	{
		double temp = 0.0;
		if (taxable)
		{
			temp = unit_price * tax_rate;
		}
		return temp;
	}

	void Product::message(const char* func_error_msg)
	{
		product_error_state.message(func_error_msg);
	}

	bool Product::isClear() const
	{
		return product_error_state.isClear();
	}

	Product::Product(char cons_char = 'N')
	{
		type = cons_char;
		strcpy(sku, "");
	}

	Product::Product(const char *, const char *, const char *, int, bool, double, int)
	{
	}

	Product::Product(const Product &)
	{
	}

	Product& Product::operator=(const Product &)
	{
		// TODO: insert return statement here
	}

	Product::~Product()
	{
	}

	std::fstream& Product::store(std::fstream &, bool newLine) const
	{
		// TODO: insert return statement here
	}

	std::fstream& Product::load(std::fstream &)
	{
		// TODO: insert return statement here
	}

	std::ostream& Product::write(std::ostream &, bool) const
	{
		// TODO: insert return statement here
	}

	std::istream& Product::read(std::istream &)
	{
		// TODO: insert return statement here
	}

	bool Product::operator==(const char *)
	{
		return false;
	}

	double Product::total_cost() const
	{
		return 0.0;
	}

	void Product::quantity(int)
	{
	}

	bool Product::isEmpty()
	{
		return false;
	}

	int Product::qtyNeeded()
	{
		return 0;
	}

	int Product::quantity() const
	{
		return 0;
	}

	bool Product::operator>(const char *) const
	{
		return false;
	}

	bool Product::operator>(const Product &) const
	{
		return false;
	}

	int Product::operator+=(int)
	{
		return 0;
	}

	std::ostream& operator<<(std::ostream &, const Product &)
	{
		// TODO: insert return statement here
	}

	std::istream& operator>>(std::istream &, Product &)
	{
		// TODO: insert return statement here
	}

	double operator+=(double &, const Product &)
	{
		return 0.0;
	}

}