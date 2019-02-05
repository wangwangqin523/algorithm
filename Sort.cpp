#include <iostream>  
#include <vector>  
//#include <algorithm>  

using namespace std;  
//¿ìÅÅÄ£°å 
void quickSort(int a[],int l,int r){
	if (l>r)return;
	int m=(l+r)/2;
	int i=l-1;
	int j=r+1;
	while(1){
	while(a[++i]<a[m]);
	while(a[--j]>a[m]);
	if(i>=j)break;
	  swap(a[i],a[j]);
	  }
	 
quickSort(a,l,i-1);
quickSort(a,j+1,r);
 
}
//¹é²¢ÅÅÐòÄ£°å 
void mergeSort(int a[],int l,int r){
	if(l>=r) return;
	int m=(l+r)/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
    int aux[r-l+1];
	for (int i=0;i<r-l+1;i++)
	aux[i]=a[l+i];
	int end1=m-l;int end2=r-l;
	int i=0,j=m-l+1,k=l;
for(i,j,k;i<=end1&&j<=end2;)
	{
	  if(aux[i]<aux[j])
	   a[k++]=aux[i++];
	 else a[k++]=aux[j++];	
			}
	while(i<=end1) a[k++]=aux[i++];
	while(j<=end2) a[k++]=aux[j++];
}
//Ã°ÅÝÅÅÐò 

void bubbleSort(int a[],int n){
	   bool ok=false;
        for(int sum=n;sum>0;sum--){
		if(ok==true) break;
	   for (int j=1;j<sum;j++)
	   {
	    
	   if(a[j]<a[j-1]) swap(a[j],a[j-1]);
	   if(ok ) ok=0;
	   }
}
}
//Ñ¡ÔñÅÅÐò 
void selectionSort(int a[],int n){
	int temp=a[0];
	int minIndex=0;
	for(int i=0;i<n;i++){
	for(int j=i;j<n;j++)
	if(a[j]<temp) temp=a[j],minIndex=j;
	swap(a[i],a[minIndex]);
	
		}
}
int main()  
{  int a[6]={0,1,2,-3,4,5};
   selectionSort(a,5);
   for (int i=0;i<6;i++)
   cout<<a[i]<<" ";
   return 0;
    
}
