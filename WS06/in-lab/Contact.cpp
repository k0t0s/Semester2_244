// Workshop 6
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Contact.cpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"

using namespace std;
namespace sict {
	Contact::Contact() { //set safe empty state
		name[0] = '\0';
		pNum = nullptr;
		pNumStored = 0;
	}

	Contact::Contact(const char* theName, long long* thepNum, int thepNumStored) {
		if (theName != nullptr) { //if name isn't nullptr, accept input
			strncpy(name, theName, MAX_CHAR);
			name[MAX_CHAR] = '\0';
			pNumStored = thepNumStored;

			if (thepNumStored > 0) { 
				long long* newpNum = new long long[pNumStored];
				for (int i = 0; i < pNumStored; i++) {
					newpNum[i] = thepNum[i];
				}
				pNum = newpNum;
			}
			else {
				pNum = nullptr;
			}
		}
		else { //if it is, set safe empty state
			Contact();
		}
	}

	Contact::~Contact() { //deallocate pNum
		delete[] pNum;
	}

	void Contact::display() const {
		if (isEmpty()) { 
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			for (int i = 0; i < pNumStored; i++) {
				if ((pNum[i] / 10000000) > 1001 && pNum[i] / 10000000 < 99999) {
					int country = pNum[i] / 10000000000;
					int area = (pNum[i] % 10000000000) / 10000000;
					int firstNum = (pNum[i] % 10000000) / 10000;
					int lastNum = (pNum[i] % 10000000) % 10000;

					cout << "(+" << country << ") " << area << " " << firstNum << "-" << setfill('0') << setw(4) << lastNum << endl;
				}
			}
		}
	}

	bool Contact::isEmpty() const {
		if (name[0] == '\0' && pNum == nullptr && pNumStored == 0) { //if safe empty state, return true
			return true;
		}
		else { //not empty state, return false
			return false;
		}
	}
}