//#pragma once

#ifndef WANG_H_
#define WANG_H_

#include <iostream>
#include "CallBack.h"
#include "Li.h"

class Wang :
	public CallBack
{
private:
	Li* li;
public:
	Wang();
	Wang(Li* l);
	~Wang(void);
	void ask();
	void solve(const char* answer);
};

#endif