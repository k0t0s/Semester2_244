// Workshop 6
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Contact.h

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_

using namespace std;
namespace sict {
	const int MAX_CHAR = 20;

	class Contact {
		char name[MAX_CHAR + 1];
		long long* pNum;
		int pNumStored;

	public:
		Contact();
		Contact(const char*, long long*, int);
		~Contact();
		void display() const;
		bool isEmpty() const;

		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long);
	};
}

#endif