// Milestone 3
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Good.h

#ifndef AID_GOOD_H
#define AID_GOOD_H

#include "Error.h"

namespace aid {
	const int max_sku_length = 7; //not capitalized because MyGood.cpp use it without capitalized
	const int max_unit_length = 10; 
	const int max_name_length = 75;
	const double TAXRATE = 0.13;

	class Good {
		char goodType;
		char goodSku[max_sku_length + 1];
		char goodUnit[max_unit_length + 1];
		char* goodName;
		int currentQuantity;
		int needQuantity;
		double beforeTax;
		bool goodStatus;
		Error goodErrState;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Good(char);
		Good(const char* sku_, const char* name_, const char* unit_, int currentQuantity_ = 0, bool taxStatus = true, double beforeTax_ = 0.0, int needQuantity_ = 0); //set default value for some parameters
			Good(const Good&);
		Good& operator=(const Good&);
		~Good();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Good&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream & , const Good&);
	std::istream& operator>>(std::istream&, Good&);
	double operator+=(double&, const Good&);
}

#endif