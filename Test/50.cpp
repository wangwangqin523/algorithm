#include <iostream>
#include <math.h>
using namespace std;
//判断一个数是否为素数
bool judge(int m)
{
    if (m <= 1)
        return false;
    if (m == 2)
        return true;
    int bound = (int)sqrt(m) + 1;
    for (int i = 2; i <= bound; i++)
        if (m % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    while (cout << "Input a number:" && cin >> n && n != EOF)
        cout << (judge(n) ? "Yes" : "No") << endl;

    return 0;
} // main()
