/*****************************************************************************
 *                                    select_sort.cpp
 *
 * 选择排序，其中使用了函数模板以及有些注意点.
 *
 * JiangChao, 2012-12-21
 *****************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>

#define length(array) sizeof(array) / sizeof(array[0])

using std::swap;
using std::cout;

struct Date
{
	int y, m, d;
};

std::ostream& operator<<(std::ostream& o, const Date& d)
{
	return o << d.y << '-' << d.m << '-' << d.d;
}

bool operator<(const Date& a, const Date& b)
{
	return a.y < b.y  || a.y == b.y && (a.m < b.m || a.m == b.m && a.d < b.d);
}

template < typename T >
void sort(T* a, int n)
{
	//反复n-1次
	for(int i=0; i<n-1; i++){
		//	第i次从第i～n个数据中找到最小元素是谁
		int min = i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[min])
				min = j;
		//	把它跟第i个元素交换
		swap(a[min],a[i]);
	}
}

template <>
void sort(const char* a[], int n)
{
	//反复n-1次
	for(int i=0; i<n-1; i++){
		//	第i次从第i～n个数据中找到最小元素是谁
		int min = i;
		for(int j=i+1; j<n; j++)
			
			if(strcmp(a[j], a[min]) < 0)
				min = j;
		//	把它跟第i个元素交换
		swap(a[min],a[i]);
	}
}

template < typename T >
void show(T* a, int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << ' ';
	cout << std::endl;
}

// 特化
template < typename T >
void show(T d)
{
	cout << d << std::endl;
}

//template < typename T >
//void show(T& a)	// 注意：这里必须使用T&，不能使用T或者T*，后两个传的都是地址
//{
//	for (int i = 0; i < length(a); i++)
//		cout << a[i] << ' ';
//	cout << std::endl;
//}

template < typename T, int N >
void show(T(&a)[N])	//数组引用
{
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';
	cout << std::endl;
}

int main()
{
	int a[6] = {20, 8, 12, 98, 66, 10};
	Date d[4] = {{2014,8,30},{1998,10,20},{2012,12,21},{2012,12,20}};
	const char* s[3] = {"jiangchao", "kuanglina", "haha"};

	sort(a, length(a));
	sort(d, length(d));
	sort(s, length(s));
	/*for(auto x : d)
	{
		cout << x << ' ';
	}*/
	show(a, length(a));
	show(d);
	show(1237.2837);
	show(s);

	std::cin.get();
	return 0;
}
