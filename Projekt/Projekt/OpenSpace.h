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
	bool GetMoveBlock();
	bool GetVisionBlock();
};

