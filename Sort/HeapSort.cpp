#include <iostream>
#include "SortHelper.h"
 using namespace std;

 //serve for heapSort(); 
 template <typename T>
 void __shiftDown(T arr[],int n,int k){
 	 		while(2*k+1<=n){
 	  			int j=2*k+1;
 	  			if (j+1<n&&arr[j+1]>arr[j])   j=j+1;
 	  			if (arr[k]>=arr[j]) break;
 	  			swap(arr[k],arr[j]);
 	  			k=j;
 	  			}
 	}
 template <typename T>
 void heapSort(T arr[],int n){
 	//heapfiy
 	for(int i=(n-1)/2;i>=0;i--)
 	       __shiftDown(arr,n,i);
 	for(int i=n-1;i>0;i--)
 	swap(arr[0],arr[i]),__shiftDown(arr,i,0);
 	}
 /*template <typename Item>
 class MaxHeap{
 	private:
 	     Item  *data;
 	     int count;
 	  void   shiftUp(int k){
 	  
 	  	while(k>1){
 	  		int	p=k/2;
 	  		if(data[k]>data[p]) swap(data[k],data[p]),k=p;
 	  		else break 		;
 	  		}
 	  	
 	  	}
 	  	
 	  	
 	  	void shiftDown(int k){
 	  		while(2*k<=count){
 	  			int j=2*k;
 	  			if (j+1<=count&&data[j+1]>data[j])   j=j+1;
 	  			if (data[k]>=data[j]) break;
 	  			swap(data[k],data[j]);
 	  			k=j;
 	  			}
 	  		}
 	public:
 	     MaxHeap(){
 	     	data=new Item[101];
 	     	count=0;
 	     	}
 	     	
 	     	~MaxHeap(){
 	     	delete[] data;
 	     	}
 	     int size(){
 	     	return count;}
     	bool isEmpty(){
 	     	return count==0;
 	     	}
 void insert(Item item){
 	assert(count+1<=100);
 	data[count+1]=item;
 	count++;
 	shiftUp(count);
 	}
 	Item extractMax(){
 	assert(count>=1);
 	Item ret=data[1];
 	data[1]=data[count];
 	count--;
 	shiftDown(1);
 	return ret;
 		
 		}
 	
 		   void testPrint(){
 		   	for (int i=1;i<=count;i++)
 		   	   cout<<data[i]<<"   ";
 		   	}	   
 	};
 */
 
 
  
  int main(){
  	int n=1000;
  	int *arr=SortTestHelper::generateRandomArray(n,0,n);
 heapSort(arr,n);
  	SortTestHelper::printArray(arr,n);
  	SortTestHelper::testSort("Heap Sort",heapSort,arr,n);
  	delete[] arr;
/*  MaxHeap <int> maxheap=MaxHeap<int>();
  	 	srand(time(NULL));
  	 	for (int i=0;i<15;i++)
  	 	maxheap.insert(rand()%100);
  	 	maxheap.testPrint();cout<<endl;
  	 	while (!maxheap.isEmpty()) 
  	 	cout<<maxheap.extractMax()<<"   ";*/
  	 	return 0;
  }