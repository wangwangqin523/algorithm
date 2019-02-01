#include<iostream>
using namespace std;
const int k=50;
long long f[k];
int  main(){
	f[1]=1;f[2]=2;
	int n;
	for (int i=3;i<=k;i++)
		f[i]=f[i-1]+f[i-2];

	while(cout<<"Input the value of n:"&&cin>>n&&n!=EOF){
	cout<<"The result is "<<f[n]<<endl;
}
	
	
	return 0;
	}