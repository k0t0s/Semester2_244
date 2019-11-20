// Workshop 2
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Kingdom.cpp

#include <iostream>
#include "Kingdom.h"

namespace sict {
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}