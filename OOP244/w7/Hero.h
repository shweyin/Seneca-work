#pragma once
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
		void setEmpty();
		bool valid(char*, int, int);
		bool isAlive() const;
		int attackStrength() const;
	public:
		Hero();
		Hero(char*, int, int);
		bool isEmpty() const;
		void operator-=(int);	
		friend std::ostream& operator<<(std::ostream&, const Hero&);
		friend const Hero& operator*(const Hero&, const Hero&);
	};
}