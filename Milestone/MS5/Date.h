// Milestone 5
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Date.h

#ifndef AID_DATE_H
#define AID_DATE_H

namespace aid {

#define NO_ERROR 0 //No error - the date is valid
#define CIN_FAILED 1 //istream failed on information entry
#define DAY_ERROR 2 //Day value is invalid
#define MON_ERROR 3 //Month value is invalid
#define YEAR_ERROR 4 //Year value is invalid
#define PAST_ERROR 5 //Date value is invalid

	const int min_year = 2018;		/////////////////////////////////////////
	const int max_year = 2038;		//used at std::istream& read(std::istream&)
	const int min_date = 751098;	/////////////////////////////////////////

	class Date {
		int year_; 
		int month_;
		int day_;
		int ErrorState;

		int value() const;
		int mdays(int mon, int year)const;
		void errCode(int errorCode);
		
	public:
		Date();
		Date(int year, int month, int day);

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode() const;
		bool bad() const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream&, const Date&);
	std::istream& operator>>(std::istream&, Date&);
}
#endif