#include "Position.h"



Position::Position()
{
}

Position::Position(int xi, int yi)
{
	x = xi;
	y = yi;
}


Position::~Position()
{
}

int Position::Distance(Position P2)
{
	return round(sqrt(pow(x-P2.x,2)+ pow(y - P2.y, 2)));  //Pitagoras
}

void Position::Move(int ix, int iy)
{
	x += ix;
	y += iy;
}

void Position::MoveTo(int ix, int iy)
{
	x = ix;
	y = iy;
}

Position Position::operator+(const Position & p)
{
	return Position(x+p.x,y+p.y);
}

Position Position::operator-(const Position &p)
{
	return Position(x-p.x,y-p.y);
}

Position Position::operator!()
{
	return Position(-x,-y);
}

std::ostream& operator<<(std::ostream& os, Position& p)
{
	os << "X=" << p.x << " Y=" << p.y << std::endl;
	return os;
}
