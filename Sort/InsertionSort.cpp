#include <iostream>
#include "SortHelper.h"
using namespace std;

template <typename T>
void insertionSort(T arr[], int n)
{

	for (int i = 1; i < n; i++)
	{
		int j;

		T e = arr[i];
		for (j = i; j > 0 && e < arr[j - 1]; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

int main()
{
	int n = 20;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	//  insertionSort(arr,n);
	// 	SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
	SortTestHelper::printArray(arr, n);
	delete[] arr;
}