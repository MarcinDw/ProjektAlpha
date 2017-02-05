#include "Melee.h"



Melee::Melee()
{
}

Melee::Melee(int x, int y) :Postac(x, y)
{
	Attk = 0;
	Defense = 0;
	DamageMin = 1;
	DamageMax = 4;
	Crit = 5;
	CritMulti = 2;
	MaxHP = 20;
	HP = 20;
}

void Melee::Tick(int maxx, int maxy, Pole *** Tabela)
{
	Position Target;
	if (MoveMap == NULL)
	{
		MoveMap = new DijkstraMap(maxx, maxy);
	}
	if (HP < 1)
	{
		Deathrattle(Tabela);
	}
	else
	{
		MoveMap->AssignStart();
		MoveMap->AssignPriority('@', 0, Tabela);
		MoveMap->Generate(Tabela);
		//MoveMap->Pisz();
		Target = MoveMap->Min(Pos);
		if (Tabela[Target.x][Target.y]->GetMoveBlock())
		{
			if (Tabela[Target.x][Target.y]->GetType() == '@')
			{
				Gracz* p = dynamic_cast<Gracz*>(Tabela[Target.x][Target.y]);
				if (p != nullptr)
				{
					Attack(p);
				}
			}
		}
		else
		{
			Move(Tabela, MoveMap->Min(Pos));
		}
	}
}

void Melee::Interact(Pole * Source)
{
	if (Source->GetType() == '@')
	{
		Gracz* p = dynamic_cast<Gracz*>(Source);
		if (p != nullptr)
		{
			p->Attack(this);
		}
	}
}

bool Melee::TakeDamage(int DMG)
{
	HP -= DMG;
	std::cout << "Zombie took " << DMG << " he has " << HP << " HP left." <<std::endl;
	if (HP > 0)
	{
		return false;
	}
	else
	{
		return false;
	}
}

void Melee::Display()
{
	if (Visible)
	{
		std::cout << 'z';
	}
	else
	{
		std::cout << ' ';
	}
}

char Melee::GetType()
{
	return'z';
}


Melee::~Melee()
{
}

void Melee::Deathrattle(Pole *** Tabela)
{
	Tabela[Pos.x][Pos.y] = Below;
	
	delete(MoveMap);
	delete(this);
}