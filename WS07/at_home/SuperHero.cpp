// Workshop 7
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: SuperHero.cpp

#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;
namespace sict {
	SuperHero::SuperHero() : Hero() {//safe empty state
		s_bonus = 0;
		s_defend = 0;
	}
	SuperHero::SuperHero(const char* name_, int health_, int strength_, int bonus_, int defends_) : Hero(name_, health_, strength_) {
		if (bonus_ > 0 && defends_ > 0) { //input if it's not empty state
			s_bonus = bonus_;
			s_defend = defends_;
		}
		else {
			*this = SuperHero();
		}
	}

	int SuperHero::attackStrength() const {
		if (s_bonus < 0 && s_defend < 0) {
			return 0;
		}
		else { //return strength if it's not in safe empty state
			int super_attack = Hero::attackStrength() + s_bonus;
			return super_attack;
		}
	}
	int SuperHero::defend() const {
		if (s_bonus < 0 && s_defend < 0) {
			return 0;
		}
		else {
			return s_defend;
		}
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero left = first;
		SuperHero right = second;
		int round = 0;

		for (int i = 0; i < MAX_ROUNDS && left.isAlive() && right.isAlive(); i++) {
			left -= right.attackStrength() - left.defend();
			right -= left.attackStrength() - right.defend();
			round = i + 1;
		}

		if (left.isAlive()) {
			cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
			cout << first << " in " << round << " rounds." << endl;
			return first;
		}
		else if (!left.isAlive() && !right.isAlive()) {
			cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
			cout << first << " in " << round << " rounds." << endl;
			return first;
		}
		else {
			cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
			cout << second << " in " << round << " rounds." << endl;
			return second;
		}
	}
};
