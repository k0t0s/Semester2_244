// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: SavingsAccount.cpp

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;
namespace sict {
	SavingsAccount::SavingsAccount(double balanceAccount, double interestRate) : Account (balanceAccount) { //set default constructor Account(balanceAccount)
		if (interestRate > 0) { //if positive-valued, store interest rate
			interest = interestRate;
		}
		else { //if not positive-valued, interest rate is set to 0
			interest = 0.0;
		}
	}
	void SavingsAccount::monthEnd() {
		double monthInterest = balance() * interest; //calculate the interest earned on the current balance
		credit(monthInterest); //credit() account with monthInterest
	}
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl; 
		os << "Balance: $" << fixed << setprecision(2) << balance() << endl; // fixed + setprecision(2) to put 2 decimal places
		os << "Interest Rate (%): " << interest * 100 << endl; // multiply by 100 because it was % value
	}
}