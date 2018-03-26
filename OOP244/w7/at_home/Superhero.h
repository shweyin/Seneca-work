#pragma once
#define _CRT_SECURE_NO_WARNINGS
//Name: Shweyin           Student ID: 115675175
#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero
	{
		int attackBonus;
		int defense;
		void setEmpty();
		bool valid(const char*, int, int, int, int);
		bool isEmpty();
		int attackStrength() const;
		int defenseStrength() const;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
	};
	const SuperHero operator*(const SuperHero&, const SuperHero&);
}