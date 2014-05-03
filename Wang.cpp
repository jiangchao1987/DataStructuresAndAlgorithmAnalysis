#include "Wang.h"


Wang::Wang(Li* l) : li(l)
{
}

Wang::~Wang(void)
{
}

void Wang::ask()
{
	li->executeMsg(this, "1+1=?");
}

void Wang::solve(const char* answer)
{
	std::cout << "answer is: " << answer << std::endl;
}
