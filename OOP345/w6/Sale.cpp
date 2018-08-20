#include "Sale.h"
namespace w7 {
	std::ostream& operator<<(std::ostream& ostr, const iProduct& myProduct)
	{
		myProduct.display(ostr);
		return ostr;
	};
	iProduct* readProduct(std::ifstream& fs)
	{
		int productNo;
		double cost;
		bool isHST;
		char next;
		fs >> productNo >> cost;
		fs.get(next);
		if (next != '\n')
		{
			fs.get(next);
			isHST = next == 'H' ? true : false;
			return new TaxableProduct(productNo, cost, isHST);
		}
		else
		{
			return new Product(productNo, cost);
		}

	};
	Product::Product(int cons_productNo, double cons_cost)
	{
		productNo = cons_productNo;
		cost = cons_cost;
	}
	double Product::getCharge() const
	{
		return cost;
	}
	void Product::display(std::ostream& ostr) const
	{
		ostr << productNo << " " << cost;
	}
	TaxableProduct::TaxableProduct(int cons_productNo, double cons_cost, bool cons_isHST) : Product(cons_productNo, cons_cost)
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
		const char* output = isHST ? " HST" : " PST";
		ostr << output;
	}
	Sale::Sale(const char* file)
	{
		std::ifstream fs(file);
		iProduct* one_product;
		while (fs.good())
		{
			one_product = readProduct(fs);
			products.push_back(one_product);
		}
		fs.close();
	}
	void Sale::display(std::ostream& ostr) const
	{
		ostr << "Product No" << "Cost" << "Taxable" << std::endl;
		for (unsigned int i = 0; i < products.size(); i++)
		{
			ostr << *products[i] << std::endl;
		}
	}
}