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

void Wall::Tick()
{
	std::cout << '#';
	//Tutaj wpisać co się dzieje za każdym razem jak postać się ruszy (Nie wiem jak będziesz robić dynamiczne oświetlenie ale może się przydać)
}


Wall::~Wall()
{
}
