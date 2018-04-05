#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include "ErrorState.h"

namespace AMA
{
	const int max_sku_chars = 7;
	const int max_unit_chars = 10;
	const int max_name_chars = 75;
	const double tax_rate = 0.13;

	class Product
	{
		char type;
		char sku_name[max_sku_chars];
		char unit_name[max_unit_chars];
		char* product_name;
		int product_quantity;
		int quantity_needed;
		double unit_price;
		bool taxable;
		ErrorState product_error_state;
	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed();
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(char);
		Product(const char*, const char*, const char*, int, bool, double, int);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		bool operator==(const char*);
		double total_cost() const;
		void quantity(int);
		bool isEmpty();
		int qtyNeeded();
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}