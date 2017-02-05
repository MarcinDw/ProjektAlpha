#pragma once
#include "Postac.h"
#include "Pole.h"
#include "DijkstraMap.h"
#include "Gracz.h"


class Melee :
	public Postac
{
public:
	Melee();
	Melee(int x, int y);
	void Tick(int maxx, int maxy, Pole *** Tabela);
	void Interact(Pole* Source);
	bool TakeDamage(int DMG);
	void Display();
	char GetType();
	~Melee();
	void Deathrattle(Pole *** Tabela);
};

