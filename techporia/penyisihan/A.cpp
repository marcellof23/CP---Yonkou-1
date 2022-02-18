#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, target;
  n = 5;
  int x[n] = {50, 25, 10, 5, 1};

  while (cin >> target)
  {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= target; j++)
      {
        dp[i][j] = dp[i - 1][j];
        int left = j - x[i - 1];
        if (left >= 0)
        {
          (dp[i][j] += dp[i][left]);
        }
      }
    }
    cout << dp[n][target] << endl;
  }
}