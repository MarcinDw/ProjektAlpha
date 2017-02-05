#include "OpenSpace.h"



OpenSpace::OpenSpace()
{
}
OpenSpace::OpenSpace(int x, int y) :Pole(x, y)
{

}

OpenSpace::~OpenSpace()
{
}

void OpenSpace::Interact(Pole* Source)
{

}

void OpenSpace::Tick(Pole *** Tabela)
{
}

char OpenSpace::GetType()
{
	return ',';
}

bool OpenSpace::GetMoveBlock()
{
	return false;
}

bool OpenSpace::GetVisionBlock()
{
	return false;
}

void OpenSpace::Display()
{
	if (Visible)
	{
		std::cout << ',';
	}
	else
	{
		std::cout << ' ';
	}
}