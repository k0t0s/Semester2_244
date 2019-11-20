// Milestone 3
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Good.cpp

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Good.h"

using namespace std;
namespace aid {
	void Good::name(const char* name_) { //store the name of Good
		if (name_ == nullptr) { //if value is nullptr, set as nullptr
			goodName = nullptr;
		}
		else { //if not nullptr, replace it with any name previously stored
			int nameLength = strlen(name_);
			goodName = new char[nameLength]; //make dynamically allocated memory, it is deallocated at ~Good
			for (int i = 0; i < nameLength; i++) {
				goodName[i] = name_[i];
			}
			goodName[nameLength] = '\0';
		}
	}
	const char* Good::name() const { //return address of goodName if Good has name
		if (goodName[0] == '\0') {
			return nullptr;
		}
		else {
			return goodName;
		}
	}
	const char* Good::sku() const { //return string with sku of the Good
		return goodSku;
	}
	const char* Good::unit() const { //return string with unit of the Good
		return goodUnit;
	}
	bool Good::taxed() const { //return taxable status of the Good
		return goodStatus;
	}
	double Good::itemPrice() const { //return price of a item of the Good
		return beforeTax;
	}
	double Good::itemCost() const { //return price + any tax applied to the Good
		if (goodStatus == true) {
			return itemPrice() * (TAXRATE + 1);
		}
		else { //if there's no tax, just return price
			return itemPrice();
		}
	}
	void Good::message(const char* errMessage) { //receive error message and store that in Error object
		goodErrState.message(errMessage);
	}
	bool Good::isClear() const { //check if Error object is clear
		return goodErrState.isClear();
	}

