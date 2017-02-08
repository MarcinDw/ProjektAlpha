#pragma once
#include "Postac.h"
#include "Pole.h"
#include "DijkstraMap.h"
#include "Gracz.h"


class Melee :
	public Postac
{
protected:
	ALLEGRO_CONFIG *EnemieConfig;
public:
	Melee();
	Melee(int x, int y);
	void LoadFromFile(char nazwa[]);
	void Tick(int maxx, int maxy, Pole *** Tabela);
	void Interact(Pole* Source);
	bool TakeDamage(int DMG);
	char GetType();
	~Melee();
	void Deathrattle(Pole *** Tabela);
};

