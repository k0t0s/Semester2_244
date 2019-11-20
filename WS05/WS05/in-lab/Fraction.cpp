// Workshop 5
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Fraction.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fraction.h"

using namespace std;

namespace sict {
	Fraction::Fraction() {
		theNumerator = 0;
		theDenominator = -1; //Denominator of 0 isn't available
	}

	Fraction::Fraction(const char numerator, const char denominator) {
		if (numerator >= 0 && denominator > -1) {
			theDenominator = denominator;
			theNumerator = numerator;
			reduce(); 
		}
		else {
			*this = Fraction(); //Set to safe empty state
		}
	}

	int Fraction::max() const {
		if (theNumerator > theDenominator) {
			return theNumerator; // return numerator when it's higher
		}
		else {
			return theDenominator;
		}
	}

	int Fraction::min() const {
		if (theNumerator > theDenominator) {
			return theDenominator; // return denominator when it's higher
		}
		else {
			return theNumerator;
		}
	}

	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int afterReduce = gcd(); 
		theNumerator /= afterReduce; // divide by greatest common divisor
		theDenominator /= afterReduce;
	}

	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (theDenominator == 1) {
			cout << theNumerator; // output numerator without denominator
		}
		else {
			cout << theNumerator << "/" << theDenominator;
		}
	}

	bool Fraction::isEmpty() const {
		if (theDenominator == -1 && theNumerator == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	Fraction Fraction::operator+(const Fraction& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			int addNumerator = (theNumerator * rhs.theDenominator) + (rhs.theNumerator * theDenominator);
			int addDenominator = theDenominator * rhs.theDenominator;
			return Fraction(addNumerator , addDenominator);
		}
		else {
			return Fraction(); //Set to safe empty state
		}
	}
}