#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e6 + 6;
const int mods = 1e9 + 7;
int arr[NMAX];

int n;

int xors(int val)
{
  int maks = arr[0];
  for (int i = 1; i < n; i++)
  {
    maks = max(maks, arr[i]);
  }

  int max_xor = (1 << (int)(log2(maks) + 1)) - 1;
  if (val > max_xor)
  {
    return 0;
  }
  int dp[n + 1][max_xor + 1];
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= max_xor; j++)
    {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= max_xor; j++)
    {
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]]) % mods;
    }
  }

  dp[n][val] = dp[n][val] % mods;

  return dp[n][val];
}

int main()
{
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    mp[x]++;
  }
  int j = 0;
  memset(arr, 0, sizeof(arr));
  for (auto m : mp)
  {
    arr[j++] = m.second;
  }
  n = j;

  cout << xors(0) << endl;
}