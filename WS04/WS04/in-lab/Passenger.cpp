// Workshop 4
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Passenger.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {
	Passenger::Passenger() { //Default constructor
		*thePassName = '\0';
		*theDestination = '\0';
	}

	Passenger::Passenger(const char* passName, const char* destination) {
		if (passName == '\0' || destination == '\0') { //Invalid, sets safe empty state
			*thePassName = '\0';
			*theDestination = '\0';
		}
		else { //Valid, copy to object's instance variables
			strncpy(thePassName, passName, SIZE);
			strncpy(theDestination, destination, SIZE);
		}
	}

	bool Passenger::isEmpty() const {
		if (*thePassName == '\0' || *theDestination == '\0') { //Report if Passenger object is in a safe empty state.
			return true;
		}
		else {
			return false;
		}
	}
	void Passenger::display() const {
		if (*thePassName == '\0' || *theDestination == '\0') { //Check if it's in a safe empty state.
			cout << "No passenger!" << endl;
		}
		else {
			cout << thePassName << " - " << theDestination << endl; //Outputs if it's not in a safe empty state.
		}
	}

}