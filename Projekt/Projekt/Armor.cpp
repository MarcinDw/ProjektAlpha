#include "Armor.h"



void Armor::LoadFromFile(char nazwa[])
{
	Nazwa = nazwa;
	Defense = std::stoi(al_get_config_value(Armors, nazwa, "Defense"));
	Type = 'A';
	Weight = 0;
	Value = 0;
}

int Armor::GetDef()
{
	return Defense;
}

Armor::Armor()
{
	Armors = al_load_config_file("ArmorStats.txt");
	int RNG = rand() % 3;
	switch (RNG)
	{
	case 0:
		LoadFromFile("Chainshirt");
		break;
	case 1:
		LoadFromFile("Breastplate");
		break;
	case 2:
		LoadFromFile("Stoneplate");
		break;
	}
}


Armor::~Armor()
{
}

std::ostream & operator<<(std::ostream & os, Armor & A)
{
	os << A.Nazwa << " Def:" << A.Defense;
	return os;
}
