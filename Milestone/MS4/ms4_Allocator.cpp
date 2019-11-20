// Milestone 4
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: ms4_Allocator.cpp

#include "ms4_MyGood.h"

namespace aid {

	iGood* CreateGood() {
		return new MyGood("Good");
	}
	iGood* CreatePerishable() {
		return new MyGood("Perishable");
	}
}