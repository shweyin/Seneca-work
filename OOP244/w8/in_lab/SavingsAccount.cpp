
#include "SavingsAccount.h"

namespace sict {
	SavingsAccount::SavingsAccount(double cons_acc_balance, double cons_int_rate)
	{
		credit(cons_acc_balance);
		if (cons_int_rate > 0)
		{
			accountInterestRate = cons_int_rate;
		}
		else
		{
			accountInterestRate = 0.0;
		}
	}

	void SavingsAccount::monthEnd()
	{
		double interestEarned = balance() * accountInterestRate;
		credit(interestEarned);
		//credit(balance() * accountInterestRate);
	}

	void SavingsAccount::display(std::ostream& ostr) const
	{
		ostr << "Account type: Savings" << std::endl;
		ostr << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl;
		ostr << "Interest Rate (%): " << std::fixed << std::setprecision(2) << accountInterestRate * 100 << std::endl;
	}
}