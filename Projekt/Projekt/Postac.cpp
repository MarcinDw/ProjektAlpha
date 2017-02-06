#include "Postac.h"



Postac::Postac()
{

}

Postac::Postac(int x, int y) :Pole(x, y)
{
	Below = new OpenSpace(x,y);
}
Postac::~Postac()
{
}

bool Postac::GetMoveBlock()
{
	return true;
}

bool Postac::GetVisionBlock()
{
	return false;
}

void Postac::Interact(Pole* Source)
{
}

void Postac::Tick(int maxx, int maxy, Pole *** Tabela)
{
}

bool Postac::TakeDamage(int DMG)
{
	HP -= DMG;
	std::cout << std::endl << "New HP " << HP;
	if (HP < 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool Postac::Attack(Postac* P)
{
	int Roll = rand() % 100;
	if ((Attk + Roll) > P->Defense)
	{
		int Damage = rand() % (DamageMax - DamageMin) + DamageMin;
		if (Roll > 100-Crit)
		{
			P->TakeDamage(Damage*CritMulti);
		}
		else
		{
			P->TakeDamage(Damage);
		}
		return true;
	}
	return false;
}


void Postac::Deathrattle(Pole*** Tabela)
{
	Tabela[Pos.x][Pos.y] = Below;
}

void Postac::Move(Pole*** Tabela,Position cel)
{
	Pole * temp = Below;
	Below = Tabela[cel.x][cel.y];
	Tabela[cel.x][cel.y] = Tabela[Pos.x][Pos.y];
	Tabela[Pos.x][Pos.y]=temp;
	Pos = cel;
}

void Postac::Display()
{
}

int Postac::GetAC()
{
	return Defense;
}
