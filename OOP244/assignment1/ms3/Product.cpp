#include "Product.h"

namespace AMA
{
	void Product::name(const char* param_product_name)
	{
		if (param_product_name)
		{
			int temp = strlen(param_product_name);
			product_name = new char[temp];
			strncpy(product_name, param_product_name, max_name_length);
		}
		else if (!param_product_name)
		{
			delete[] product_name;
		}
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
		return sku_name;
	}

	const char* Product::unit() const
	{
		return unit_name;
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
		strcpy(sku_name, "");
		strcpy(unit_name, "");
		product_name = nullptr;
		product_quantity = 0;
		quantity_needed = 0;
		unit_price = 0;
		taxable = false;
	}

	Product::Product(const char* cons_sku_name, const char* cons_product_name, const char* cons_unit_name, int cons_product_quantity = 0, bool cons_taxable = true, double cons_unit_price, int cons_quantity_needed)
	{
		type = 'N';
		name(cons_sku_name);
		strcpy(unit_name, cons_unit_name);
		product_quantity = cons_product_quantity;
		taxable = cons_taxable;
		unit_price = cons_unit_price;
		quantity_needed = cons_quantity_needed;
	}

	Product::Product(const Product& copy_target)
	{
		*this = copy_target;
	}

	Product& Product::operator=(const Product& copy_target)
	{
		type = copy_target.type;
		name(copy_target.product_name);
		strcpy(unit_name, copy_target.unit_name);
		product_quantity = copy_target.product_quantity;
		taxable = copy_target.taxable;
		unit_price = copy_target.unit_price;
		quantity_needed = copy_target.quantity_needed;
	}

	Product::~Product()
	{
		delete[] product_name;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine = true) const
	{
		// TODO: insert return statement here
	}

	std::fstream& Product::load(std::fstream&)
	{
		// TODO: insert return statement here
	}

	std::ostream& Product::write(std::ostream& ostr, bool linear) const
	{
		if (linear)
		{
			std::cout << std::setw(max_sku_length) << sku << "|"
				<< std::setw(20) << product_name << "|"
				<< std::setw(7) << cost() << "|"
				<< std::setw(4) << product_quantity << "|"
				<< std::setw(10) << unit_name << "|"
				<< std::setw(4) << quantity_needed;
		}
		else
		{
			std::cout
				<< "Sku: " << sku << std::endl
				<< "Name (no spaces): " << product_name << std::endl
				<< "Price: " << unit_price << std::endl;
			if (taxable) { std::cout << "Price after tax: " << cost() << std::endl; }
			else { std::cout << "N/A" << std::endl; }
			std::cout
				<< "Quantity on hand: " << product_quantity << std::endl
				<< "Quantity needed: " << quantity_needed << std::endl;
		}
		return ostr;
	}

	std::istream& Product::read(std::istream& istr)
	{
		//TODO this whole goddam function
		return istr;
	}

	bool Product::operator==(const char* compared_sku_name)
	{
		return (strcmp(sku_name, compared_sku_name) == 0);
	}

	double Product::total_cost() const
	{
		return taxable ? (unit_price * product_quantity) * tax_rate : unit_price * product_quantity;
	}

	void Product::quantity(int new_quantity)
	{
		product_quantity = new_quantity;
	}

	bool Product::isEmpty()
	{
		return (
			strcpy(sku_name, "") == 0 &&
			strcpy(unit_name, "") == 0 &&
			product_name == nullptr &&
			product_quantity == 0 &&
			quantity_needed == 0 &&
			unit_price == 0 &&
			taxable == false);
	}

	int Product::qtyNeeded()
	{
		return quantity_needed;
	}

	int Product::quantity() const
	{
		return product_quantity;
	}

	bool Product::operator>(const char* comparison_string) const
	{
		return sku_name > comparison_string;
	}

	bool Product::operator>(const Product& comparison_name) const
	{
		return product_name > comparison_name.product_name;
	}

	int Product::operator+=(int adding_quantity)
	{
		if (adding_quantity > 0)
		{
			product_quantity += adding_quantity;
		}
		return product_quantity;
	}

	std::ostream& operator<<(std::ostream& ostr, const Product& outputProduct)
	{
		outputProduct.write(ostr, true);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Product& inputProduct)
	{
		inputProduct.read(istr);
		return istr;
	}

	double operator+=(double& initial_cost, const Product& myProduct)
	{
		return initial_cost + myProduct.total_cost;
	}

}