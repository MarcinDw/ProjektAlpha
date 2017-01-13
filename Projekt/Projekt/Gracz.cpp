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