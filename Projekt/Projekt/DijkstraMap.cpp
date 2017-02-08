#include "DijkstraMap.h"



DijkstraMap::DijkstraMap()
{
}

DijkstraMap::DijkstraMap(int imaxx, int imaxy)
{
	maxx = imaxx;
	maxy = imaxy;
	Map = new int*[maxx];
	for (int i = 0; i < maxx; i++)
	{
		Map[i] = new int[maxy];
		for (int j = 0; j < maxy; j++)
		{
			Map[i][j] = 2000;
		}
	}
}

DijkstraMap::~DijkstraMap()
{
}

void DijkstraMap::Generate(Pole *** Mapa)
{
	int iterations=20;
	int size = maxx*maxy-AsignedValues;
	while (size > 0 && iterations!=0)
	{
		iterations--;
		//Pisz();
		for (int y = 0; y < maxy; y++)
		{
			for (int x = 0; x < maxx; x++)
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
						else
						{
							if (n == 2001)
							{
								Map[x][y] = n;
								size--;
							}
						}
					}
				}
			}
		}
	}
	AsignedValues = 0;
}

void DijkstraMap::AssignStart()
{
	if (Map != NULL)
	{
		for (int i = 0; i < maxx; i++)
		{
			for (int j = 0; j < maxy; j++)
			{
				Map[i][j] = 2000;
			}
		}
	}
	else
	{
		Map = new int*[maxy];
		for (int i = 0; i < maxy; i++)
		{
			Map[i] = new int[maxx];
			for (int j = 0; j < maxx; j++)
			{
				Map[i][j] = 2000;
			}
		}
	}
}


void DijkstraMap::AssignPriority(char znak, int wartosc, Pole *** Mapa)
{
	for (int x = 0; x < maxx; x++)
	{
		for (int y = 0; y < maxy; y++)
		{
			if (Mapa[x][y]->GetType() == znak)
			{
				Map[x][y] = wartosc;
				AsignedValues++;
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

Position DijkstraMap::Min(Position Pos)
{
		int min = 2003;
		//Pisz();
		bool first, second;
		first = (Pos.y-1 > 0);
		second = (Pos.y+1 < maxy);
		Position Odp(0,0);
		if (second)
		{
			if (Map[Pos.x][Pos.y + 1] < min)
			{
				min = Map[Pos.x][Pos.y + 1];
				Odp.MoveTo(Pos.x, Pos.y + 1);
			}
		}
		if (first)
		{
			if (Map[Pos.x][Pos.y - 1] < min)
			{
				min = Map[Pos.x][Pos.y - 1];
				Odp.MoveTo(Pos.x, Pos.y - 1);
			}
		}
		if (Pos.x + 1 < maxx)
		{
			if (Map[Pos.x + 1][Pos.y] < min)
			{
				min = Map[Pos.x + 1][Pos.y];
				Odp.MoveTo(Pos.x + 1, Pos.y);
			}
			if (second)
			{
				if (Map[Pos.x + 1][Pos.y + 1] < min)
				{
					min = Map[Pos.x + 1][Pos.y + 1];
					Odp.MoveTo(Pos.x + 1, Pos.y + 1);
				}
			}
			if (first)
			{
				if (Map[Pos.x + 1][Pos.y - 1] < min)
				{
					min = Map[Pos.x + 1][Pos.y - 1];
					Odp.MoveTo(Pos.x + 1, Pos.y - 1);  //Finish first and second!!!
				}
			}

		}
		if (Pos.x - 1 >= 0)
		{
			if (Map[Pos.x - 1][Pos.y] < min)
			{
				min = Map[Pos.x - 1][Pos.y];
				Odp.MoveTo(Pos.x - 1, Pos.y);
			}
			if (second)
			{
				if (Map[Pos.x - 1][Pos.y + 1] < min)
				{
					min = Map[Pos.x - 1][Pos.y + 1];
					Odp.MoveTo(Pos.x - 1, Pos.y + 1);
				}
			}
			if (first)
			{
				if (Map[Pos.x - 1][Pos.y - 1] < min)
				{
					min = Map[Pos.x - 1][Pos.y - 1];
					Odp.MoveTo(Pos.x - 1, Pos.y - 1);
				}
			}
		}
		return Odp;
}

void DijkstraMap::Pisz()
{
	for (int x = 0; x < maxx; x++)
	{
		for (int y = 0; y < maxy; y++)
		{
			std::cout <<std::setw(5)<< Map[x][y];
		}
		std::cout << std::endl;
	}
}
