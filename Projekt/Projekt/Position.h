#pragma once
#include <math.h>
#include <iostream>
class Position
{
public:
	int x;
	int y;
	Position();
	Position(int xi, int yi);
	~Position();
	int Distance(Position P2);
	friend std::ostream& operator<<(std::ostream&, Position&);
	Position operator+(const Position&);
	Position operator-(const Position&);
	Position operator!();
};

