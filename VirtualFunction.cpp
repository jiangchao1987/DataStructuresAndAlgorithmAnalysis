// 利用虚函数/纯虚函数,打破子类访问权限
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
	a->output2(); //通过 a 我们访问到了 B 变量 b 的私有成员函数和保护成员函数 output1,output2
	//b.output1(); 
	//b.output2();//这里我们是无权限去访问类 B 变量 b 的私有成员函数和保护成员函数 output1,output2

	system("pause");
}