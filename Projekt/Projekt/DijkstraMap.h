#pragma once
#include "Pole.h"
#include "Position.h"
#include <iomanip>
class DijkstraMap
{
	Pole***Tabela;
	int ** Map;
	int maxx;
	int maxy;
public:
	DijkstraMap();
	DijkstraMap(int maxx, int maxy, Position PCPos, Pole*** Mapa);
	~DijkstraMap();
	void Generate(Position PCPos, Pole*** Mapa);
	int Nextto(int x,int y);
	void Pisz();
};

