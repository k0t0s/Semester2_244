// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: SavingsAccount.h

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include <iostream>
#include "Account.h"

using namespace std;
namespace sict{
	class SavingsAccount : public Account { //include Account.h
		double interest;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif