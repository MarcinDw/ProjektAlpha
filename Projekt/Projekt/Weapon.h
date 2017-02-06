#pragma once
#include "Item.h"
#include "allegro5\allegro_memfile.h"
#include <allegro5/allegro.h>
class Weapon :
	public Item
{
private:
	void LoadFromFile(char nazwa[]);
	ALLEGRO_CONFIG *Weapons;
public:
	int MinDamage;
	int MaxDamage;
	int Attack;
	int Crit;
	int CritMulti;
	char DamageType;//B-bludgening S-Slashing P-Piercing F-Fire
public:
	Weapon();
	~Weapon();
};

