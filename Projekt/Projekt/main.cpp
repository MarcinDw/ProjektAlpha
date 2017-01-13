#include "Position.h"
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include<stdio.h>
#include "Map2D.h"
#include "Postac.h"
#include "Control.h"
#include "DijkstraMap.h"
// ToDo add error protection
bool initAll()
{
	if (!(al_init()))
	{
		return 0;
		perror("al_init");
	}
	if (!(al_init_primitives_addon()))
	{
		perror("al_init_primitives_addon");
		return 0;
	}
	if (!(al_install_keyboard()))
	{
		perror("al_install_keyboard");
		return 0;
	}
	if (!(al_install_mouse()))
	{
		perror("al_install_mouse");
		return 0;
	}
	return 1;
	//al_init_font_addon();
	//al_init_image_addon();
	//al_init_ttf_addon();
}


int main()
{
	if (!(initAll()))
	{
		return 1;
	}

	ALLEGRO_DISPLAY* Display = al_create_display(800, 600);
	Map2D Test;
	Control CTRL;
	Position PlayerPosition;
	Melee ZombieTest;
	bool TestBool;
	
	TestBool=ZombieTest.GetMoveBlock();
	Test.ReadFromFile("MapTest.txt");
	PlayerPosition = Test.GetPlayerPosition();
	do
	{
		Test.ListaTest();
		Test.Display();
	} while (CTRL.WaitForInput(Test.GetTab(),PlayerPosition));


	return 0;
}
