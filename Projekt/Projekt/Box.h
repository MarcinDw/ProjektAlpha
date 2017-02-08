#pragma once
#include "Pole.h"
#include "Item.h"
#include <list>
#include "Gracz.h"
#include "Control.h"
#include "Armor.h"
class Box :
	public Pole
{
private:
	std::list<Item*> Lista = {};
	std::list<Item*>::iterator it = Lista.begin();
public:
	void Interact(Pole* Source);
	bool GetVisionBlock();
	Box();
	Box(int x, int y);
	~Box();
};

