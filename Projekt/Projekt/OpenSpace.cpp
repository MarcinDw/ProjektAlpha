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

void OpenSpace::Tick()
{
	std::cout << ',';
}

bool OpenSpace::GetMoveBlock()
{
	return false;
}

bool OpenSpace::GetVisionBlock()
{
	return false;
}
