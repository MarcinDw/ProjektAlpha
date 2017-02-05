#pragma once
#include <string>
#include <string.h>
class Item
{
protected:
	float Weight;
	float Value;
	std::string Nazwa;
	char Type;// O-One handed weapon T-Two handed weapon A-Armor Q-Amulet
public:
	Item();
	~Item();
};

