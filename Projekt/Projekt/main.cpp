#include "Position.h"
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include <cstdlib> 
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Map2D.h"
#include "Postac.h"
#include "Control.h"
#include "DijkstraMap.h"
#include "CaveMapGen.h"
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
	Gracz* Player;
	Melee ZombieTest;
	int debug;
	bool HP=true;
	bool Victory=true;
	CaveMapGen TestGen(50, 50, "temp.txt");


	srand(time(NULL));
	Test.ReadFromFile("temp.txt");
	PlayerPosition = Test.GetPlayerPosition();
	do
	{
		//system("CLS");
		Test.UpdatePlayerPosition(PlayerPosition);
		Player = dynamic_cast<Gracz*>(Test.GetTab()[PlayerPosition.x][PlayerPosition.y]);
		HP = Player->Alive();
		Test.Turn();
		if ((debug=Test.GetEnemies()) == 0)
		{
			Victory = false;
		}
		Test.Display();
	} while ((CTRL.WaitForInput(Test.GetTab(),PlayerPosition))&&(HP)&&(Victory));
	if (HP)
	{
		if (Victory)
		{
			std::cout << std::endl << "Good bye" << std::endl;
		}
		else
		{
			std::cout << std::endl << "You won YAY!!" << std::endl;
		}
	}
	else 
	{
		std::cout << std::endl << "The Hero is Dead..." << std::endl;
	}
	al_rest(1);
	return 0;
}
