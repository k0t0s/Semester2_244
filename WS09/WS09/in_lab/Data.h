// Workshop 9
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Data.h

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <cstring>

using namespace std;
namespace sict {

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	template <class T> 
	T min(const T* data, int n) { // return smallest element in data
		T min = LARGEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (min > data[i]) {
				min = data[i];
			}
		}
		return min;
	}

	template <typename T>
	T max(const T* data, int n) { // return largest element in data
		T max = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (max < data[i]) {
				max = data[i];
			}
		}
		return max;
	}

	template <typename T>
	T sum(const T* data, int n) { // return sum of n element in data
		T sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum;
	}

	template <typename T>
	double average(const T* data, int n) { // return average of two integers
		return sum(data, n) / n;
	}

	template <typename T>
	bool read(std::istream & input, T* data, int n) { // read n comma-separated data elements
		for (int i = 0; i < n; i++) { 
			input.ignore();
			input >> data[i];
			if (input.fail()) { //return false if fail
				return false;
			}
		}
		return true;
	}

	template <typename T>
	void display(const char* name, const T* data, int n) { //display name right-justified in a field of 20 and each data element in a field of 15
		cout.width(20);
		cout << right << name;
		for (int i = 0; i < n; i++)
		{
			cout.width(COLUMN_WIDTH);
			cout << right << data[i];
		}
		cout << endl;
	}

	template <typename T>
	T readRow(std::istream& input, const char* name, T* data, int n) { //combined readRow() using template
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif