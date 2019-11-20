// Workshop 7
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: Hero.h

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>

using namespace std;
namespace sict {
	const int MAX_ROUNDS = 100;
	const int MAX_NAME = 40;

	class Hero {
		char name[MAX_NAME];
		int health;
		int strength;

	public:
		Hero();
		Hero(const char*, int, int);

		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif