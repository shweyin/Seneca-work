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
			int str_length = strlen(param_product_name);
			product_name = new char[str_length + 1];
			strcpy(product_name, param_product_name);
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
		return taxable ? unit_price * (1 + tax_rate) : unit_price;
	}
	const char* Product::message() const
	{
		return product_error_state.message();
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
		setEmpty(cons_char);
	}

	void Product::setEmpty(char cons_char)
	{
		type = cons_char;
		sku_name[0] = '\0';
		unit_name[0] = '\0';
		product_name = nullptr;
		product_quantity = 0;
		quantity_needed = 0;
		unit_price = 0;
		taxable = false;
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
		setEmpty(copy_target.type);
		type = copy_target.type;
		strcpy(sku_name, copy_target.sku_name);
		name(copy_target.product_name);
		strcpy(unit_name, copy_target.unit_name);
		product_quantity = copy_target.product_quantity;
		taxable = copy_target.taxable;
		unit_price = copy_target.unit_price;
		quantity_needed = copy_target.quantity_needed;
		if (!copy_target.product_error_state.isClear())
		{
			product_error_state.message(copy_target.product_error_state.message());
		}
		return *this;
	}

	Product::~Product()
	{
		delete[] product_name;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		if (file.is_open()) {
			int taxableNum = taxable ? 1 : 0;
			file << type << ","
				<< sku_name << ","
				<< product_name << ","
				<< unit_name << ","
				<<taxableNum << ","
				<< unit_price << ","
				<< product_quantity << ","
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
		int taxableNum = 1;
		char temp_product_name[max_name_length];
		/*file >> temp.type;
		file.ignore(2000, ',');
		file.get(temp_sku_name, max_sku_length, ',');
		temp.name(temp_sku_name);
		file.ignore(2000, ',');
		file.get(temp.product_name, max_name_length, ',');
		file.ignore(2000, ',');
		file.get(temp.unit_name, max_unit_length, ',');
		file.ignore(2000, ',');
		file >> taxableNum;
		temp.taxable = taxableNum == 1 ? true : false;
		file.ignore(2000, ',');
		file >> temp.product_quantity;
		file.ignore(2000, ',');
		file >> temp.quantity_needed;
		file.ignore(2000, '\n');*/
		char trash = '\0';
		file.get(temp.type);
		file.get(trash);
		file.get(temp.sku_name, max_sku_length, ',');
		file.get(trash);
		file.get(temp_product_name, max_name_length, ',');
		temp.name(temp_product_name);
		file.get(trash);
		file.get(temp.unit_name, max_unit_length, ',');
		file.get(trash);
		file >> taxableNum;
		file.get(trash);
		temp.taxable = taxableNum == 1 ? true : false;
		file >> temp.unit_price;
		file.get(trash);
		file >> temp.product_quantity;
		file.get(trash);
		file >> temp.quantity_needed;
		file.get(trash);
		file.clear();
		file.close();
		*this = temp;
		return file;
	}

	std::ostream& Product::write(std::ostream& ostr, bool linear) const
	{
		if (!isEmpty() && linear)
		{
			ostr << std::fixed << std::left << std::setprecision(2);
			ostr << std::setw(max_sku_length) << sku_name << "|"
				<< std::setw(20) << product_name << "|"
				<< std::setw(7) << std::right << cost() << "|"
				<< std::setw(4) << product_quantity << "|"
				<< std::setw(10) << std::left << unit_name << "|"
				<< std::setw(4) << std::right << quantity_needed << "|";
		}
		else if (!isEmpty() && !linear)
		{
			ostr << "Sku: " << sku_name << std::endl
				<< "Name (no spaces): " << product_name << std::endl
				<< "Price: " << unit_price << std::endl;
			ostr << "Price after tax: ";
			if (taxable) { ostr  << cost() << std::endl; }
			else { ostr << "N/A" << std::endl; }
			ostr << "Quantity on hand: " << product_quantity << std::endl
				<< "Quantity needed: " << quantity_needed << std::endl;
		}
		else if (isEmpty())
		{
			ostr << product_error_state.message();
		}
		return ostr;
	}

	std::istream& Product::read(std::istream& istr)
	{
		bool good = true;
		char temparray[max_name_length];
		char yorn = '\0';
		Product temp;
		std::cout << " Sku: ";
		istr.getline(temp.sku_name, max_sku_length);
		std::cout << " Name (no spaces): ";
		istr.getline(temparray, max_name_length);
		temp.name(temparray);
		std::cout << " Unit: ";
		istr.getline(temp.unit_name, max_unit_length);
		std::cout << " Taxed? (y/n): ";
		istr >> yorn;
		if (yorn == 'n' || yorn == 'N' || yorn == 'y' || yorn == 'Y')
		{
			if (yorn == 'y' || yorn == 'Y')
			{
				temp.taxable = true;
			}
			else
			{
				temp.taxable = false;
			}
			
		}
		else 
		{ 
			message("Only (Y)es or (N)o are acceptable"); 
			good = false; 
			istr.setstate(std::ios::failbit);
		}

		if (good && !istr.fail())
		{
			std::cout << " Price: ";
			istr >> temp.unit_price;
			if (istr.fail())
			{
				message("Invalid Price Entry");
				good = false;
			}
		}

		if (good && !istr.fail())
		{
			std::cout << " Quantity on hand: ";
			istr >> temp.product_quantity;
			if (istr.fail())
			{
				message("Invalid Quantity Entry");
				good = false;
			}
		}

		if (good && !istr.fail())
		{
			std::cout << " Quantity needed: ";
			istr >> temp.quantity_needed;
			if (istr.fail())
			{
				message("Invalid Quantity Needed Entry"); 
				good = false;
			}
		}
		if (good)
		{
			*this = temp;
		}
		return istr;
	}

	bool Product::operator==(const char* compared_sku_name) const
	{
		return (strcmp(sku_name, compared_sku_name) == 0);
	}

	double Product::total_cost() const
	{
		return taxable ? (unit_price * product_quantity) * (1+tax_rate) : unit_price * product_quantity;
	}

	void Product::quantity(int new_quantity)
	{
		product_quantity = new_quantity;
	}

	bool Product::isEmpty() const
	{
		return (!product_name);
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

	bool Product::operator>(const iProduct& comparison_name) const
	{
		return product_name > comparison_name.name();
	}

	int Product::operator+=(int adding_quantity)
	{
		if (adding_quantity > 0)
		{
			product_quantity += adding_quantity;
		}
		return product_quantity;
	}

	std::ostream& operator<<(std::ostream& ostr, const iProduct& outputProduct)
	{
		outputProduct.write(ostr, true);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, iProduct& inputProduct)
	{
		inputProduct.read(istr);
		return istr;
	}

	double operator+=(double& initial_cost, const iProduct& myProduct)
	{
		return initial_cost + myProduct.total_cost();
	}

}