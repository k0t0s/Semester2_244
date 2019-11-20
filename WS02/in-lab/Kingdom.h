// Workshop 2
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Kingdom.h

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

using namespace std;
namespace sict {

	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom&);

}
#endif