// Workshop 8
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: ChequingAccount.cpp

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

using namespace std;
namespace sict {
	ChequingAccount::ChequingAccount(double balanceNum, double trans, double monthEnd) : Account(balanceNum){
		if (trans > 0) { //if transaction input is positive-valued, apply
			trans_fee = trans;
		}
		else { //else, store 0
			trans_fee = 0.0;
		}
		if (monthEnd > 0) { //if monthly fee input is positive-valued, apply
			monthEnd_fee = monthEnd;
		}
		else { //else, store 0
			monthEnd_fee = 0.0;
		}
	}
	bool ChequingAccount::credit(double creditBalance) {
		if (Account::credit(creditBalance)) { //check the balance by the amount received
			Account::debit(trans_fee); //if success, debit trans_fee from balance
			return true;
		}
		else { //if not, do nothing
			return false;
		}
	}
	bool ChequingAccount::debit(double debitBalance) {
		if (Account::debit(debitBalance)) { //check the amount received
			Account::debit(trans_fee); //if success, debit trans_fee from balance
			return true;
		}
		else { //if not, do nothing
			return false;
		}
	}
	void ChequingAccount::monthEnd() { //debit the monthly fee from balance
		Account::debit(monthEnd_fee);
	}
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << fixed << setprecision(2) << balance() << endl; // fixed + setprecision(2) to put 2 decimal places
		os << "Per Transaction Fee: " << trans_fee << endl;
		os << "Monthly Fee: " << monthEnd_fee << endl;
	}
}
