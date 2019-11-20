// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Allocator.cpp

#include "SavingsAccount.h"

using namespace std;
namespace sict {
	const double accountInterest = 0.05; //interest rate is 5% (0.05)
	iAccount* CreateAccount(const char* type, double balanceNum) {
		iAccount* newAccount = nullptr; 

		if (type[0] == 'S') { // if it's saving account, create new savings account
			newAccount = new SavingsAccount(balanceNum, accountInterest);
			return newAccount;
		}
		else { //if not saving account, return with nullptr
			return newAccount;
		}
	}
}