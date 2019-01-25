#include  <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;
const int n=1000;
class unionFind{//BaseClass
       protected:
                     int * id;
              int count;
		public:
	   unionFind(){
	  
	   	}
	 /*  void print(){
	   	for (int i=0;i<n;i++)
	   	cout<<id[i]<<" ";}*/
	~unionFind(){
		}
	virtual	int find(int p){}
			bool isConnected(int p,int q){
				return find(p)==find(q);
				}
};

class unionFind1:public unionFind{//QuickSort
               		public:
	   unionFind1(){
	   	count=n;
	   	id=new int[n];
	   	for(int i=0;i<n;i++)
	   	id[i]=i;
	   	}
	~unionFind1(){
		delete[] id;
		}
	virtual	int find(int p){
			assert(p>=0&&p<count);
			return id[p];
			}
	
			void unionElements(int p,int q){
if( id[p]==id[q])     return;
								for (int i=0;i<count;i++)
				if(id[i]==id[p])  id[i]=id[q];
				}
	};

class unionFind2 :public unionFind{//Quick Union
	       private:
              int *rank;//base on the height of tree
		public:
	   unionFind2(){
	   	count=n;
	   	id=new int[n];
	   	rank=new int[n];
	   	for(int i=0;i<n;i++)
	   	id[i]=i,rank[i]=1;
	   	}
	  
	~unionFind2(){
		delete[] id;
		delete[] rank;
		}
virtual		int find(int p){
			assert(p>=0&&p<count);
			while(id[p]!=p)
			{
				id[p]=id[id[p]];
				p=id[p];
				}
				
			return p;
			}
			
			void unionElements(int p,int q){
          int pID=find(p);int qID=find(q);
          if(pID==qID)       return;
          if(rank[pID]>rank[qID])   id[qID]=pID;
           else if(rank[pID]>rank[qID]) id[pID]=qID;
              else id[pID]=qID,rank[qID]++;
				}
	};
	
class unionFind2r :public unionFind2{
virtual	int find(int p){
		if(id[p]!=p) 		       id[p]=find(id[p]);
		return id[p];
		}
	};

template <typename UF>
void testUF(){
UF uf;
	srand(time(NULL));
	time_t startTime=clock();
	for(int i=0;i<n;i++){
		int a=rand()%n;
		int b=rand()%n;
		uf.unionElements(a,b);
	}
	for (int i=0;i<n;i++)
	{ int a=rand()%n;
	int b= rand()%n;
	uf.isConnected(a,b);
	}
	time_t endTime=clock();
cout<<"\t"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"S"<<endl;}	
	