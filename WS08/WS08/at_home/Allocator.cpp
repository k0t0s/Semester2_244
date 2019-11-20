// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Allocator.cpp

#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;
namespace sict {
	const double accountInterest = 0.05; //interest rate is 5% (0.05)
	const double transaction_fee = 0.50; //transaction fee
	const double monthly_fee = 2.00; //monthly fee
	iAccount* CreateAccount(const char* type, double balanceNum) {
		iAccount* newAccount = nullptr; 

		if (type[0] == 'S') { // if type is S, create new savings account
			newAccount = new SavingsAccount(balanceNum, accountInterest);
			return newAccount;
		}
		else if (type[0] == 'C') { //if type is C, create new chequing account
			newAccount = new ChequingAccount(balanceNum, transaction_fee, monthly_fee);
			return newAccount;
		}
		else { //if not saving account, return with nullptr
			return newAccount;
		}
	}
}