#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <time.h> 
class CaveMapGen
{
private:
	int x;
	int y;
	char** Map;
	char** Map2;
	void MakeNewMap();
	void MakeNoise();
	void SmoothTheWalls();
	bool PlaceMonsters();
	int Adcjecent(int cx,int cy,bool m);
	void Pisz();
	void AddXofY(char sign, int Number);
	void SaveToFile(std::string Nazwa);
	void CreateBorder();
public:
	CaveMapGen();
	CaveMapGen(int ix, int iy, std::string NazwaPliku);
	~CaveMapGen();
};

