#include <iostream>
#include <math.h>
using namespace std;
//ɸѡ���� 
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
//��������ӡ������ҵ�������ĩλΪ1��������Ҳ��������룭1 
void print(int i){
	bool isPutout=false;
for(int k=2;k<i;k++) {
	
if(marked[k]&&(k%10==1)){
  if(isPutout==false) isPutout=true;//�ҵ��ˣ���isPutout��1 
	cout<<k<<"   ";}
 }
 
 if(isPutout==false) cout<<-1;//û���ҵ� �������1 
}
int main(){
	cout<<"�ж�һ�������Ƿ�Ϊ����"<<endl; 
int n;
init();
while(cout<<"����һ������1������:"&&cin>>n&&n>=2)//�ж����� 
print(n),cout<<endl;
return 0;
} // main()
