// Milestone 3
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Error.h

#ifndef AID_ERROR_H
#define AID_ERROR_H

#include <iostream>

using namespace std;
namespace aid {
	class Error {
		char* messages;

	public:
		explicit Error(const char* errorMessage = nullptr);

		Error& operator=(const char * em);

		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;

		virtual ~Error();

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream&, const Error&);
}

#endif