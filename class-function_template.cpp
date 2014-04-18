/*****************************************************************************
 *                                    class-function_template.cpp
 *
 * 类模板和函数模板.
 * 普通函数在类型不匹配是编译器会尝试做类型转换, 但模板函数编译器不会做转换.
 *
 * JiangChao, 2013-01-06
 *****************************************************************************/
#include <iostream>
using namespace std;

// 类模板
template <typename T, typename U>
struct Pair
{
	T first;
	U second;
	Pair() : first(), second() {}
	Pair(const T& a, const U& b) : first(a), second(b) {}
	template<typename X, typename Y>
	Pair& operator=(const Pair<X, Y>& p)
	{
		first = convertto<T>(p.first);
		second = convertto<U>(p.second);
		return *this;
	}
};

template <typename To, typename From>
To convertto(From v)
{ 
	return To(v); 
}
template <typename To>
To convertto(const char* str)
{
	return To(atof(str));
}

// 函数模板（重载函数）
template <typename T, typename U>
ostream& operator<<(ostream& o, const Pair<T, U>& p)
{
	return o << p.first << ':' << p.second;
}

// 函数模板（普通函数）
template <typename T, typename U>
//Pair<T, U> mp(const T& f, const U& s)	//错误	1	error C2536: “Pair<T,U>::Pair<T,U>::first”: 无法指定数组的显式初始值设定项，用了引用竟然被当成数组了 char[5]这么个数组
Pair<T, U> mp(T f, U s)
{
	/*Pair<T, U> obj(f, s);
	return obj;*/
	return Pair<T, U> (f, s);	//匿名对象
}

int main()
{
	cout << Pair<const char*, int>("kevin", 28) << endl;
	cout << Pair<int, double>(20, 6789.5) << endl;
	cout << mp("kevin", 28) << endl;
	cout << mp(20, 6789.5) << endl;
	Pair<int, double> a(20, 23782.2);
	cout << "a=" << a << endl;
	Pair<const char*, const char*> b("78", "90.2");
	a = b;
	cout << "a=" << a << endl;

	cin.get();
	return 0;
}