// Workshop 7
// Name: Koto Sumioka
// Student #: 110206174
// Course: OOP244 Fall 2018
// File: SuperHero.h
#ifndef SICT_SUPER_HERO_H
#define SICT_SUPER_HERO_H

#include <iostream>
#include "Hero.h"

using namespace std;
namespace sict {
	class SuperHero : public Hero{
		int s_bonus;
		int s_defend;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);

		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif