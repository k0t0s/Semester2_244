// Workshop 5
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Fraction.h

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

#include <iostream>

using namespace std;
namespace sict {

	class Fraction {
		int theNumerator;
		int theDenominator;

		int max() const;
		int min() const;
		int gcd() const;

	public:
		Fraction(); //Default Constructor
		Fraction(const char numerator, const char denominator); //Construmer with 2 parameters
		void reduce();
		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction& rhs) const; //Overload operator
	};
}

#endif