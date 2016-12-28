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
	virtual void Tick()=0;
	~Pole();
};

