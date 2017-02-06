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


bool Control::WaitForInput(Pole*** Tab,Position &Player)
{
	Tab[Player.x][Player.y]->Tick(Player.x,Player.y,Tab);
	ALLEGRO_EVENT eve;
	do
	{
		al_wait_for_event(que, &eve);
	}
	while (eve.type != ALLEGRO_EVENT_KEY_DOWN);

	switch (eve.keyboard.keycode)
	{
	case ALLEGRO_KEY_PAD_1:
		if (!(Tab[Player.x + 1][Player.y - 1]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab,Position(Player.x+1,Player.y-1));
			Player.Move(1, -1);
		}
		else
		{
			Tab[Player.x + 1][Player.y - 1]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_2:
		if (!(Tab[Player.x + 1][Player.y]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x + 1, Player.y));
			Player.Move(1, 0);
		}
		else
		{
			Tab[Player.x + 1][Player.y]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_3:
		if (!(Tab[Player.x + 1][Player.y + 1]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x + 1, Player.y + 1));
			Player.Move(1, 1);
		}
		else
		{
			Tab[Player.x + 1][Player.y + 1]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_4:
		if (!(Tab[Player.x][Player.y - 1]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x, Player.y - 1));
			Player.Move(0, -1);
		}
		else
		{
			Tab[Player.x][Player.y - 1]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_5:Tab[Player.x][Player.y]->Interact(Tab[Player.x][Player.y]);
		break;
	case ALLEGRO_KEY_PAD_6:
		if (!(Tab[Player.x][Player.y + 1]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x, Player.y + 1));
			Player.Move(0, +1);
		}
		else
		{
			Tab[Player.x][Player.y + 1]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_7:
		if (!(Tab[Player.x - 1][Player.y - 1]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x - 1, Player.y - 1));
			Player.Move(-1, -1);
		}
		else
		{
			Tab[Player.x - 1][Player.y - 1]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_8:
		if (!(Tab[Player.x - 1][Player.y]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x - 1, Player.y));
			Player.Move(-1, 0);
		}
		else
		{
			Tab[Player.x - 1][Player.y]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_PAD_9:
		if (!(Tab[Player.x - 1][Player.y + 1]->GetMoveBlock()))
		{
			Tab[Player.x][Player.y]->Move(Tab, Position(Player.x - 1, Player.y + 1));
			Player.Move(-1, +1);
		}
		else
		{
			Tab[Player.x - 1][Player.y + 1]->Interact(Tab[Player.x][Player.y]);
		}
		break;
	case ALLEGRO_KEY_ESCAPE: 
		perror("ESC Pressed");
		return false;
		break;
	}
	return true;
}

int Control::GetNumber()
{
	ALLEGRO_EVENT eve;
	do
	{
		al_wait_for_event(que, &eve);
	} while (eve.type != ALLEGRO_EVENT_KEY_DOWN);

	switch (eve.keyboard.keycode)
	{
	case ALLEGRO_KEY_PAD_1:
		return 1;
	case ALLEGRO_KEY_PAD_2:
		return 2;
	case ALLEGRO_KEY_PAD_3:
		return 3;
	case ALLEGRO_KEY_PAD_4:
		return 4;
	case ALLEGRO_KEY_PAD_5:
		return 5;
	case ALLEGRO_KEY_PAD_6:
		return 6;
	case ALLEGRO_KEY_PAD_7:
		return 7;
	case ALLEGRO_KEY_PAD_8:
		return 8;
	case ALLEGRO_KEY_PAD_9:
		return 9;
	case ALLEGRO_KEY_PAD_0:
		return 0;
	}
	return 0;
}
