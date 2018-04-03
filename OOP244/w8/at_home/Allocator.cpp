#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double stdInterestRate = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* cons_account_type, double cons_acc_balance)
	{
		Account* acc_creation_temp = nullptr;
		if (cons_account_type[0] == 'S')
		{
			acc_creation_temp = new SavingsAccount(cons_acc_balance, stdInterestRate);
		}
		return acc_creation_temp;
	}








}
