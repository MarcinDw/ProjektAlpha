#pragma once
#include "Postac.h"
class Gracz :
	public Postac
{
public:
	Gracz();
	Gracz(int x, int y);
	~Gracz();
	void Tick();
};

