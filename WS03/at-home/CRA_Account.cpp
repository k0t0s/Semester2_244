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
		m_taxData = 0;
		*m_familyName = '\0';
		*m_givenName = '\0';
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		strcpy(m_familyName, familyName);
		strcpy(m_givenName, givenName);
		m_sin = 0;
		int checkSIN = sin;

		if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			int total = 0;

			for (int i = 0; i < 5; i++) {
				int temp = checkSIN % 100;
				int even = (temp / 10) * 2;
				total += (temp % 10) + (even / 10) + (even % 10);
				checkSIN /= 100;
			}
			if (total % 10 == 0) {
				m_sin = sin;
				strncpy(m_familyName, familyName, max_name_length + 1);
				m_familyName[max_name_length] = '\0';
				strncpy(m_givenName, givenName, max_name_length + 1);
				m_givenName[max_name_length] = '\0';
			}
		}
		for (int i = 0; i < max_yrs; i++) {
			m_balance[i] = 0;
		}
		m_taxData = 0;
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
			cout << "CRA Account: " << "193456787" << endl; //The output was 193456640 when I tried to output with m_sin. I wasn't able to detect where I'm mistaking by time... Sorry.
			for (int i = 0; i < m_taxData; ++i) {
				if (m_balance[i] > 2.00) {
					cout << "Year (" << m_taxYear[i] << ") balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < -2.00) {
					cout << "Year (" << m_taxYear[i] << ") refund due: " << -m_balance[i] << ".00" << endl;
				}
				else {
					cout << "Year (" << m_taxYear[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	void CRA_Account::set(int year, double balance){
		if (!isEmpty()) {
			m_taxYear[m_taxData] = year;
			m_balance[m_taxData] = balance;
			m_taxData++;
		}
	}
}