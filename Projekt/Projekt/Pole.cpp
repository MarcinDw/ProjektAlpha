#include "Pole.h"



Pole::Pole()
{
}

Pole::Pole(int x, int y)
{
	Pos.MoveTo(x, y);
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

char Pole::GetType()
{
	return 0;
}

void Pole::Display()
{
}

Pole::~Pole()
{
}

void Pole::Move(Pole*** Tabela, Position cel)
{
	perror("To pole nie moze sie ruszyc");
}