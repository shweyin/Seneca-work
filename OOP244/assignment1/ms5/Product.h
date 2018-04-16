#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "ErrorState.h"
#include "iProduct.h"

namespace AMA
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Product : public iProduct
	{
		char type;
		char sku_name[max_sku_length + 1];
		char unit_name[max_unit_length + 1];
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
		bool taxed() const;
		double price() const;
		double cost() const;
		const char* message() const;
		void message(const char*);
		bool isClear() const;
	public:
		void setEmpty(char);
		Product(char cons_char = 'N');
		Product(const char* cons_sku_name, const char* cons_product_name, const char* cons_unit_name,
			int cons_product_quantity = 0, bool cons_taxable = true, double cons_unit_price = 0, int cons_quantity_needed = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}