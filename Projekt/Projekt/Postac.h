#pragma once
#include "Pole.h"
#include "OpenSpace.h"
#include "DijkstraMap.h"
#include <string>
class Postac :
	public Pole
{
protected:
	DijkstraMap* MoveMap=NULL;
	std::string Name;
	int Attk;
	int Defense;
	int HP;
	int MaxHP;
	int DamageMin;
	int DamageMax;
	int Crit;
	int CritMulti;
	Pole* Below;
public:
	Postac();
	Postac(int x, int y);
	~Postac();
	virtual bool GetMoveBlock();
	virtual bool GetVisionBlock();
	virtual void Interact(Pole* Source);
	virtual void Tick(int maxx, int maxy, Pole *** Tabela);
	virtual bool TakeDamage(int DMG);
	virtual bool Attack(Postac* P);
	virtual void Deathrattle(Pole *** Tabela);
	virtual void Move(Pole *** Tabela, Position cel);
	virtual int GetAC();
};

