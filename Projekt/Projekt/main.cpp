#include "Position.h"
#include<stdio.h>
#include "Map2D.h"
int main()
{
	Map2D Test;
	Test.ReadFromFile("MapTest.txt");
	Test.Turn();
	return 0;
}