#pragma once
#include "iProduct.h"
namespace w7 {
	class Product : public iProduct {
		int productNo;
		double cost;
	public:
		Product(int, double);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
	class TaxableProduct : public Product{
		bool isHST;
	public:
		TaxableProduct(int, double, bool);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
	class Sale {
		std::vector<iProduct*> products;
	public:
		Sale(const char*);
		void display(std::ostream&) const;
	};
}