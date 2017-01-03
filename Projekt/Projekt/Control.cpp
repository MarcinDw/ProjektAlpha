#include "Control.h"



Control::Control()
{
	que = al_create_event_queue();
	if (que != NULL)
	{
		al_register_event_source(que, al_get_keyboard_event_source());
		perror("Que creation sucesful");
	}
}


Control::~Control()
{
}


bool Control::WaitForInput(Pole*** Tab,Position Player)
{
	ALLEGRO_EVENT eve;
	do
	{
		perror ("Why?");
		al_wait_for_event(que, &eve);
		perror("You not work");
	}
	while (eve.type != ALLEGRO_EVENT_KEY_DOWN);

	/*
	switch (eve.keyboard.keycode)
	{
	case ALLEGRO_KEY_PAD_1:Tab[Player.x+1][Player.y+1]->Interact();
		break;
	case ALLEGRO_KEY_PAD_2:Tab[Player.x][Player.y + 1]->Interact();
		break;
	case ALLEGRO_KEY_PAD_3:Tab[Player.x - 1][Player.y + 1]->Interact();
		break;
	case ALLEGRO_KEY_PAD_4:Tab[Player.x + 1][Player.y]->Interact();
		break;
	case ALLEGRO_KEY_PAD_5:Tab[Player.x][Player.y]->Interact();
		break;
	case ALLEGRO_KEY_PAD_6:Tab[Player.x - 1][Player.y]->Interact();
		break;
	case ALLEGRO_KEY_PAD_7:Tab[Player.x + 1][Player.y - 1]->Interact();
		break;
	case ALLEGRO_KEY_PAD_8:Tab[Player.x][Player.y - 1]->Interact();
		break;
	case ALLEGRO_KEY_PAD_9:Tab[Player.x - 1][Player.y - 1]->Interact();
		break;
	case ALLEGRO_KEY_ESCAPE: 
		perror("ESC Pressed");
		return false;
		break;
	}
	*/
	return false;
}