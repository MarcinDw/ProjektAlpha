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
	void Move(int ix, int iy);
	void MoveTo(int ix, int iy);
	friend std::ostream& operator<<(std::ostream&, Position&);
	Position operator+(const Position&);
	Position operator-(const Position&);
	Position operator!();
};

