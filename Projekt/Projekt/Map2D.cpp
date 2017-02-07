#include "Map2D.h"



Map2D::Map2D()
{
	x = 0;
	y = 0;
}


Map2D::~Map2D()
{
	for (int i = 0; i < x; i++)
	{
		delete(Tab[x]);
	}
	delete(Tab);
}

bool Map2D::ReadFromFile(std::string Filename)
{
	x = 0;
	std::string Buffor="";
	std::string Temp;
	std::ifstream savefile;
	savefile.open(Filename);
	//perror("Entityopen");
	if (savefile.is_open())
	{
		while (!(savefile.eof()))
		{
			std::getline(savefile, Temp);
			Buffor += Temp;
			x++;
		}
		y = (Buffor.length() / x)+1;
		x--;
		//std::cout << "Y=" << y << std::endl;
		//std::cout << "X=" << x << std::endl;
	}
	else
	{
		perror("file TestEntity was not opened");
	}
	Generuj(Buffor, x, y);
	return true;
}

bool Map2D::Generuj(std::string Dane, int x, int y)
{
	int temp=0;
	Tab = new Pole**[x];
	for (int i = 0; i < x; i++)
	{
		Tab[i] = new Pole*[y];
		for (int j = 0; j < y; j++)
		{
			//Ogromny switch który wybiera odpowiedni obiekt dla każdego znaku
			switch (Dane[temp])
			{
			case '#':
				Tab[i][j] = new Wall(i,j);
				break;
			case 'C':
				Tab[i][j] = new Box(i, j);
				break;
			case ',':
				Tab[i][j] = new OpenSpace(i,j);
				break;
			case '@':
				Tab[i][j] = new Gracz(i, j);
				PlayerPosition.MoveTo(i, j);
				break;
			case 'z':
				Tab[i][j] = new Melee(i, j);
				Lista.emplace_front(Tab[i][j]);
				break;
			default:
				return false;
					break;
			}
			temp++;
		}
	}
	return true;
}

Pole *** Map2D::GetTab()
{
	return Tab;
}

int Map2D::Getx()
{
	return x;
}

int Map2D::Gety()
{
	return y;
}

Position Map2D::GetPlayerPosition()
{
	return PlayerPosition;
}

void Map2D::ListaTest()
{
	for (it = Lista.begin(); it != Lista.end(); it++)
	{
			(*it)->Tick(x, y, Tab);
	}
}


void Map2D::Turn()
{
	Lista.clear();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (Tab[i][j]->GetType() == 'z')
			{
				if (Tab[i][j]->GetVisible() == 1)
				{
					Lista.push_back(Tab[i][j]);
				}
			}
		}
	}
	ListaTest();
}

void Map2D::UpdatePlayerPosition(Position PPos)
{
	PlayerPosition = PPos;
}

void Map2D::ClearVision()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Tab[i][j]->ChangeVision(false);
		}
	}
}

void Map2D::Display()
{
	MapVision(20);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Tab[i][j]->Display();
		}
		std::cout << std::endl;
	}
}

void Map2D::MapVision(float Range)
{
	float x, y;
	int i;
	ClearVision();
	for (i = 0; i<360; i++)
	{
		x = cos((float)i*0.01745f);
		y = sin((float)i*0.01745f);
		Ray(x, y,Range);
	};
}

void Map2D::Ray(float ix, float iy, float Range)
{
	int i;
	float ox, oy;
	ox = (float)PlayerPosition.x + 0.5f;
	oy = (float)PlayerPosition.y + 0.5f;
	for (i = 0; i<Range; i++)
	{
		if ((ox > 0) && (oy > 0) && (ox < x) && (oy < y))
		{
			Tab[(int)ox][(int)oy]->ChangeVision(true);
			if (Tab[(int)ox][(int)oy]->GetVisionBlock())
				return;
			ox += ix;
			oy += iy;
		}
	};
}