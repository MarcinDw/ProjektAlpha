#include "Position.h"
#include<stdio.h>
#include "Map2D.h"
#include "Postac.h"
int main()
{
	Map2D Test;
	Postac P1, P2;
	Test.ReadFromFile("MapTest.txt");
	Test.Turn();
	P1.Attack(P2);
	P1.Attack(P2);

	return 0;
}