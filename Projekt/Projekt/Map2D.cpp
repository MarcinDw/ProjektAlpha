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
		std::cout << "Y=" << y << std::endl;
		std::cout << "X=" << x << std::endl;
	}
	else
	{
		perror("file TestEntity was not opened");
	}
	return true;
}