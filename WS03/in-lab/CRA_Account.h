// Workshop 3
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: CRA_Account.h

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

#include <iostream>

using namespace std;
namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
		char m_familyName[max_name_length];
		char m_givenName[max_name_length];
		int m_sin;
	public:
		CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif