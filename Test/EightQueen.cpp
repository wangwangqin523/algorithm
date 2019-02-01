#include<iostream>
using namespace std;
const int n=8;
int s[]={1,2,3,4,5,6,7,8};
int  ans[n+1];
bool mark[n+1];
int c=0;//count the number of the solutions.
void print(){
for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
   if(abs(i-j)==abs(ans[i]-ans[j]))
   return;
for (int i=1;i<=n;i++)
{
     for (int j=1;j<=n;j++)
{if(j==n&&ans[i]!=j) cout<<"|";
 if(ans[i]!=j&&j<n) cout<<"|-" ;
if(ans[i]==j&&j==n)cout<<"o";
if(ans[i]==j&&j<n)cout<<"o-";}
cout<<endl;}
c++;
cout<<"-----------------"<<c;
cout<<endl;
}



void dfs(int p){
if(p<0)  return;
if(p==n) {
print();
return;
}
for (int i=0;i<n;i++){
if (mark[i]==0)
{mark[i]=1;
ans[p+1]=s[i];
dfs(p+1);
mark[i]=0;
}
}
}

int main(){
dfs(0);

	return 0;
	}