// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//

	ChequingAccount::ChequingAccount(double cons_acc_balance, double cons_trans_fee, double cons_month_fee)
	{
		credit(cons_acc_balance);
		if (cons_trans_fee > 0)
		{
			transactionFee = cons_trans_fee;
		}
		else
		{
			transactionFee = 0.0;
		}
		if (cons_month_fee > 0)
		{
			monthEndFee = cons_month_fee;
		}
		else
		{
			monthEndFee = 0.0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//

	bool ChequingAccount::credit(double chequing_acc_credit)
	{
		bool torf = false;
		if (Account::credit(chequing_acc_credit))
		{
			Account::debit(transactionFee);
			torf = true;
		}
		return torf;
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

	bool ChequingAccount::debit(double chequing_acc_debit)
	{
		bool torf = false;
		if (Account::debit(chequing_acc_debit))
		{
			Account::debit(transactionFee);
			torf = true;
		}
		return torf;
	}

	// monthEnd debits month end fee
	//

	void ChequingAccount::monthEnd()
	{
		debit(monthEndFee);
	}

	// display inserts account information into ostream os
	//

	void ChequingAccount::display(std::ostream& ostr) const
	{
		ostr << "Account type: Chequing" << std::endl;
		ostr << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl;
		ostr << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << transactionFee << std::endl;
		ostr << "Monthly Fee: " << std::fixed << std::setprecision(2) << monthEndFee << std::endl;
	}








}