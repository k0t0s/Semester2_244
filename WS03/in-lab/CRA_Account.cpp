// Workshop 3
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: CRA_Account.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	CRA_Account::CRA_Account() {
		m_sin = 0;
		*m_familyName = '\0';
		*m_givenName = '\0';
	}
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		m_sin = sin;
		strcpy(m_familyName, familyName);
		strcpy(m_givenName, givenName);
	}
		bool CRA_Account::isEmpty() const {
			bool empState;
			if (m_sin >= max_sin || m_sin <= min_sin) {
				empState = true;
			}
			else {
				empState = false;
			}
			return empState;
		}
		void CRA_Account::display() const {
			if (!CRA_Account::isEmpty()) {
				cout << "Family Name: " << m_familyName << endl;
				cout << "Given Name : " << m_givenName << endl;
				cout << "CRA Account: " << m_sin << endl;
			}
			else {
				cout << "Account object is empty!" << endl;
			}
		}
}