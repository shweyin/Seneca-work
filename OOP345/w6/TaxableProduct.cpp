#include <iomanip>
#include "TaxableProduct.h"
namespace w7 {
	TaxableProduct::TaxableProduct(int cons_prodId, double cons_price, bool cons_isHST) : Product::Product(cons_prodId, cons_price)
	{
		isHST = cons_isHST;
	}
	double TaxableProduct::getCharge() const
	{
		return isHST ? Product::getCharge() * 1.13 : Product::getCharge() * 1.08;
	}
	void TaxableProduct::display(std::ostream& ostr) const
	{
		Product::display(ostr);
		ostr << ' ' << isHST ? 'H' : 'P';
	}
}