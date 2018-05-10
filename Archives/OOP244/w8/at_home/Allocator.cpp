#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
	const double stdInterestRate = 0.05;
	const double stdTransactionFee = 0.50;
	const double stdMonthlyFee = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* cons_account_type, double cons_acc_balance)
	{
		Account* acc_creation_temp = nullptr;
		if (cons_account_type[0] == 'S')
		{
			acc_creation_temp = new SavingsAccount(cons_acc_balance, stdInterestRate);
		}
		else if (cons_account_type[0] == 'C')
		{
			acc_creation_temp = new ChequingAccount(cons_acc_balance, stdTransactionFee, stdMonthlyFee);
		}
		return acc_creation_temp;
	}
}
