#include "Gracz.h"



Gracz::Gracz()
{
}

Gracz::Gracz(int x, int y) :Postac(x, y)
{
	Attk = 0;
	Defense = 0;
	DamageMin = 1;
	DamageMax = 6;
	Crit = 10;
	CritMulti = 2;
	MaxHP = 200;
	HP = 200;
}

Gracz::~Gracz()
{
}

void Gracz::Tick(int maxx, int maxy, Pole *** Tabela)
{
}

void Gracz::Interact()
{
	std::cout << std::endl << "Gracz trafiony" << std::endl;
}

char Gracz::GetType()
{
	return '@';
}

void Gracz::Display()
{
	std::cout << '@';
}

void Gracz::Move(Pole*** Tabela, Position cel)
{
		Pole * temp = Below;
		Below = Tabela[cel.x][cel.y];
		Tabela[cel.x][cel.y] = Tabela[Pos.x][Pos.y];
		Tabela[Pos.x][Pos.y] = temp;
		Pos = cel;
}

bool Gracz::TakeDamage(int DMG)
{
	HP -= DMG;
	std::cout << std::endl << "New HP " << HP << "Damage Taken " << DMG << std::endl;
	if (HP < 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}