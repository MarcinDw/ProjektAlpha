#pragma once
#include "Position.h"
class Pole
{
	protected :
	Position Pos;
public:
	Pole();
	Pole(int x,int y);
	virtual void Interact()=0;
	virtual void Tick(int maxx, int maxy, Pole *** Tabela);
	virtual bool GetMoveBlock();
	virtual bool GetVisionBlock();
	virtual char GetType();
	virtual void Display();
	~Pole();
	virtual void Move(Pole *** Tabela, Position cel);
};

