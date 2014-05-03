#include <iostream>
#include "Li.h"
#include "Wang.h"

int main()
{
	Li* li = new Li();
	Wang* wang = new Wang(li);

	wang->ask();

	system("pause");
	return 0;
}