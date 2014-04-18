/*****************************************************************************
 *                                    select_sort.cpp
 *
 * ѡ����������ʹ���˺���ģ���Լ���Щע���; �ػ��Ƕ�һ�����е�ģ�����ػ�.
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
	//����n-1��
	for(int i=0; i<n-1; i++){
		//	��i�δӵ�i��n���������ҵ���СԪ����˭
		int min = i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[min])
				min = j;
		//	��������i��Ԫ�ؽ���
		swap(a[min],a[i]);
	}
}

// const char* �ػ���ȫ�ػ���
template <>
void sort(const char* a[], int n)
{
	//����n-1��
	for(int i=0; i<n-1; i++){
		//	��i�δӵ�i��n���������ҵ���СԪ����˭
		int min = i;
		for(int j=i+1; j<n; j++)
			
			if(strcmp(a[j], a[min]) < 0)
				min = j;
		//	��������i��Ԫ�ؽ���
		swap(a[min],a[i]);
	}
}

// ָ���ػ�, �������Ķ���ָ�루ƫ�ػ���
template < typename T >
void sort(T* a[], int n)
{
	//����n-1��
	for(int i=0; i<n-1; i++){
		//	��i�δӵ�i��n���������ҵ���СԪ����˭
		int min = i;
		for(int j=i+1; j<n; j++)
			if(*a[j]<*a[min])	// �Ƚϵ�ַû���壬��ȻҪ�Ƚ�ָ��ָ�����ֵ��
				min = j;
		//	��������i��Ԫ�ؽ���
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

// ����Ԫ���ػ�
template < typename T >
void show(T d)
{
	cout << d << std::endl;
}

//template < typename T >
//void show(T& a)	// ע�⣺�������ʹ��T&������ʹ��T����T*�����������Ķ��ǵ�ַ
//{
//	for (int i = 0; i < length(a); i++)
//		cout << a[i] << ' ';
//	cout << std::endl;
//}

template < typename T, int N >
void show(T(&a)[N])	//��������
{
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';
	cout << std::endl;
}

template < typename T, int N >
void show(T*(&a)[N])	//��������
{
	for (int i = 0; i < N; i++)
		cout << *a[i] << ' ';
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

	int* ap[4] = {new int(5), new int(2), new int(8), new int(7)};
	double* bp[3] = {new double(2.2), new double(1.8), new double(6.6)};
	sort(ap, 4); sort(bp, 3);
	show(ap); show(bp);
	std::cin.get();
	return 0;
}
