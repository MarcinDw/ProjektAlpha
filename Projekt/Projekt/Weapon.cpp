#include "Weapon.h"



void Weapon::LoadFromFile(char nazwa[])
{
	Nazwa = nazwa;
	Value = std::stoi(al_get_config_value(Weapons, nazwa, "Value"));
	MinDamage = std::stoi(al_get_config_value(Weapons, nazwa, "MinDamage"));
	MaxDamage = std::stoi(al_get_config_value(Weapons, nazwa, "MaxDamage"));
	Crit = std::stoi(al_get_config_value(Weapons, nazwa, "Crit"));
	CritMulti = std::stoi(al_get_config_value(Weapons, nazwa, "CritMulti"));
	DamageType = *(al_get_config_value(Weapons, nazwa, "DamageType"));
	Type = *(al_get_config_value(Weapons, nazwa, "Type"));
}

Weapon::Weapon()
{
	Weapons = al_load_config_file("WeaponsStats.txt");
	int RNG = rand() % 5;
	switch (RNG)
	{
	case 0:
		LoadFromFile("Club");
		break;
	case 1:
		LoadFromFile("Shortspear");
		break;
	case 2:
		LoadFromFile("Earthbreaker");
		break;
	case 3:
		LoadFromFile("Greataxe");
		break;
	case 4:
		LoadFromFile("Scythe");
		break;
	default:
		LoadFromFile("Dagger");
		break;
	}
}


Weapon::~Weapon()
{
}
