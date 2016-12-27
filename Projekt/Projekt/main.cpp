#include "Position.h"
#include<stdio.h>
int main()
{
	Position A(1,10);
	Position B(20, 200);
	std::cout << A;
	std::cout << B;
	std::cout << A+B;
	std::cout << A-B;
	std::cout << !A;
	std::cout << A.Distance(B);

	return 0;
}