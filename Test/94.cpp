#include<iostream>
using namespace std;
// All of the n envelops are wrong.
const int k = 10;
long long f[k];
int main() {
  f[1] = 0;
  f[2] = 1;
  int n;
  for (int i = 3; i <= k; i++)
    f[i] = (i - 1) * f[i - 1] + (i - 1) * f[i - 2];

  while (cout << "Input the value of n:" && cin >> n && n > 2) 
    cout << "The result is " << f[n] << endl;
 
     return 0;
}