	Good::Good(char type_) { //Zero-One argument Constructor
		goodType = type_; //set the current object to a safe recognizable empty state
		goodSku[0] = '\0';
		goodUnit[0] = '\0';
		goodName = nullptr;
		currentQuantity = 0;
		needQuantity = 0;
		beforeTax = 0.0;
		goodStatus = false;
	}
	Good::Good(const char* sku_, const char* name_, const char* unit_, int currentQuantity_, bool taxStatus, double beforeTax_, int needQuantity_) {
		name(name_); //Seven argument Constructor

		strncpy(goodSku, sku_, max_sku_length); 
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, unit_, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		currentQuantity = currentQuantity_;
		goodStatus = taxStatus;
		beforeTax = beforeTax_;
		needQuantity = needQuantity_;
	}
	Good::Good(const Good& copy) { //Copy Constructor
		if (copy.goodName == nullptr) { 
			goodName = nullptr;
		}
		else {
			int nameLength = strlen(copy.goodName);
			goodName = new char[nameLength];
			for (int i = 0; i < nameLength; i++) {
				goodName[i] = copy.goodName[i];
			}
		}

		goodType = copy.goodType;

		strncpy(goodSku, copy.goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, copy.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		currentQuantity = copy.currentQuantity;
		goodStatus = copy.goodStatus;
		beforeTax = copy.beforeTax;
		needQuantity = copy.needQuantity;
	}
	Good& Good::operator=(const Good& copy) { //Copy Assignment Operator
		if (copy.goodName == nullptr) {
			goodName = nullptr;
		}
		else {
			int nameLength = strlen(copy.goodName);
			goodName = new char[nameLength];
			for (int i = 0; i < nameLength; i++) {
				goodName[i] = copy.goodName[i];
			}
		}
		
		goodType = copy.goodType;

		strncpy(goodSku, copy.goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, copy.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		currentQuantity = copy.currentQuantity;
		goodStatus = copy.goodStatus;
		beforeTax = copy.beforeTax;
		needQuantity = copy.needQuantity;

		return *this;
	}
	Good::~Good() { //Destructor
		delete[] goodName;
		goodName = nullptr;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const { //inserts file into fstream object, comma separated fields
		file << goodType << "," << goodSku << "," << goodUnit << "," << goodName << ",";
		file << currentQuantity << "," << goodStatus << "," << beforeTax << "," << needQuantity;
		if (newLine == true) { //if bool received is true, file adds new line
			file << endl;
		}
		return file;
	}
	std::fstream& Good::load(std::fstream& file) { //receive fstream object and return reference to that fstream object
		Good reference = '\0'; //create Good object with null
		reference.goodName = new char[max_name_length + 1];
		if (file.is_open()) { //if file is_open, insert into file
			file << reference.goodType << "," << reference.goodSku << "," << reference.goodUnit << ","; //seperating lines because I was confused
			file << reference.goodName << "," << reference.currentQuantity << ",";
			file << reference.goodStatus << "," << reference.beforeTax << "," << reference.needQuantity;
			*this = reference;
		}
		delete[] reference.goodName; //deallocate
		reference.goodName = nullptr;

		return file;
	}
	std::ostream& Good::write(std::ostream& os, bool linear) const { //display actual message
		if (linear == true) { //if received bool is true, output data with vertical bar character ('|')
			os << left << setw(max_sku_length) << goodSku << "|";
			os << left << setw(20) << goodName << "|";
			os << fixed << setprecision(2) << right << setw(7) << itemCost() << "|";
			os << right << setw(4) << currentQuantity << "|";
			os << left << setw(10) << goodUnit << "|";
			os << right << setw(4) << needQuantity << "|";
		}
		else { //if false, insert the field on separate line
			os << "Sku: " << goodSku << endl;
			os << "Name (no spaces): " << goodName << endl;
			os << "Price: "; 
			if (beforeTax) {
				os << "Price after tax: " << itemCost() << "|" << endl;
			}
			else {
				os << "N/A" << "|" << endl;
			}
		}
		return os;
	}
	std::istream& Good::read(std::istream& is) { //input data into Good
		char sku_[max_sku_length + 1];
		char *name_ = new char[max_name_length + 1];
		char unit_[max_unit_length + 1];
		int currentQuantity_;
		int needQuantity_;
		double beforeTax;
		char checkTax;
		bool goodStatus_;
		Error error;

		cout << " Sku: ";
		is >> sku_;

		cout << " Name (no spaces): ";
		is >> name_;

		cout << " Unit: ";
		is >> unit_;

		cout << " Taxed? (y/n): ";
		is >> checkTax;

		if (checkTax == 'Y' || checkTax == 'y') {
			goodStatus_ = true;
		}
		else if (checkTax == 'N' || checkTax == 'n') {
			goodStatus_ = false;
		}
		else { //if input wasn't Yy or Nn, send error message
			is.setstate(std::ios::failbit);
			error.message("Only(Y)es or (N)o are acceptable");
		}

		if (!is.fail()) { 
			cout << " Price: ";
			is >> beforeTax;
			if (is.fail()) //if any input failed, send error message
				error.message("Invalid Price Entry");

			cout << " Quantity on hand: ";
			is >> currentQuantity_;
			if (is.fail())
				error.message("Invalid Quantity Entry");

			cout << " Quantity needed: ";
			is >> needQuantity_;
			if (is.fail())
				error.message("Invalid Quantity Needed Entry");

			Good copy = Good(sku_, name_, unit_, currentQuantity_, goodStatus_, beforeTax, needQuantity_);
			*this = copy;
		}

		delete[] name_;
		name_ = nullptr;
		return is;
	}
	bool Good::operator==(const char* sku_) const { //return true if received string is identical to goodSku
		if (sku_ == goodSku) {
			return true;
		}
		else {
			return false;
		}
	}
	double Good::total_cost() const { //calculate the total cost including tax
		double totalCost = beforeTax + (beforeTax * TAXRATE);
		return static_cast<double>(totalCost * currentQuantity);
	}
	void Good::quantity(int onHand) { //if positive-valued, sets currentQuantity to received integer
		if (onHand > 0) {
			currentQuantity = onHand;
		}
	}
	bool Good::isEmpty() const { //if the object is in safe empty state, return true
		if (goodSku[0] == '\0' && goodUnit[0] == '\0' && goodName == nullptr && currentQuantity == 0 && needQuantity == 0 && beforeTax == 0.0) {
			return true;
		}
		else {
			return false;
		}
	}
	int Good::qtyNeeded() const { //returns the number of units of the Good needed
		return needQuantity;
	}
	int Good::quantity() const { //return the number of units of the Good that are on hand
		return currentQuantity;
	}
	bool Good::operator>(const char* sku_) const { //return true if sku of current object is greater than the received string
		if (goodSku > sku_) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Good::operator>(const Good& name_) const { //return true if name of current object is greater than the name of received Good object
		if (goodName > name_.goodName) {
			return true;
		}
		else {
			return false;
		}
	}
	int Good::operator+=(int addedUnit) { 
		if (addedUnit > 0) { //if received value is positive-valued, add to currentQuantity
			currentQuantity += addedUnit;
			return currentQuantity;
		}
		else {
			return currentQuantity;
		}
	}

	std::ostream& operator<<(std::ostream & ost, const Good& helper) { //ostream helper function
		helper.write(ost, true);
		return ost;
	}
	std::istream& operator>>(std::istream& ist, Good& helper) { //istream helper function
		helper.read(ist);
		return ist;
	}
	double operator+=(double& total, const Good& helper) { //operator += helper function
		total += helper.total_cost();
		return total;
	}
};