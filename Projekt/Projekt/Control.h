#pragma once
#include "allegro5\allegro.h"
#include "Pole.h"
class Control
{
	ALLEGRO_EVENT_QUEUE* que = NULL;
public:
	Control();
	~Control();
	bool WaitForInput(Pole*** Tab, Position &Player);
	int GetNumber();
};

