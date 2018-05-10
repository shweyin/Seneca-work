#include "Account.h"

namespace sict {
	Account::Account()
	{
		AccountBalance = 0.0;
	}
	Account::Account(double cons_acc_balance)
	{
		AccountBalance = 0.0;
		if (cons_acc_balance > 0)
		{
			AccountBalance = cons_acc_balance;
		}
	}
	double Account::balance() const
	{
		return AccountBalance;
	}
	bool Account::credit(double credit_amount)
	{
		bool torf = false;
		if (credit_amount > 0)
		{
			AccountBalance += credit_amount;
			torf = true;
		}
		return torf;
	}
	bool Account::debit(double debit_amount)
	{
		bool torf = false;
		if (debit_amount > 0)
		{
			AccountBalance -= debit_amount;
			torf = true;
		}
		return torf;
	}
}