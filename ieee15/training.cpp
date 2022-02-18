#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int M, X, Y, K;
    cin >> M >> X >> Y >> K;
    int arr[X];
    int dp[X + 1][Y + 1][K + 1];
    for (int i = 0; i < X; i++)
    {
      cin >> arr[i];
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= X; i++)
    {
      dp[i][1][1] = arr[i - 1];
    }

    for (int m = 0; m < M; m++)
    {
      for (int i = 1; i <= X; i++)
      {
        for (int j = 1; j <= Y; j++)
        {
          for (int k = 1; k <= K; k++)
          {
            if (i + k <= X)
              dp[i][j][k] = max(dp[i][j][k], dp[i][j][k] + arr[i + k]);
          }
        }
      }
    }

    for (int i = 1; i <= X; i++)
    {
      for (int j = 1; j <= Y; j++)
      {
        for (int k = 1; k <= K; k++)
        {
          cout << dp[i][j][k] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
  }
}