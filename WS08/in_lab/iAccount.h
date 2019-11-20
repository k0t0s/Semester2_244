// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: iAccount.h

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>

using namespace std;
namespace sict {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {}
	};
	iAccount* CreateAccount(const char*, double);
}

#endif