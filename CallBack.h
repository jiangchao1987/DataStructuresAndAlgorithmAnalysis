#pragma once
#ifndef CALLBACK_H_
#define CALLBACK_H_

class CallBack
{
public:
	CallBack(void);
	~CallBack(void);
	virtual void solve(const char* c) = 0;
};

#endif