// Milestone 1
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Date.cpp

#include <iostream>
#include <cstring>
#include "Date.h"

namespace aid {
	int Date::value() const{
		return year_ * 372 + month_ * 31 + day_;
	}
	// number of days in month mon and year year
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	void Date::errCode(int errCode) { //receive error code from Date(int, int, int)
		ErrorState = errCode;
	}

	Date::Date() { //safe empty state
		year_ = 0;
		month_ = 0;
		day_ = 0;
		ErrorState = NO_ERROR;
	}
	Date::Date(int year, int month, int day) {
		if (year > 0) { //check if year is valid
			year_ = year;
			if (month < 13 && month > 0) { //check if month is valid
				month_ = month;
				if (day > 0 && day <= mdays(month, year)) { //check if day is valid
					day_ = day;
					errCode(NO_ERROR); //return current object and sets the error state to no_error
				}
				else { //return day_error if day is invalid
					*this = Date();
					errCode(DAY_ERROR);
				}
			}
			else { //return month_error if month is invalid
				*this = Date();
				errCode(MON_ERROR);
			}
		}
		else { //return year_error if year is invalid
			*this = Date();
			errCode(YEAR_ERROR);
		}
	}

	bool Date::operator==(const Date& rhs) const { 
		if (value() == rhs.value()) { //check if value() == rhs
			return true;
		}
		else { //if one or both of the object is empty, return false
			return false;
		}
	}
	bool Date::operator!=(const Date& rhs) const {
		if (value() != rhs.value()) { //check if value() != rhs
			return true;
		}
		else { //if one or both of the object is empty, return false
			return false;
		}
	}
	bool Date::operator<(const Date& rhs) const {
		if (value() < rhs.value()) { //check if value() < rhs
			return true;
		}
		else { //if one or both of the object is empty, return false
			return false;
		}
	}
	bool Date::operator>(const Date& rhs) const {
		if (value() > rhs.value()) { //check if value() > rhs
			return true;
		}
		else { //if one or both of the object is empty, return false
			return false;
		}
	}
	bool Date::operator<=(const Date& rhs) const {
		if (value() < rhs.value()) { //check if value() <= rhs
			return true;
		}
		else if (value() == rhs.value()) {
			return true;
		}
		else { //if one or both of the object is empty, return false
			return false;
		}
	}
	bool Date::operator>=(const Date& rhs) const {
		if (value() > rhs.value()) { //check if value() >= rhs
			return true;
		}
		else if (value() == rhs.value()) {
			return true;
		}
		else { //if one or both of the object is empty, return false
			return false;
		}
	}

	int Date::errCode() const { //returns the error state as an error code value
		return ErrorState;
	}
	bool Date::bad() const { //return true if error state is not NO_ERROR
		if (ErrorState != NO_ERROR) {
			return true;
		}
		else {
			return false;
		}
	}

	std::istream& Date::read(std::istream& istr) { //reads data from istr, return if theres no error
		char sym_char;

		istr >> year_ >> sym_char >> month_ >> sym_char >> day_;

		if (istr.fail()) { //if istr fails at any point, return cin_failed
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (min_year > year_ || max_year < year_) { //if year is invalid, return year_error
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (1 > month_ || 12 < month_) { //if month is invalid, return mon_error
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (day_ > mdays(month_, year_)) { //if day is invalid, return day_error
			*this = Date();
			errCode(DAY_ERROR);
		}
		else if (value() <= min_date) { //if day is invalid in that month, return past_error
			*this = Date();
			errCode(PAST_ERROR);
		}

		return istr;
	}
	std::ostream& Date::write(std::ostream& ostr) const { //write data with format of YYYY/MM/DD
		ostr << year_ << "/";
		if (month_ < 10) { //If month is less then 10, add 0 before month
			ostr << "0" << month_ << "/";
		}
		else {
			ostr << month_ << "/";
		}
		if (day_ < 10) { //If day is less then 10, add 0 before day
			ostr << "0" << day_;
		}
		else {
			ostr << day_;
		}
		return ostr;
	}
	
	std::ostream& operator<<(std::ostream& ostr, const Date& date_) {
		return date_.write(ostr); //call write member function, then return its value
	}
	std::istream& operator>>(std::istream& istr, Date& date_) {
		return date_.read(istr); //call read function, then return its value
	}

};