﻿#pragma once
#include<string>
#include <iostream>
#include <fstream>
//Include dla wszystkich rodzaji danych wejściowych
#include"Pole.h"
#include "Wall.h"
#include "OpenSpace.h"
#include "Gracz.h"
class Map2D
{
protected:
	Pole*** Tab;
	int x;
	int y;
	Position PlayerPosition;
public:
	Map2D();
	~Map2D();
	bool ReadFromFile(std::string Filename);
	bool Generuj(std::string Dane, int x, int y);
	Pole*** GetTab();
	Position GetPlayerPosition();
	void Turn();
};

