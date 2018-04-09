#include "Product.h"

namespace AMA
{
	void Product::name(const char* param_product_name)
	{
		if (product_name)
		{
			delete[] product_name;
			product_name = nullptr;
		}
		if (param_product_name)
		{
			int temp = strlen(param_product_name) + 1;
			product_name = new char[temp];
			strncpy(product_name, param_product_name, temp);
		}

	}

	const char* Product::name() const
	{
		return product_name;
	}

	const char* Product::sku() const
	{
		return sku_name;
	}

	const char* Product::unit() const
	{
		return unit_name;
	}

	bool Product::taxed() const
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

	Product::Product(char cons_char)
	{
		type = cons_char;
		sku_name[0] = '\0';
		unit_name[0] = '\0';
		product_name = nullptr;
		product_quantity = 0;
		quantity_needed = 0;
		unit_price = 0;
		taxable = false;
		product_error_state;
	}

	Product::Product(const char* cons_sku_name, const char* cons_product_name, const char* cons_unit_name, 
		int cons_product_quantity, bool cons_taxable, double cons_unit_price, int cons_quantity_needed)
	{
		type = 'N';
		strcpy(sku_name, cons_sku_name);
		product_name = nullptr;
		name(cons_product_name);
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
		return *this;
	}

	Product::~Product()
	{
		delete[] product_name;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		if (file.is_open()) {
			file << sku_name << ","
				<< product_name << ","
				<< cost() << ","
				<< product_quantity << ","
				<< unit_name << ","
				<< quantity_needed;
		}if (newLine)
		{
			file << std::endl;
		}
		return file;
	}

	std::fstream& Product::load(std::fstream& file)
	{
		Product temp;
		file.open("myFile", std::ios::in);
		file >> temp.sku_name;
		file >> temp.product_name;
		file >> temp.unit_name;
		file >> temp.taxable;
		file >> temp.unit_price;
		file >> temp.product_quantity;
		file >> temp.quantity_needed;
		file.clear();
		file.close();
		return file;
	}

	std::ostream& Product::write(std::ostream& ostr, bool linear) const
	{
		if (linear)
		{
			ostr << std::fixed << std::left << std::setprecision(2);
			ostr << std::setw(max_sku_length) << sku_name << "|"
				<< std::setw(20) << product_name << "|"
				<< std::setw(7) << cost() << "|"
				<< std::setw(4) << product_quantity << "|"
				<< std::setw(10) << unit_name << "|"
				<< std::setw(4) << quantity_needed;
		}
		else
		{
			ostr << "Sku: " << sku_name << std::endl
				<< "Name (no spaces): " << product_name << std::endl
				<< "Price: " << unit_price << std::endl;
			if (taxable) { ostr << "Price after tax: " << cost() << std::endl; }
			else { ostr << "N/A" << std::endl; }
			ostr << "Quantity on hand: " << product_quantity << std::endl
				<< "Quantity needed: " << quantity_needed << std::endl;
		}
		return ostr;
	}

	std::istream& Product::read(std::istream& istr)
	{
		bool good = true;
		char temparray[max_name_length];
		Product temp;
		std::cout << "Sku: ";
		istr.getline(temp.sku_name, max_sku_length);
		std::cout << "Name (no spaces): ";
		istr.getline(temparray, max_name_length);
		std::cout << "Unit: ";
		istr.getline(temp.unit_name, max_unit_length);
		std::cout << "Taxed? (y/n): ";
		temp.taxable = YorN();
		std::cout << "Price: ";
		istr >> temp.unit_price;
		std::cout << "Quantity on hand: ";
		istr >> temp.product_quantity;
		std::cout << "Quantity needed: ";
		istr >> temp.quantity_needed;
		istr.ignore();
		temp.name(temparray);
		if (good)
		{
			*this = temp;
		}
		return istr;
	}
	bool YorN()
	{
		char temp;
		bool yes = false;
		std::cin >> temp;
		if (temp == 'y' || temp == 'Y')
		{
			yes = true;
		}
		return yes;

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

	bool Product::isEmpty() const
	{
		return (
			strcmp(sku_name, "") == 0 &&
			strcmp(unit_name, "") == 0 &&
			product_name == nullptr &&
			product_quantity == 0 &&
			quantity_needed == 0 &&
			unit_price == 0 &&
			taxable == false);
	}

	int Product::qtyNeeded() const
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
		return initial_cost + myProduct.total_cost();
	}

}