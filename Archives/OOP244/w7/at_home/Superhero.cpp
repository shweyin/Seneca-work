#include "SuperHero.h"
//Name: Shweyin           Student ID: 115675175

namespace sict {
	SuperHero::SuperHero()
	{
		setEmpty();
	}

	SuperHero::SuperHero(const char* cons_name, int cons_health, int cons_strength, int cons_attackBonus, int cons_defense)
	{
		if (valid(cons_name, cons_health, cons_strength, cons_attackBonus, cons_defense))
		{
			setHero(cons_name, cons_health, cons_strength);
			attackBonus = cons_attackBonus;
			defense = cons_defense;
		}
		else
		{
			setEmpty();
		}
	}
	void SuperHero::setEmpty()
	{
		setHero("", 0, 0);
		attackBonus = 0;
		defense = 0;
	}
	bool SuperHero::valid(const char * unvalidated_name, int unvalidated_health, int intunvalidated_strength, int unvalidated_attackBonus, int unvalidated_defense)
	{
		return (unvalidated_name && unvalidated_health > 0 && intunvalidated_strength > 0 && unvalidated_attackBonus > 0 && unvalidated_defense > 0);
	}
	bool SuperHero::isEmpty()
	{
		return (attackBonus == 0 && defense == 0);
	}
	int SuperHero::attackStrength() const
	{
		int attack1 = Hero::attackStrength();
		return attack1 + attackBonus;
	}
	int SuperHero::defend() const
	{
		return defense;
	}
	const SuperHero operator*(const SuperHero& lhsSuperHero, const SuperHero& rhsSuperHero)
	{
		SuperHero temp_lhsSuperHero = lhsSuperHero;
		SuperHero temp_rhsSuperHero = rhsSuperHero;
		const SuperHero *temp_winner = nullptr;
		int i = 0;
		while (temp_lhsSuperHero.isAlive() && temp_rhsSuperHero.isAlive() && i < max_rounds)
		{
			temp_lhsSuperHero -= rhsSuperHero.attackStrength() - lhsSuperHero.defend();
			temp_rhsSuperHero -= lhsSuperHero.attackStrength() - rhsSuperHero.defend();
			i++;
		}

		temp_winner = temp_rhsSuperHero.isAlive() ? &rhsSuperHero : &lhsSuperHero;

		std::cout << "Super Fight! " << lhsSuperHero << " vs " << rhsSuperHero << " : Winner is " << *temp_winner << " in " << i << " rounds." << std::endl;

		return *temp_winner;
	}
}