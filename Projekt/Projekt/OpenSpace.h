#pragma once
#include "Pole.h"
class OpenSpace :
	public Pole
{
public:
	OpenSpace();
	~OpenSpace();
	void Interact();
	void Tick();
	bool GetMoveBlock();
	bool GetVisionBlock();
};

