#pragma once
#include "Product.h"
#include "iProduct.h"

namespace w7 {
	class TaxableProduct : public Product {
		bool isHST;
	public:
		TaxableProduct(int, double, bool);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
}