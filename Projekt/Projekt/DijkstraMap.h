#pragma once
#include "Pole.h"
#include "Position.h"
#include <iomanip>
class DijkstraMap
{
	Pole*** Tabela;
	int ** Map;
	int AsignedValues;
	int maxx;
	int maxy;
public:
	DijkstraMap();
	DijkstraMap(int maxx, int maxy);
	~DijkstraMap();
	void Generate(Pole *** Mapa);
	void AssignStart();
	void AssignPriority(char znak, int wartosc, Pole *** Mapa);
	int Nextto(int x,int y);
	Position Min(Position Pos);
	void Pisz();
};