#include <iostream>
#include "SortHelper.h"
 using namespace std;
 
 template <typename T>
int  __partition(T arr[],int l,int r){
	 	T v=arr[l];
 	int i=l+1;int j=r;
 	//arr[l+1,i)<=v,arr(j,r]>=v
 	while (true){
 		while(i<=r&&arr[i]<v) i++;
 		while (j>=l+1&&arr[j]>v) j--;
 		if (i>=j) break;
 		swap(arr[i],arr[j]);
i++;j--;
 	 	}
 	 	swap(arr[l],arr[j]);
 	 	return j;
 }
 
 template<typename T>
 void __quickSort(T arr[],int l,int r){
if(l>=r) return;
 	int p=__partition(arr,l,r);
 	__quickSort(arr,l,p-1);
 	__quickSort(arr,p+1,r);
 }
 
 
 template <typename T>
  void quickSort(T arr[],int n){
 __quickSort(arr,0,n-1);
  
   
     }
  
  
  int main(){
  	int n=1000;
  	int *arr=SortTestHelper::generateRandomArray(n,0,n);
     quickSort(arr,n);
  	SortTestHelper::printArray(arr,n);
  	SortTestHelper::testSort("Quick Sort",quickSort,arr,n);
  	delete[] arr;
  	return 0;
  }