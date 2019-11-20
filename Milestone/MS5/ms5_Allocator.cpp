// Milestone 5
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: ms5_Allocator.cpp

#include "Good.h"
#include "Perishable.h"

namespace aid {

	// creates an empty good
	//
	iGood* CreateGood() {
		return new Good();
	}

	// creates an empty perishable good
	//
	iGood* CreatePerishable() {
		return new Perishable();
	}
}
