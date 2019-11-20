// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Account.h

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h" 

using namespace std;
namespace sict {
	class Account : public iAccount{ //include iAccount.h
		double accountBalance;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);

		double balance() const;
	};
	iAccount* CreateAccount(const char*, double);
}

#endif