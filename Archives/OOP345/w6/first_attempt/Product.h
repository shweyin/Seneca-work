#pragma once
#include "iProduct.h"

namespace w7 {
	class Product : public iProduct {
		int productId;
		double price;
	public:
		Product(int, double);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
}