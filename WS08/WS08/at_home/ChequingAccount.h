// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: ChequingAccount.h

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

using namespace std;
namespace sict {
	class ChequingAccount : public Account{
		double trans_fee;
		double monthEnd_fee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif