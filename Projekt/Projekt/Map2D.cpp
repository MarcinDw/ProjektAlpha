#include "Map2D.h"



Map2D::Map2D()
{
	x = 0;
	y = 0;
}


Map2D::~Map2D()
{
}

bool Map2D::ReadFromFile(std::string Filename)
{
	x = 0;
	std::string Buffor="";
	std::string Temp;
	std::ifstream savefile;
	savefile.open(Filename);
	perror("Entityopen");
	if (savefile.is_open())
	{
		while (!(savefile.eof()))
		{
			std::getline(savefile, Temp);
			Buffor += Temp;
			x++;
		}
		y = Buffor.length() / x;
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
		(*it)->Tick(x,y,Tab);
	}
}

void Map2D::Turn()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Tab[i][j]->Tick(x,y,Tab);
		}
	}
}

void Map2D::Display()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Tab[i][j]->Display();
		}
		std::cout << std::endl;
	}
}