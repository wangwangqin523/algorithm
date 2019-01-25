#include  <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;
namespace SortTestHelper{
//生成随机数组[rangL,rangR]
int * generateRandomArray(const int n,int rangL,int rangR){
   assert(rangL<=rangR);
  
 int * arr =new int[n];
	srand(time(NULL));
	for (int i=0;i<n;i++)
	arr[i]=rand() % (rangR-rangL+1)+rangL;
	return arr;
}

template <typename T>
void printArray(T arr[],int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<"  ";
	cout<<endl;
	return;
}

template<typename T>
void testSort(const string &sortName,void (*sort)(T[],int),T arr[],int n){
	clock_t startTime=clock();
	sort(arr,n);
	clock_t endTime=clock();	cout<<sortName<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"S"<<endl;
	return;
}
	
};