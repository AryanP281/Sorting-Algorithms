#pragma once
#include <algorithm>
#include<iterator>
#include <exception>

//************************Helper Functions*************************
template<typename T>
void Swap(T* x, T* y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

template<typename T>
void Replace(T* arr, int arrLen, int destIndex, int sourceIndex)
{
	if (destIndex >= arrLen || sourceIndex >= arrLen)
		throw std::exception("Index greater than array length");
	if (destIndex > sourceIndex)
		throw std::exception("Source Index cannot be greater than destination index");

	T replaced = arr[destIndex];
	arr[destIndex] = arr[sourceIndex];
	for (int a = destIndex + 1; a <= sourceIndex; ++a)
	{
		Swap(&replaced, &arr[a]);
	}
}

//***********************Sorting Algorithms*************************

template<typename T> void BubbleSort(T* arr, int len)
{

	if (len <= 1)
		return;

	for (int a = 0; a < len - 1; ++a)
	{
		bool swapped = false;
		for(int b = 0; b < len - a - 1; ++b)
		{
			if (arr[b] > arr[b + 1])
			{
				Swap<T>(&arr[b], &arr[b + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}


template<typename T> 
void SelectionSort(T* arr, int arrLen)
{
 	if (arrLen <= 1)
		return;


	for (int a = 0; a < arrLen - 1; ++a)
	{
		T min_val = *std::min_element(arr + a, arr + arrLen);
		int min_index = std::distance(arr, std::find(arr + a, arr + arrLen, min_val));
		Swap<T>(&arr[a], &arr[min_index]);
	}
}

template<typename T>
void InsertionSort(T* arr, int arrLen)
{
	if (arrLen <= 1)
		return;

	for (int a = 1; a < arrLen; ++a)
	{
		if (arr[a] < arr[a - 1])
		{
			for (int b = 0; b < a; ++b)
			{
				if (arr[a] < arr[b])
				{
					Replace(arr, arrLen, b, a);
					break;
				}
			}
		}
	}
}