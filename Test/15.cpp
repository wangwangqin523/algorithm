#include<iostream>
using namespace std;
//layout problem
 int main(){
int n;char a,b;
char buf[81][81];
bool firstCase=true;//The fist case need didn't have a line.
while(cin>>n>>b>>a&&n!=0)
{
if (firstCase==true) firstCase=false;
else cout<<endl;
for (int k=1;k<=(n+1)/2;k++){
int begin=k;int end=n+1-begin;
char x=(begin%2==1? a:b);
   for (int i=begin;i<=end;i++)  
  { buf[begin][i]=x,buf[end][i]=x;
   for (int j=begin+1;j<=end-1;j++)  buf[j][begin]=x,buf[j][end]=x;}
}

if (n!=1){
buf[1][1]=' ';buf[1][n]=' ';buf[n][1]=' ';buf[n][n]=' ';}


for (int i=1;i<=n;i++)
{   for (int j=1;j<=n;j++)
cout<<"  "<<buf[i][j];
cout<<endl;}
}

return 0;

}