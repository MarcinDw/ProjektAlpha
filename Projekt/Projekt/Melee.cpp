#include "Melee.h"



Melee::Melee()
{
}

Melee::Melee(int x, int y) :Postac(x, y)
{
}

void Melee::Tick(int maxx, int maxy, Pole *** Tabela)
{
	Position Target;
	if (MoveMap == NULL)
	{
		MoveMap = new DijkstraMap(maxx, maxy);
	}
	MoveMap->AssignStart();
	MoveMap->AssignPriority('@', 0, Tabela);
	MoveMap->Generate(Tabela);
	MoveMap->Pisz();
	Target = MoveMap->Min(Pos);
	if (Tabela[Target.x][Target.y]->GetMoveBlock())
	{
		Tabela[Target.x][Target.y]->Interact();
	}
	else
	{
		Move(Tabela, MoveMap->Min(Pos));
	}
}

void Melee::Display()
{
	std::cout << 'z';
}


Melee::~Melee()
{
}
