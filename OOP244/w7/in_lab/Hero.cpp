#include "Hero.h"

namespace sict
{
	Hero::Hero()
	{
		setEmpty();
	}
	Hero::Hero(const char* con_name, int con_health, int con_strength)
	{
		if (valid(con_name, con_health, con_strength))
		{
			strcpy(name, con_name);
			health = con_health;
			strength = con_strength;
		}
		else
		{
			setEmpty();
		}
	}
	void Hero::setEmpty()
	{
		strcpy(name, "");
		health = 0;
		strength = 0;
	}
	bool Hero::isEmpty() const
	{
		return (strcmp(name, "") == 0 && health == 0 && strength == 0);
	}
	bool Hero::valid(const char* unvalidated_name, int unvalidated_health, int unvalidated_strength)
	{
		return (unvalidated_name != nullptr && unvalidated_health > -1 && unvalidated_strength > 0);
	}
	bool Hero::isAlive() const
	{
		return health > 0;
	}
	int Hero::attackStrength() const
	{
		return strength > 0 ? strength : 0;
	}
	void Hero::operator-=(int attack)
	{
		health -= attack;
	}
	std::ostream & operator<<(std::ostream& ostr, const Hero& thisHero)
	{
		if (thisHero.isEmpty())
		{
			ostr << "No Hero";
		}
		else
		{
			ostr << thisHero.name;
		}
		return ostr;
	}
	const Hero& operator*(const Hero& lhsHero, const Hero& rhsHero)
	{
		Hero temp_lhsHero = lhsHero;
		Hero temp_rhsHero = rhsHero;
		const Hero *temp_winner = nullptr;
		int i = 0;
		while (temp_lhsHero.isAlive() && temp_rhsHero.isAlive() && i < max_rounds)
		{
			temp_lhsHero -= rhsHero.strength;
			temp_rhsHero -= lhsHero.strength;
			i++;
		}

		temp_winner = temp_rhsHero.isAlive() ? &rhsHero : &lhsHero;

		std::cout << "Ancient Battle! " << lhsHero << " vs " << rhsHero << " : Winner is " << *temp_winner << " in " << i << " rounds." << std::endl;

		return *temp_winner;
	}

}