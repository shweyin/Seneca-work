#include <iomanip>
#include "Product.h"
#include "TaxableProduct.h"
namespace w7 {
	Product::Product(int cons_prodId, double cons_price)
	{
		productId = cons_prodId;
		price = cons_price;
	}
	double Product::getCharge() const
	{
		return price;
	}
	void Product::display(std::ostream& ostr) const
	{
		ostr << std::setw(10);
		ostr << productId << " " << price;
	}
	std::ostream& operator<<(std::ostream& ostr, const iProduct& myProduct)
	{
		myProduct.display(ostr);
		return ostr;
	}
	iProduct* readProduct(std::ifstream& istr)
	{
		int readProductId = 0;
		double readCost = 0.0;
		char taxed;

		istr >> readProductId;
		istr >> readCost;
		taxed = istr.get();
		if (taxed != '\n')
		{
			istr >> taxed;
			bool isHST = (taxed == 'H');
			return new TaxableProduct(readProductId, readCost, isHST);
		}
		else
		{
			return new Product(readProductId, readCost);
		}
	}
}