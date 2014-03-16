#include <iostream>
#include "algorithm.h"

#define length(array) sizeof(array) / sizeof(array[0])
#define format "%d "

using namespace std;

//直接插入排序(straight insertion sort)
void StraightInsertionSort(int array[], int len)
{
	int key, index;  //key:待排序数, index:已排序下标索引值
    for(int i = 1; i < len; i++)
	{  //默认第一个元素(下标从0开始)已经有序
        key = array[i];  //待排序元素
        for(index = i - 1; index >= 0 && array[index] > key; index--)
		{ //待排序数较小
            array[index + 1] = array[index];  //后移
        }
        array[index + 1] = key;  //插入待排序元素

		//cout << "(" << i << ") -> ";
		//Show(array, len);
		//cout << endl;
    }

	Show(array, len);
}

//希尔排序(Shell Sort)
void ShellSort(int array[], int len)
{
	int key, index;
	for(int step = len/2; step > 0; step /= 2)
	{
		for (int i = step; i < len; i++)
		{
			key = array[i];
			for (index = i - step; index >= 0 && array[index] > key; index -= step)
			{
				array[index + step] = array[index];
			}
			array[index + step] = key;			
		}
	}

	Show(array, len);
}

//直接选择排序(Straight Select Sort)
void StraightSelectSort(int array[], int len)
{
	int index, min, tmp;
	for (int i = 0; i < len - 1; i++)// N - 1 趟
	{
		min = i;
		 //查找选择最小元素值的下标索引值
		for (index = i + 1; index < len; index++)
		{
			if (array[min] > array[index])
				min = index;
		}
		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
		}
	}

	Show(array, len);
}

//冒泡排序(Bubble Sort)
void BubbleSort(int* array, int len)
{
	bool isOk = false;        //设置排序是否结束的哨兵
    for (int i = 0; i < len - 1 && !isOk; ++i)		//i从[0,len-1)开始冒泡，确定第i个元素
    {
        isOk = true;        //假定排序成功
        for (int index = len- 1; index > i; --index)		//从[len - 1, i）检查是否比上面一个小，把小的冒泡浮上去
        {
            if (array[index] < array[index - 1])    //如果下面的比上面小，交换
            {
                int tmp = array[index];
                array[index] = array[index - 1];
                array[index - 1] = tmp;
                isOk = false;
            }
        }
    }

	Show(array, len);
}

//快速排序(QuickSort) 步骤1
//int AdjustArray(int* array, int left, int right)
//{
//	int i = left, j = right;
//	int base = array[i];	//基准, 亦即第一个坑
//	while (i < j)	
//	{
//		// 从右向左找小于base的数array[j]来填array[i], 之后i++
//		while (i < j && array[j] >= base)
//			j--;
//		if (i < j)
//		{
//			array[i] = array[j];
//			i++;
//		}
//		// 从左向右找大于或等于base的数array[i]来填array[j], 之后j--
//		while (i < j && array[i] < base)
//			i++;
//		if (i < j)
//		{
//			array[j] = array[i];
//			j--;
//		}
//	}
//	//退出时，i等于j。将base填到这个坑中。
//    array[i] = base;
//
//	return i;	//返回调整后基准数的位置
//}
//快速排序(QuickSort) 步骤2
//void QuickSort(int* array, int left, int right)
//{
//	if (left < right)
//	{
//		int i = AdjustArray(array, left, right);
//		QuickSort(array, left, i - 1);
//		QuickSort(array, i + 1, right);
//	}
//}

void QuickSort(int* array, int left, int right)
{
	if (left < right)
	{
		int i = left, j = right;
		int base = array[i];	//基准, 亦即第一个坑
		while (i < j)	
		{
			// 从右向左找小于base的数array[j]来填array[i], 之后i++
			while (i < j && array[j] >= base)
				j--;
			if (i < j)
				array[i++] = array[j];
			// 从左向右找大于或等于base的数array[i]来填array[j], 之后j--
			while (i < j && array[i] < base)
				i++;
			if (i < j)
				array[j--] = array[i];
		}
		//退出时，i等于j。将base填到这个坑中。
		array[i] = base;
		QuickSort(array, left, i - 1);
		QuickSort(array, i + 1, right);
	}
	Show(array, right);
	cout << endl;
}

int main()
{
	int array[] = { 49, 38, 65, 44, 81, 97, 76, 13, 27, 52, 30 };

	//StraightInsertionSort(array, length(array));
	//ShellSort(array, length(array));
	//StraightSelectSort(array, length(array));
	//BubbleSort(array, length(array));
	QuickSort(array, 0, length(array));	//TODO: 排序后最大值溢出?

	cin.get();
	return 0;
}

void Show(int array[], int len)
{
	for (int i = 0; i < len; i++){
		printf(format, array[i]);
	}
}