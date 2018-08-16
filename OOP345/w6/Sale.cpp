#include <iomanip>
#include <vector>
#include <fstream>
#include <iostream>
#include "Sale.h"

namespace w7 {
	Sale::Sale(const char* fileName)
	{
		std::ifstream fs(fileName);
		iProduct* iP;
		while ((iP = readProduct(fs)))
		{
			products.push_back(iP);
		}
		fs.close();
	}
	Sale::~Sale() {
		unsigned int i;
		for (i = 0; i < products.size(); i++)
		{
			delete[] products[i];
		}
	}
	void Sale::display(std::ostream& os) const
	{
		os << std::setw(10) << "Product No" << "Cost Taxable" << std::endl;
		for (unsigned int i = 0; i < products.size(); i++)
		{
			os << products[i] << std::endl;
		}
	}
}