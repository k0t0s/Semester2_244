// Workshop 7
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Hero.cpp

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace sict {
	Hero::Hero() { //setting to safe empty state
		name[0] = '\0';
		health = 0;
		strength = 0;
	}
	Hero::Hero(const char* name_, int health_, int strength_) { //inputting file
		if (name_ != nullptr && health_ > 0 && strength_ > 0) {
			strncpy(name, name_, MAX_NAME);
			health = health_;
			strength = strength_;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack) { //Attack is received and subtracts hero's health
		if (strength > 0) {
			health -= attack;
			if (health < 0) {
				health = 0;
			}
		}
	}
	bool Hero::isAlive() const { //return true if health isn't less than 0
		if (health > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int Hero::attackStrength() const { //return 0 if object is in safe empty state
		if (name[0] == '\0' && health == 0 && strength == 0) {
			return 0;
		}
		else { //return strength if it's not in safe empty state
			return strength;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.name == '\0') { //if hero is empty, insert message
			cout << "No hero";
		}
		else { //if it isn't empty, insert name
			cout << hero.name;
		}
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second){
		Hero left = first;
		Hero right = second;
		int round = 0;

		for (int i = 0; i < MAX_ROUNDS && left.isAlive() && right.isAlive(); i++) {
			left -= right.attackStrength();
			right -= left.attackStrength();
			round = i + 1;
		}

		if (left.isAlive()) {
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
			cout << first << " in " << round << " rounds." << endl;
			return first;
		}
		else {
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
			cout << second << " in " << round << " rounds." << endl;
			return second;
		}
	}
};