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
	y = 0;
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
			y++;
		}
		x = Buffor.length() / y;
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
	Tab = new Pole**[y];
	for (int i = 0; i < y; i++)
	{
		Tab[i] = new Pole*[x];
		for (int j = 0; j < x; j++)
		{
			//Ogromny switch który wybiera odpowiedni obiekt dla każdego znaku
			switch (Dane[temp])
			{
			case '#':
				Tab[i][j] = new Wall(j,i);
				break;
			case ',':
				Tab[i][j] = new OpenSpace(j,i);
				break;
			case '@':
				Tab[i][j] = new Gracz(j, i);
				PlayerPosition.MoveTo(i, j);
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

Position Map2D::GetPlayerPosition()
{
	return PlayerPosition;
}

void Map2D::Turn()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			Tab[i][j]->Tick();
		}
		std::cout << std::endl;
	}
}
