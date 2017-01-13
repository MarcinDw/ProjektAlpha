#include "Wall.h"



Wall::Wall()
{
}

Wall::Wall(int x, int y):Pole(x,y)
{

}

void Wall::Interact()
{
	//Tu wpisać co się stanie jak postać będzie chiała na to wejść (Jakiś dźwięk albo coś takiego żeby było wiadomo że coś się dieje)
}

void Wall::Tick(int maxx, int maxy, Pole *** Tabela)
{
}

Wall::~Wall()
{
}

void Wall::Display()
{
	std::cout << '#';
}