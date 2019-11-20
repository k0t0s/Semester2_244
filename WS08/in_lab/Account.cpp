// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Account.cpp

#include "Account.h"

using namespace std;
namespace sict {
	Account::Account(double balanceNum) {
		if (balanceNum < 0 || balanceNum == 0) { //if not positive-valued or no amount is received, return 0.0
			accountBalance = 0.0;
		}
		else { //else initialize current balance
			accountBalance = balanceNum;
		}
	}
	bool Account::credit(double creditBalance) {
		if (creditBalance > 0) { //if positive-valued, add to balance
			accountBalance += creditBalance;
			return true;
		}
		else { //if not positive-valued, do nothing
			return false;
		}
	}
	bool Account::debit(double debitBalance) {
		if (debitBalance > 0) { //if positive-valued, subtract to balance
			accountBalance -= debitBalance;
			return true;
		}
		else { //if not positive-valued, do nothing
			return false;
		}
	}

	double Account::balance() const {
		return accountBalance; //return balanceNum
	}
}
