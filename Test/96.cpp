#include<iostream>
using namespace std;
// The longest sub sequence of no increasing.
const int k = 8;
int list[k + 1];
int dp[k + 1];
int main() {
  for (int i = 1; i <= k; i++)
    cout << "  ", cin >> list[i];
  dp[1] = 1;
  for (int i = 2; i <= k; i++) {
    int max = 1;
    for (int j = i - 1; j >= 1; j--)
      if (list[i] <= list[j] && dp[j] + 1 > max)
        max = dp[j] + 1;
    dp[i] = max;
  }
  cout << "   The puted list is: ";
  for (int i = 1; i <= k; i++)
    cout << "   " << list[i];
  cout << endl << "  The count is :    ";
  for (int i = 1; i <= k; i++)
    cout << "   " << dp[i];
  int ans = 1;
  for (int i = 1; i <= k; i++)
    ans = max(ans, dp[i]);
  cout << endl << "  The sequence is :  " << ans;
  return 0;
}