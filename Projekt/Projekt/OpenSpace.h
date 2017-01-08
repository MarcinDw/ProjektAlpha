#pragma once
#include "Pole.h"
class OpenSpace :
	public Pole
{
public:
	OpenSpace();
	OpenSpace(int x, int y);
	~OpenSpace();
	void Interact();
	void Tick();
	char GetType();
	bool GetMoveBlock();
	bool GetVisionBlock();
};

