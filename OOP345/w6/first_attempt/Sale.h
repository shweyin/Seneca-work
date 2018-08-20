#pragma once
#include <vector>
#include "Product.h"
#include"TaxableProduct.h"

namespace w7 {
	class Sale {
		std::vector<iProduct*> products;
	public:
		Sale(const char* fileName);
		virtual ~Sale();
		void display(std::ostream& os) const;
	};
}