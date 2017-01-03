#include "Postac.h"



Postac::Postac()
{

}

Postac::Postac(int x, int y) :Pole(x, y)
{
	Attk = 0;
	Defense = 0;
	DamageMin = 1;
	DamageMax = 200;
	Crit = 10;
	CritMulti = 2;
	MaxHP = 20;
	HP = 20;
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

void Postac::Interact()
{
}

void Postac::Tick()
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

bool Postac::Attack(Postac P)
{
	int Roll = rand() % 100;
	if ((Attk + Roll) > P.Defense)
	{
		int Damage = rand() % (DamageMax - DamageMin) + DamageMin;
		if (Roll > 100-Crit)
		{
			P.TakeDamage(Damage*CritMulti);
		}
		else
		{
			P.TakeDamage(Damage);
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
	Tabela[Pos.x][Pos.y]=temp;
	Pos = cel;
}