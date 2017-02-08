#include "Melee.h"



Melee::Melee()
{
}

Melee::Melee(int x, int y) :Postac(x, y)
{
	EnemieConfig = al_load_config_file("EnemieConfig.txt");
	int RNG = rand() % 2;
	switch (RNG)
	{
	case 0:
		LoadFromFile("Zombie");
		break;
	case 1:
		LoadFromFile("Skeleton");
		break;
	}
}

void Melee::LoadFromFile(char nazwa[])
{
	Name = nazwa;
	Attk = std::stoi(al_get_config_value(EnemieConfig, nazwa, "Attk"));
	Defense = std::stoi(al_get_config_value(EnemieConfig, nazwa, "Defense"));
	DamageMin = std::stoi(al_get_config_value(EnemieConfig, nazwa, "DamageMin"));
	DamageMax = std::stoi(al_get_config_value(EnemieConfig, nazwa, "DamageMax"));
	Crit = std::stoi(al_get_config_value(EnemieConfig, nazwa, "Crit"));
	CritMulti = std::stoi(al_get_config_value(EnemieConfig, nazwa, "CritMulti"));
	MaxHP = std::stoi(al_get_config_value(EnemieConfig, nazwa, "MaxHP"));
	HP = MaxHP;
	Type = *(al_get_config_value(EnemieConfig, nazwa, "Type"));
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
	std::cout <<Name <<" took " << DMG << " he has " << HP << " HP left." <<std::endl;
	if (HP > 0)
	{
		return false;
	}
	else
	{
		return false;
	}
}

char Melee::GetType()
{
	return Type;
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