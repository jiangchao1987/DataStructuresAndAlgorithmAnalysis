// �����麯��/���麯��,�����������Ȩ��
#include<iostream>
#include<cstdlib>

using namespace std;

class A{
public:
	virtual void output1() = 0;
	virtual void output2(){cout<<"this is A"<<endl;}
};

class B:public A{
private:
	void output1(){cout<<"this is success!"<<endl;}
protected:
	void output2(){cout<<"this is B"<<endl;}
};

void main()
{
	A* a;
	B b;
	a = &b;

	a->output1();
	a->output2(); //ͨ�� a ���Ƿ��ʵ��� B ���� b ��˽�г�Ա�����ͱ�����Ա���� output1,output2
	//b.output1(); 
	//b.output2();//������������Ȩ��ȥ������ B ���� b ��˽�г�Ա�����ͱ�����Ա���� output1,output2

	system("pause");
}