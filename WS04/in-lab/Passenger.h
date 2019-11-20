// Workshop 4
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Passenger.h

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

#include <iostream>
#define SIZE 19

using namespace std;
namespace sict {
	class Passenger { //Private information
		char thePassName[SIZE];
		char theDestination[SIZE];
	public:
		Passenger(); //Default constructor
		Passenger(const char* passName, const char* destination); //constructor with 2 parameters
		bool isEmpty() const;
		void display() const;
	};
}

#endif