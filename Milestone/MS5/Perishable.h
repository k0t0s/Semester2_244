// Milestone 5
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Perishable.h

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include <iostream>
#include <fstream>
#include "Good.h"
#include "Date.h"

using namespace std;
namespace aid {
	class Perishable : public Good {
		Date perDate;
	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine=true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
	iGood* CreatePerishable();
}
#endif