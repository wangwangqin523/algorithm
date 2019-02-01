#include<iostream>
using namespace std;
//0,1knapsack problem
const int W = 70;
const int N=3;
struct E{
int w;
int v;
}list[N+1];


void pack1(){//double dims
int d[N+1][W+1];
	for (int i=1;i<=N ;i++)  cin>>list[i].w>>list[i].v;//initize the list.

for (int i=0;i<=W;i++) d[0][i]=0;//The first line is set 0
for (int i=0;i<=N;i++) d[i][0]=0;//The first column is set 0;
for (int i=1;i<=N;i++){
	for (int j=1;j<=W;j++)
	{if(j<list[i].w)  d[i][j]=d[i-1][j];
	else d[i][j]=max(d[i-1][j-list[i].w]+list[i].v,d[i-1][j]);//The state trafer
	
	}
	
	}
cout<<"\t"<<d[N][W];
	}
	
void pack2(){
	int d[W+1];
	for (int i=1;i<=N ;i++)  cin>>list[i].w>>list[i].v;//initize the list.

for (int i=0;i<=W;i++) d[i]=0;//The first line is set 0

for (int i=1;i<=N;i++){
	for (int j=W;j>=list[i].w;j--)

 d[j]=max(d[j-list[i].w]+list[i].v,d[j]);//The state trafer
	
	
	
	}
cout<<"\t"<<d[W];
	
	
	
	}	
	
int main() {
//	pack1();
     pack2();
    return 0;
}