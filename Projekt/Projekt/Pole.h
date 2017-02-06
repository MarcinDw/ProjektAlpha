#pragma once
#include "Position.h"
class Pole
{
	protected :
	Position Pos;
	bool Visible;
	bool FoW;
	char Type;
public:
	Pole();
	Pole(int x,int y);
	virtual void Interact(Pole* Source)=0;
	virtual void Tick(int maxx, int maxy, Pole *** Tabela);
	virtual bool GetMoveBlock();
	virtual bool GetVisionBlock();
	virtual void ChangeVision(bool V);
	virtual bool GetVisible();
	virtual bool GetFoW();
	virtual char GetType();
	virtual void Display();
	~Pole();
	virtual void Move(Pole *** Tabela, Position cel);
};

