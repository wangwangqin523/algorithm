#include <iostream>
#include <math.h>
using namespace std;
//筛选素数 
bool marked[10001];
void init(){
for (int i=2;i<=10000;i++) marked[i]=true;
for (int i=2;i<=10000;i++)
{
if (marked[i]==false )
continue;
for (int j=2;j*i<=10000;j++)
marked[i*j]=false;

}

}
//按条件打印，如果找到素数且末位为1则输出，找不到则输入－1 
void print(int i){
	bool isPutout=false;
for(int k=2;k<i;k++) {
	
if(marked[k]&&(k%10==1)){
  if(isPutout==false) isPutout=true;//找到了，将isPutout置1 
	cout<<k<<"   ";}
 }
 
 if(isPutout==false) cout<<-1;//没有找到 ，输出－1 
}
int main(){
	cout<<"判断一个整数是否为素数"<<endl; 
int n;
init();
while(cout<<"输入一个大于1的整数:"&&cin>>n&&n>=2)//判断条件 
print(n),cout<<endl;
return 0;
} // main()
