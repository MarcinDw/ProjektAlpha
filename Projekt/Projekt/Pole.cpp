#include "Pole.h"



Pole::Pole()
{
}

Pole::Pole(int x, int y)
{
	Pos.MoveTo(x, y);
	FoW = true;
}

void Pole::Tick(int maxx, int maxy, Pole *** Tabela)
{
}

bool Pole::GetMoveBlock()
{
	return true;
}

bool Pole::GetVisionBlock()
{
	return true;
}

void Pole::ChangeVision(bool V)
{
	Visible=V;
	if (Visible)
	{
		FoW = false;
	}
}

bool Pole::GetVisible()
{
	return Visible;
}

bool Pole::GetFoW()
{
	return FoW;
}

char Pole::GetType()
{
	return Type;
}

void Pole::Display()
{
	if (Visible)
	{
		std::cout << GetType();
	}
	else
	{
		std::cout << ' ';
	}
}

Pole::~Pole()
{
}

void Pole::Move(Pole*** Tabela, Position cel)
{
	perror("To pole nie moze sie ruszyc");
}