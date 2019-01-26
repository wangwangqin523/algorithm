#include <iostream>
#include "SortHelper.h"
using namespace std;

//将Arr[l,mid]和Arr[mid+1,r]进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
   T aux[r - l + 1];
   for (int i = l; i <= r; i++)
      aux[i - l] = arr[i];

   int i = l;
   int j = mid + 1;
   for (int k = l; k <= r; k++)
   {
      if (i > mid)
         arr[k] = aux[j - l], j++;
      else if (j > r)
         arr[k] = aux[i - l], i++;

      else if (aux[i - l] < aux[j - l])
         arr[k] = aux[i - l], i++;
      else
         arr[k] = aux[j - l], j++;
   }
}

//递归使用归并排序，范围[l,r]
template <typename T>
void __mergeSort(T arr[], int l, int r)
{
   if (l >= r)
      return;
   int mid = (l + r) / 2;
   __mergeSort(arr, l, mid);
   __mergeSort(arr, mid + 1, r);
   __merge(arr, l, mid, r);
}
template <typename T>
void mergeSort(T arr[], int n)
{
   __mergeSort(arr, 0, n - 1);
}

int main()
{
   int n = 1000;
   int *arr = SortTestHelper::generateRandomArray(n, 0, n);
   mergeSort(arr, n);
   SortTestHelper::printArray(arr, n);
   SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
   delete[] arr;
}