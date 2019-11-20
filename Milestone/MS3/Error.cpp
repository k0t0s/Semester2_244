// Milestone 3
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Error.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;
namespace aid {
	Error::Error(const char* errorMessage) {
		if (errorMessage == nullptr) { //if address is nullptr, return safe empty state
			messages = nullptr;
		} 
		else { //else, proceed to message(const char* str)
			messages = nullptr;
			message(errorMessage);
		}
	}
	Error& Error::operator=(const char* em) {
		message(em);
		return *this;
	}

	Error::~Error() { //de-allocate messages
		delete[] messages;
	}
	void Error::clear() { //clear messages, initialize to safe empty state
		delete[] messages;
		messages = nullptr;
	}
	bool Error::isClear() const { //return true if it's safe empty state
		if (messages == nullptr) {
			return true;
		}
		else if (strlen(messages) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void Error::message(const char* str) { //de-allocate messages, allocate dynamic memory to store copy of str
		clear();
		if (str != nullptr) {
			int msgLength = strlen(str);
			messages = new char[msgLength + 1];
			strncpy(messages, str, msgLength + 1); //copy string at address str to the allocated memory
		}
	}
	const char* Error::message() const { //return the address of messages
		return messages;
	}

	std::ostream& operator<<(std::ostream& ost, const Error& error) {
		if (!error.isClear()) {
			ost << error.message();
			return ost;
		}
		else {
			return ost;
		}
	}
}