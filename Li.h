//#pragma once	//注意这里#pragma once的用处，删除#pragma once会出现 error C2011: “Li”:“class”类型重定义 错误，当然不用这个就要用ifndef这个了，刚开始出错是因为竟然忘了加ifndef这个了！！！

#ifndef LI_H_
#define LI_H_

#include <iostream>
#include "CallBack.h"

class Li
{
public:
	Li(void);
	~Li(void);
	void executeMsg(CallBack* cb, const char* question);
};

#endif
