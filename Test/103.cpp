#include<iostream>
using namespace std;
//0,1mutiple knapsacks problem
const int W = 8;
const int N=2;
struct E{
int w;
int v;
}list[2001];
int d[101];

	
void pack(){
	int T;cin>>T;
	while(T--){
		int m=0;//m is the mark of the array.
		for (int i=1;i<=N;i++)
		{   int b=1;int w,v,c;//b is base,c is count of the kind rice
			  cin>>w>>v>>c;
		while(c-b>0){   
				    c=c-b;
		     list[++m].w=b*w;list[m].v=b*v;  
		    b=b*2;

		    }
		list[++m].w=c*w;list[m].v=c*v;
		
		}
		
		}



for (int i=0;i<=W;i++) d[i]=0;//The first line is set 0

for (int i=1;i<=m;i++){
	for (int j=W;j>=list[i].w;j--)

 d[j]=max(d[j-list[i].w]+list[i].v,d[j]);//The state trafer
	
	
	
	}
cout<<"\t"<<d[W];
	
	
	
	}	
	
int main() {
     pack();
    return 0;
}