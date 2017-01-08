#include "DijkstraMap.h"



DijkstraMap::DijkstraMap()
{
}

DijkstraMap::DijkstraMap(int imaxx, int imaxy, Position PCPos, Pole *** Mapa)
{
	maxx = imaxx;
	maxy = imaxy;
	Map = new int*[maxy];
	Generate(PCPos, Mapa);
}


DijkstraMap::~DijkstraMap()
{
}

void DijkstraMap::Generate(Position PCPos, Pole *** Mapa)
{
	int size = maxx*maxy-1;
	for (int i = 0; i < maxy; i++)
	{
		Map[i] = new int[maxx];
		for (int j = 0; j < maxx; j++)
		{
			Map[i][j] = 2000;
		}
	}
	Map[PCPos.x][PCPos.y] = 0;
	while (size > 0)
	{
		for (int y = 0; y < maxx; y++)
		{
			for (int x = 0; x < maxy; x++)
			{
				if (Map[x][y] == 2000)
				{
					if (Mapa[x][y]->GetMoveBlock())
					{
						Map[x][y] = 2001;
						size--;
					}
					else
					{
						int n = Nextto(x, y);
						if (n < 2000)
						{
							Map[x][y] = n+1;
							size--;
						}
					}
				}
			}
		}
	}
}

int DijkstraMap::Nextto(int x, int y)
{
	int min=2003;
	if (Map[x + 1][y] < min)
	{
		min = Map[x + 1][y];
	}
	if (Map[x + 1][y+1] < min)
	{
		min = Map[x + 1][y+1];
	}
	if (Map[x + 1][y-1] < min)
	{
		min = Map[x + 1][y-1];
	}
	if (Map[x][y+1] < min)
	{
		min = Map[x][y+1];
	}
	if (Map[x][y-1] < min)
	{
		min = Map[x][y-1];
	}
	if (Map[x - 1][y] < min)
	{
		min = Map[x - 1][y];
	}
	if (Map[x - 1][y+1] < min)
	{
		min = Map[x - 1][y+1];
	}
	if (Map[x - 1][y-1] < min)
	{
		min = Map[x - 1][y-1];
	}
	return min;
}

void DijkstraMap::Pisz()
{
	for (int x = 0; x < maxy; x++)
	{
		for (int y = 0; y < maxx; y++)
		{
			std::cout <<std::setw(5)<< Map[x][y];
		}
		std::cout << std::endl;
	}
}
