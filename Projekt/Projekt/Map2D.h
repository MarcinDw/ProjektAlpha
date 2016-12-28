#pragma once
#include"Pole.h"
#include<string>
#include <iostream>
#include <fstream>
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
};

