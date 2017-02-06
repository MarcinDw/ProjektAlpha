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
			std::cout << i << " " << (*it)->GetName() << std::endl;
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
	p1 = new Weapon();
	p2 = new Weapon();
	Lista.push_back(p1);
	Lista.push_back(p2);
}

Box::~Box()
{
}
