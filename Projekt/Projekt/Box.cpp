#include "Box.h"



void Box::Interact(Pole * Source)
{
	Control con;
	if (Source->GetType() == '@')
	{
		Gracz* Player = dynamic_cast<Gracz*>(Source);
		int i = 0;
		int j = 0;
		for (it = Lista.begin(); it != Lista.end(); it++)
		{
			if ((*it)->GetType() == 'A')
			{
				Armor* temp;
				temp = dynamic_cast<Armor*>(*it);
				std::cout << i << " " << *temp << std::endl;
			}
			else
			{
				Weapon* temp;
				temp = dynamic_cast<Weapon*>(*it);
				std::cout << i << " " << *temp << std::endl;
			}
			i++;
		}
		std::cout << i << " " << "exit" << std::endl;
		con.GetNumber();
		if ((j < i) && (j >= 0))
		{
			i = 0;
			it = Lista.begin();
			while (i != j)
			{
				it++;
				i++;
			}
			(*it) = Player->Equip((*it));
		}
	}
	Lista.remove(nullptr);
}

bool Box::GetVisionBlock()
{
	return false;
}

Box::Box()
{
	Type = 'C';
	Item* p1;
	Item* p2;
	p1 = new Weapon();
	p2 = new Weapon();
	Lista.push_back(p1);
	Lista.push_back(p2);
}

Box::Box(int x, int y) :Pole(x, y)
{
	Type = 'C';
	Item* p1;
	Item* p2;
	int RNG = rand() % 2;
	switch (RNG)
	{
	case 1:
		p1 = new Weapon();
		break;
	case 0:
		p1 = new Armor();
	}
	RNG = rand() % 2;
	switch (RNG)
	{
	case 1:
		p2 = new Weapon();
		break;
	case 0:
		p2 = new Armor();
	}
	Lista.push_back(p1);
	Lista.push_back(p2);
}

Box::~Box()
{
	it = Lista.begin();
	while (it != Lista.end())
	{
		delete(*it);
	}
	Lista.clear();
}
