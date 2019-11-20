// Milestone 5
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Perishable.cpp

#include <iostream>
#include <fstream>
#include "Perishable.h"

using namespace std;
namespace aid {
	Perishable::Perishable() : Good('P') {
		perDate = Date();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const { //returns reference to modified fstream object
		Good::store(file, false);
		file << "," << perDate; //insert perishable date
		if (newLine == true) { //if bool is true, insert new line before return
			file << endl;
			return file;
		}
		else {
			return file;
		}
	}
	std::fstream& Perishable::load(std::fstream& file) {
		Good::load(file); //load expiry date from the file
		perDate.read(file); 
		file.ignore(); //note this ignore function
		return file; //return a single character from fstream object
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Good::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear == false) { //if linear is false, add new line and "Expiry date:"
				os << endl << " Expiry date: " << perDate;
			}
			else { //if linear is true, add expiry date on same line
				os << perDate;
			}
			return os;
		}
		else { 
			return os;
		}
		
	}
	std::istream& Perishable::read(std::istream& is) {
		Date date_;
		is.clear();
		Good::read(is); //read is

		if (Good::isClear()) { //if object extracts data successfully, prompt for expiry date and stores it in Date object
			cout << " Expiry date (YYYY/MM/DD): ";
			date_.read(is);
		}
		//Stores individual errors when occured
		if (date_.errCode() == CIN_FAILED) {
			goodErrState.clear();
			is.setstate(std::ios::failbit);
			goodErrState.message("Invalid Date Entry");
		}

		else if (date_.errCode() == YEAR_ERROR) {
			goodErrState.clear();
			is.setstate(std::ios::failbit);
			goodErrState.message("Invalid Year in Date Entry");
		}

		else if (date_.errCode() == MON_ERROR) {
			goodErrState.clear();
			is.setstate(std::ios::failbit);
			goodErrState.message("Invalid Month in Date Entry");
		}

		else if (date_.errCode() == DAY_ERROR) {
			goodErrState.clear();
			is.setstate(std::ios::failbit);
			goodErrState.message("Invalid Day in Date Entry");
		}

		else if (date_.errCode() == PAST_ERROR) {
			goodErrState.clear();
			is.setstate(std::ios::failbit);
			goodErrState.message("Invalid Expiry in Date Entry");
		}

		else {
			perDate = date_;
			is.istream::fail(); //member function that reports failure of an istream object
        }
		return is;
	}
	const Date& Perishable::expiry() const {
		return perDate; //return expiry date
	}
}