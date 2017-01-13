#pragma once
#include "Postac.h"
class Gracz :
	public Postac
{
public:
	Gracz();
	Gracz(int x, int y);
	~Gracz();
	void Tick(int maxx, int maxy, Pole *** Tabela);
	void Interact();
	virtual char GetType();
	void Display();
};

