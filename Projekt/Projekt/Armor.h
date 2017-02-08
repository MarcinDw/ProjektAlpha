#pragma once
#include "Item.h"
#include <allegro5/allegro.h>
#include<iostream>
class Armor :
	public Item
{
private:
	ALLEGRO_CONFIG *Armors;
	int Defense;
public:
	void LoadFromFile(char nazwa[]);
	friend std::ostream& operator<<(std::ostream& os, Armor& A);
	int GetDef();
	Armor();
	~Armor();
};

