#include "Gracz.h"



Gracz::Gracz()
{
}

Gracz::Gracz(int x, int y) :Postac(x, y)
{

}

Gracz::~Gracz()
{
}

void Gracz::Tick()
{
	std::cout << '@';
}

