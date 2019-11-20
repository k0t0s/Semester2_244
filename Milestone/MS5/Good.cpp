// Milestone 5
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
			delete[] goodName;
			goodName = nullptr;
		}
		else { //if not nullptr, replace it with any name previously stored
			int nameLength = strlen(name_);
			goodName = new char[nameLength + 1]; //make dynamically allocated memory, it is deallocated at ~Good
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
		if (this != &copy) {
			delete[] goodName;
			goodName = nullptr;
			name(copy.goodName);

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
		return *this;
	}
	Good::~Good() { //Destructor
		delete[] goodName;
		goodName = nullptr;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const { //inserts file into fstream object, comma separated fields
		file << goodType << ',' << goodSku << ',' << goodName << ',' << goodUnit << ',';
		file << goodStatus << ',' << beforeTax << ',' << currentQuantity << ',' << needQuantity;

		if (newLine == true) { //if bool received is true, file adds new line
			file << endl;
			return file;
		}
		else {
			return file;
		}
	}
	std::fstream& Good::load(std::fstream& file) { //receive fstream object and return reference to that fstream object
		char sku_[max_sku_length];
		char name_[max_name_length];
		char unit_[max_unit_length];
		double beforeTax_;
		int currentQuantity_;
		int needQuantity_;
		char checkTax;
		bool goodStatus_;

		if (file.is_open()) {
			file.getline(sku_, max_sku_length, ',');
			sku_[strlen(sku_)] = '\0';

			file.getline(name_, max_name_length, ',');
			name_[strlen(name_)] = '\0';

			file.getline(unit_, max_unit_length, ',');
			unit_[strlen(unit_)] = '\0';

			file >> checkTax;

			if (checkTax == '1') {
				goodStatus_ = true;
			}
			else if (checkTax == '0') {
				goodStatus_ = false;
			}
			file.ignore();

			file >> beforeTax_;
			file.ignore();

			file >> currentQuantity_;
			file.ignore();

			file >> needQuantity_;
			file.ignore();

			*this = Good(sku_, name_, unit_, currentQuantity_, goodStatus_, beforeTax_, needQuantity_);
		}

		return file;
	}
	std::ostream& Good::write(std::ostream& os, bool linear) const { //display actual message
		if (!(goodErrState.isClear())) {
			os << goodErrState.message();
		}
		else if (!linear) {
			os << " Sku: " << goodSku << endl;
			os << " Name (no spaces): " << goodName << endl;
			os << " Price: " << beforeTax << endl;
			if (goodStatus)
				os << " Price after tax: " << itemCost() << endl;
			else {
				os << " Price after tax:  N/A" << endl;
			}
			os << " Quantity on Hand: " << currentQuantity << ' ' << goodUnit << endl;
			os << " Quantity needed: " << needQuantity;
		}
		else {
			os << setw(max_sku_length) << left << goodSku << '|';
			os << setw(20) << left << goodName << '|';
			os << setw(7) << right << fixed << setprecision(2) << itemCost() << '|';
			os << setw(4) << right << currentQuantity << '|';
			os << setw(10) << left << goodUnit << '|';
			os << setw(4) << right << needQuantity << '|';
		}

		return os;
	}
	std::istream& Good::read(std::istream& is) { //input data into Good
		char* name_ = new char[max_name_length + 1];
		int currentQuantity_;
		int needQuantity_;
		double beforeTax_;
		char checkTax;
		goodErrState.clear();

		if (!is.fail()) {
			cout << " Sku: ";
			is >> goodSku;
			cin.ignore();

			cout << " Name (no spaces): ";
			is >> name_;
			name(name_);

			cout << " Unit: ";
			is >> goodUnit;

			cout << " Taxed? (y/n): ";
			is >> checkTax;

			if (!is.fail()) {
				goodErrState.clear();

				if (checkTax == 'y' || checkTax == 'Y') {
					goodStatus = true;
				}
				else if (checkTax == 'n' || checkTax == 'N') {
					goodStatus = false;
				}
				else{
					is.setstate(std::ios::failbit);
					goodErrState.message("Only (Y)es or (N)o are acceptable");
					return is;
				}
			}
			else {
				is.setstate(std::ios::failbit);
				goodErrState.message("Only (Y)es or (N)o are acceptable");
				return is;
			}

			cout << " Price: ";
			is >> beforeTax_;

			if (is.fail()) {
				goodErrState.clear();
				is.setstate(ios::failbit);
				goodErrState.message("Invalid Price Entry");
				return is;
			}
			else
				beforeTax = beforeTax_;

			cout << " Quantity on hand: ";
			is >> currentQuantity_;


			if (is.fail()) {
				goodErrState.clear();
				goodErrState.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				currentQuantity = currentQuantity_;

			cout << " Quantity needed: ";
			is >> needQuantity_;
			cin.ignore();

			if (is.fail()) {
				goodErrState.clear();
				goodErrState.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				needQuantity = needQuantity_;

			if (!is.fail()) {
				goodErrState.clear();
			}
		}

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
	bool Good::operator>(const iGood& name_) const { //return true if name of current object is greater than the name of received Good object
		if (strcmp(goodName, name_.name()) > 0) {
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

	std::ostream& operator<<(std::ostream & ost, const iGood& helper) { //ostream helper function
		helper.write(ost, true);
		return ost;
	}
	std::istream& operator>>(std::istream& ist, iGood& helper) { //istream helper function
		helper.read(ist);
		return ist;
	}
	double operator+=(double& total, const iGood& helper) { //operator += helper function
		total += helper.total_cost();
		return total;
	}
};