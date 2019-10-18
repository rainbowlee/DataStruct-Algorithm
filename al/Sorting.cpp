#include "Sorting.h"
#include <vector>
using namespace std;
void Sort::BubbleSort( int arr[] , int len)
{
	for( int i = 0; i < len; i++)
	{
		bool exchange = false;
		for(int j = 0; j < len - i - 1; j++)
		{
			if(arr[j+1] < arr[j])
			{
				int value = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = value;
				exchange = true;
			}
		}

		if(exchange == false)
			return;
	}
}

void B2(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		int moved = false;
		for(int j = 0; j < len - i; j++)
		{
			if(arr[j+1] < arr[j])
			{
				int t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				moved = true;
			}
		}

		if(moved == false)
			return;
	}
}

void Sort::InsertSort( int arr[] , int len)
{
	for(int i = 1; i < len; ++i)
	{
		int inserValue = arr[i];
		int j = i - 1;
		for( ; j >=0; --j)
		{
			if(arr[j] > inserValue)
				arr[j+1] = arr[j];
			else
				break;
		}

		arr[j+1] = inserValue;
	}
}

void I2( int arr[] , int len)
{
	for(int i = 1; i < len; i++)
	{
		int j = i - 1;
		int value = arr[i];
		for(; j >=0; --j)
		{
			if(arr[j] > value)
				arr[j+1] = arr[j];
			else
				break;
		}

		arr[j+1] = value;
	}
}

void S2( int arr[] , int len)
{
	for(int  i = 0; i < len; i++)
	{
		int minIndex = i;
		for(int j = i; j < len; j++)
		{
			if(arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}

		int value = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex]= value;
	}
}

void Sort::SelectSort( int arr[] , int len)
{
	for(int i = 0; i < len-1; i++)
	{
		int minValueIndex = i;
		for(int j = i; j < len; j++)
		{
			if(arr[j] < arr[minValueIndex])
			{
				minValueIndex = j;
			}
		}

		if(minValueIndex != i)
		{
			int minvalue = arr[minValueIndex];
			arr[minValueIndex] = arr[i];
			arr[i] = minvalue;
		}
	}

	////ѡ���ȶ��㷨������
	//for(int i = 0; i < len-1; i++)
	//{
	//	int minValueIndex = i;
	//	for(int j = i; j < len; j++)
	//	{
	//		if(arr[j] < arr[minValueIndex])
	//		{
	//			minValueIndex = j;
	//		}
	//	}

	//	int minValue = arr[minValueIndex];
	//	for(int k = minValueIndex; k > i;k--)
	//	{
	//		arr[k] = arr[k-1];
	//	}
	//	arr[i] = minValue;
	//}
}

void MergeSort_M(vector<int>* arr, int from, int mid, int to, vector<int>* temparr)
{
	int doFrom = from;
	int doFrom2 = mid+1;
	int tempFrom = from;
	for(; doFrom <=mid && doFrom2 <=to; )
	{
		if((*arr)[doFrom] <= (*arr)[doFrom2])
		{
			(*temparr)[tempFrom++] = (*arr)[doFrom++];
		}
		else
		{
			(*temparr)[tempFrom++] = (*arr)[doFrom2++];
		}
	}

	for(; doFrom <=mid;)
		(*temparr)[tempFrom++] = (*arr)[doFrom++];

	for(; doFrom2 <=to;)
		(*temparr)[tempFrom++] = (*arr)[doFrom2++];

	int copyFrom = from;
	for(; copyFrom <= to; copyFrom++)
		(*arr)[copyFrom] = (*temparr)[copyFrom];
}

//���
void MergeSort_S(vector<int>* arr, int from, int to, vector<int>* temparr)
{
	if(from>=to)
		return;
	int mid = (to - from)/2 + from;
	MergeSort_S(arr, from, mid, temparr);
	MergeSort_S(arr, mid+1, to, temparr);

	MergeSort_M(arr, from, mid, to, temparr);
}

void Sort::MergeSort( vector<int>& arr )
{
	vector<int> newArray;
	for( size_t i = 0; i < arr.size(); i++)
		newArray.push_back(0);

	//memset(newArr, 9, sizeof(int)*len);
	MergeSort_S(&arr, 0, arr.size()-1, &newArray);
}

void QuickSort_S(vector<int>& arr, int from, int to )
{
	if(from >= to) return;

	int index = Sort::QuickPartition(arr, from, to);
	if(index == to)
	{
		QuickSort_S(arr, from, index-1);
	}
	else if( index == from)
	{
		QuickSort_S(arr,index+1, to);
	}
	else
	{
		QuickSort_S(arr, from, index-1);
		QuickSort_S(arr,index+1, to);
	}

	//index left <=> right

	//left
	//ѡ�������
	for( int i = from; i < index-1; i++)
	{
		int minIndex = i;
		int j = i;
		for(; j < index; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		int value = arr[i];
		arr[i]= arr[minIndex];
		arr[minIndex] = value;
	}


	for( int i = index+1; i < to; i++)
	{
		int minIndex = i;
		int j = i;
		for(; j < to+1; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		int value = arr[i];
		arr[i]= arr[minIndex];
		arr[minIndex] = value;
	}
}

void Sort::QuickSort( vector<int>& arr)
{
	QuickSort_S(arr,0, arr.size()-1);
}

//���������� �����һ��pivotԪ�أ���arr�ֳ������֣�һ����С��pivot,ʣ�´����
//���ȶ�����
int Sort::QuickPartition(vector<int>& arr, int from ,int to)
{
	if(from >= to)
		return 0;

	int value = arr[to];

	int i = from;
	for( int j = from; j < to -1; j++)
	{
		if(arr[j] < value)
		{
			int changeValue = arr[i];
			arr[i] = arr[j];
			arr[j] = changeValue;
			i++;
		}
	}

	arr[to] = arr[i];
	arr[i] = value;
	return i;
}