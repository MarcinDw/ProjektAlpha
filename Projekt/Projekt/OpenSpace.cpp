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

void OpenSpace::Interact()
{

}

void OpenSpace::Tick(Pole *** Tabela)
{
}

char OpenSpace::GetType()
{
	return '#';
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
	std::cout << ',';
}