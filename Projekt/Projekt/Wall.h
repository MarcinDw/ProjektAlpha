#pragma once
#include "Pole.h"
class Wall :
	public Pole
{
public:
	Wall();
	Wall(int x, int y);
	void Interact();
	void Tick(int maxx, int maxy, Pole *** Tabela);
	~Wall();
	void Display();
};

