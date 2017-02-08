#include "CaveMapGen.h"



void CaveMapGen::MakeNewMap()
{
	Map = new char*[x];
	Map2 = new char*[x];
	for (int i = 0; i < x; i++)
	{
		Map[i] = new char[y];
		Map2[i] = new char[y];
	}
}

void CaveMapGen::MakeNoise()
{
	srand(time(NULL));
	int RNG;
	for (int i = 0; i < x; i++)
	{
		for(int j=0 ; j<y ; j++)
		{
			if ((i == 0) || (i == x - 1) || (j == 0) || (j == y - 1))
			{
				Map[i][j] = '#';
				Map2[i][j] = '#';
			}
			else
			{
				RNG = rand() % 100;
				if (RNG < 45)
				{
					Map[i][j] = '#';
				}
				else
				{
					Map[i][j] = ',';
				}
			}
		}
	}
}

void CaveMapGen::SmoothTheWalls()
{
	bool m=false;
	for (int i = 0; i < 8; i++)
	{
		m = !m;
		for (int j = 1; j < x - 1; j++)
		{
			for (int k = 1; k < y - 1; k++)
			{
				if (m)
				{
					if (Adcjecent(j, k, m) >= 5)
					{
						Map2[j][k] = '#';
					}
					else
					{
						Map2[j][k] = ',';
					}
				}
				else
				{
					if (Adcjecent(j, k, m) >= 5)
					{
						Map[j][k] = '#';
					}
					else
					{
						Map[j][k] = ',';
					}
				}
			}
		}
	}
}

bool CaveMapGen::PlaceMonsters()
{
	bool test=false;
	int px;
	int py;
	while (!test)
	{
		px=rand() % x;
		py = rand() % y;
		if (Map[px][py] == ',')
		{
			Map[px][py] = '@';
			test = true;
		}
	}
	AddXofY('C', 10);
	AddXofY('z', 10);
	return false;
}

int CaveMapGen::Adcjecent(int cx, int cy, bool m)
{
	int sum=0;
	for (int i = cx - 1; i < cx + 2; i++)
	{
		for (int j = cy - 1; j < cy + 2; j++)
		{
			if (m)
			{
				if (Map[i][j] == '#')
				{
					sum++;
				}
			}
			else
			{
				if (Map2[i][j] == '#')
				{
					sum++;
				}
			}
		}
	}
	return sum;
}

void CaveMapGen::Pisz()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout<<Map[i][j];
		}
		std::cout << std::endl;
	}
}

void CaveMapGen::AddXofY(char sign, int Number)
{
	for (int i = 0; i <= Number; i++)
	{
		int px = rand() % x;
		int py = rand() % y;
		if (Map[px][py] == ',')
		{
			Map[px][py] = sign;
		}
	}
}

void CaveMapGen::SaveToFile(std::string Nazwa)
{
	std::ofstream File;
	File.open(Nazwa);
	if (File.is_open());
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			File << Map[i][j];
		}
		File << '\n';
	}
	File.close();
}

void CaveMapGen::CreateBorder()
{
	for (int i = 0; i < x; i++)
	{
		Map[i][0];
		Map[i][y];
	}
	for (int i = 0; i < y; i++)
	{
		Map[0][i];
		Map[x][i];
	}
}

CaveMapGen::CaveMapGen()
{
}

CaveMapGen::CaveMapGen(int ix, int iy, std::string NazwaPliku)
{
	x = ix;
	y = iy;
	MakeNewMap();
	MakeNoise();
	Pisz();
	std::cout << std::endl;
	SmoothTheWalls();
	Pisz();
	std::cout << std::endl;
	PlaceMonsters();
	CreateBorder();
	Pisz();
	SaveToFile(NazwaPliku);
}


CaveMapGen::~CaveMapGen()
{

	for (int i = 0; i < x; i++)
	{
		delete(Map[i]);
		delete(Map2[i]);
	}
	delete(Map);
	delete(Map2);
}
