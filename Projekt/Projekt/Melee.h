#pragma once
#include "Postac.h"
#include "Pole.h"
#include "DijkstraMap.h"


class Melee :
	public Postac
{
public:
	Melee();
	Melee(int x, int y);
	void Tick(int maxx, int maxy, Pole *** Tabela);
	void Display();
	~Melee();
};

