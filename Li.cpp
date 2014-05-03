#include "Li.h"

Li::Li(void)
{
}

Li::~Li(void)
{
}

void Li::executeMsg(CallBack* cb, const char* question)
{
	std::cout << "question is: " << question << std::endl;
	question = "2";
	cb->solve(question);
}
