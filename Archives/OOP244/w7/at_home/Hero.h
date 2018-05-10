#pragma once
//Name: Shweyin           Student ID: 115675175
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


namespace sict
{
	const int max_rounds = 100;
	const int name_size = 41;
	class Hero
	{
		char name[name_size];
		int health;
		int strength;
	public:
		Hero();
		Hero(const char*, int, int);
		void setHero(const char*, int, int);
		bool valid(const char*, int, int);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		void operator-=(int);
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);

}