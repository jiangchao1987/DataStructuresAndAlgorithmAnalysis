#include <iostream>
#include "algorithm.h"

#define length(array) sizeof(array) / sizeof(array[0])
#define format "%d "

using namespace std;

//ֱ�Ӳ�������(straight insertion sort)
void StraightInsertionSort(int array[], int len)
{
	int key, index;  //key:��������, index:�������±�����ֵ
    for(int i = 1; i < len; i++)
	{  //Ĭ�ϵ�һ��Ԫ��(�±��0��ʼ)�Ѿ�����
        key = array[i];  //������Ԫ��
        for(index = i - 1; index >= 0 && array[index] > key; index--)
		{ //����������С
            array[index + 1] = array[index];  //����
        }
        array[index + 1] = key;  //���������Ԫ��

		//cout << "(" << i << ") -> ";
		//Show(array, len);
		//cout << endl;
    }

	Show(array, len);
}

//ϣ������(Shell Sort)
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

//ֱ��ѡ������(Straight Select Sort)
void StraightSelectSort(int array[], int len)
{
	int index, min, tmp;
	for (int i = 0; i < len - 1; i++)// N - 1 ��
	{
		min = i;
		 //����ѡ����СԪ��ֵ���±�����ֵ
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

//ð������(Bubble Sort)
void BubbleSort(int* array, int len)
{
	bool isOk = false;        //���������Ƿ�������ڱ�
    for (int i = 0; i < len - 1 && !isOk; ++i)		//i��[0,len-1)��ʼð�ݣ�ȷ����i��Ԫ��
    {
        isOk = true;        //�ٶ�����ɹ�
        for (int index = len- 1; index > i; --index)		//��[len - 1, i������Ƿ������һ��С����С��ð�ݸ���ȥ
        {
            if (array[index] < array[index - 1])    //�������ı�����С������
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

//��������(QuickSort) ����1
//int AdjustArray(int* array, int left, int right)
//{
//	int i = left, j = right;
//	int base = array[i];	//��׼, �༴��һ����
//	while (i < j)	
//	{
//		// ����������С��base����array[j]����array[i], ֮��i++
//		while (i < j && array[j] >= base)
//			j--;
//		if (i < j)
//		{
//			array[i] = array[j];
//			i++;
//		}
//		// ���������Ҵ��ڻ����base����array[i]����array[j], ֮��j--
//		while (i < j && array[i] < base)
//			i++;
//		if (i < j)
//		{
//			array[j] = array[i];
//			j--;
//		}
//	}
//	//�˳�ʱ��i����j����base�������С�
//    array[i] = base;
//
//	return i;	//���ص������׼����λ��
//}
//��������(QuickSort) ����2
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
		int base = array[i];	//��׼, �༴��һ����
		while (i < j)	
		{
			// ����������С��base����array[j]����array[i], ֮��i++
			while (i < j && array[j] >= base)
				j--;
			if (i < j)
				array[i++] = array[j];
			// ���������Ҵ��ڻ����base����array[i]����array[j], ֮��j--
			while (i < j && array[i] < base)
				i++;
			if (i < j)
				array[j--] = array[i];
		}
		//�˳�ʱ��i����j����base�������С�
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
	QuickSort(array, 0, length(array));	//TODO: ��������ֵ���?

	cin.get();
	return 0;
}

void Show(int array[], int len)
{
	for (int i = 0; i < len; i++){
		printf(format, array[i]);
	}
}