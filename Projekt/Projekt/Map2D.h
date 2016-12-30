#pragma once
#include<string>
#include <iostream>
#include <fstream>
//Include dla wszystkich rodzaji danych wejściowych
#include"Pole.h"
#include "Wall.h"
#include "OpenSpace.h"
class Map2D
{
protected:
	Pole*** Tab;
	int x;
	int y;
public:
	Map2D();
	~Map2D();
	bool ReadFromFile(std::string Filename);
	bool Generuj(std::string Dane, int x, int y);
	void Turn();
};

