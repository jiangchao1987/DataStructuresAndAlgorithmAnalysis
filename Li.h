//#pragma once	//ע������#pragma once���ô���ɾ��#pragma once����� error C2011: ��Li��:��class�������ض��� ���󣬵�Ȼ���������Ҫ��ifndef����ˣ��տ�ʼ��������Ϊ��Ȼ���˼�ifndef����ˣ�����

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
