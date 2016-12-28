#include "Pole.h"



Pole::Pole()
{
}

Pole::Pole(int x, int y)
{
	Pos.MoveTo(x, y);
}

bool Pole::GetMoveBlock()
{
	return true;
}

bool Pole::GetVisionBlock()
{
	return true;
}

Pole::~Pole()
{
}
