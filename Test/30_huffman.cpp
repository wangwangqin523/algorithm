#include <stdio.h>
#include <queue>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int>> Q;

int main(){
	while(scanf("%d",&n)){
		int temp;
		for(int i=0;i<n;i++)
		  {
		  	scanf("%d",&temp);
		  	Q.push(temp);
		  	
		  }
		  int ans=0;
		  while(!Q.empty()){
		 
		int variable1=Q.top();
		Q.pop();
	if(!Q.empty())	{
	     int variable2=Q.top();
		 Q.pop();
		ans=ans+variable1+variable2;
		Q.push(variable1+variable2);
		}
		
		
		 }
		printf("%d\n",ans);
		
		
		
	}
	
	
	
	
}
