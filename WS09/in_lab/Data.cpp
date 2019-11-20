// Workshop 9
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Data.cpp

#include <iostream>
#include <cstring>
#include "Data.h"

using namespace std;
namespace sict {
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		cout.precision(2);
		cout << "Population change from " << min(year, n) << " to " << max(year, n) << " is " << fixed << static_cast<double>(population[n - 1] - population[0]) / 1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		cout << "Violent Crime trend is ";
		if (violentCrimeRate[1] - violentCrimeRate[0] > 0) {
			cout << "up" << endl;
		}
		else {
			cout << "down" << endl;
		}

		// Q3 print the GTA number accurate to 0 decimal places
		double gtaNum = average(grandTheftAuto, n) / 1000000;
		cout << "There are " << fixed << gtaNum << " million Grand Theft Auto incidents on average a year" << endl;
		
		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;


	}
}