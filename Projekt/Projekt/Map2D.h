#pragma once
#include<string>
#include <iostream>
#include <fstream>
#include <list>
//Include dla wszystkich rodzaji danych wejściowych
#include"Pole.h"
#include "Wall.h"
#include "Melee.h"
#include "OpenSpace.h"
#include "Gracz.h"
class Map2D
{
protected:
	Pole*** Tab;
	int x;
	int y;
	Position PlayerPosition;
	std::list<Pole*> Lista = {};
	std::list<Pole*>::iterator it = Lista.begin();

public:
	Map2D();
	~Map2D();
	bool ReadFromFile(std::string Filename);
	bool Generuj(std::string Dane, int x, int y);
	Pole*** GetTab();
	int Getx();
	int Gety();
	Position GetPlayerPosition();
	void ListaTest();
	void Turn();
	void Display();
};

