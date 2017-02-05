#pragma once
#include "Pole.h"
class OpenSpace :
	public Pole
{
public:
	OpenSpace();
	OpenSpace(int x, int y);
	~OpenSpace();
	void Interact(Pole* Source);
	void Tick(Pole *** Tabela);
	char GetType();
	bool GetMoveBlock();
	bool GetVisionBlock();
	void Display();
};

