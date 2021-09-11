#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<string> grids;
  string arr_str[N][M];

  for (int i = 0; i < N; i++)
  {
    string str;
    cin >> str;
    grids.push_back(str);
  }

  int k = 2;
  vector<string> curr[4];
  for (int i = 0; i < N - k + 1; i++)
  {
    for (int j = 0; j < M - k + 1; j++)
    {
      for (int kk = 0; kk < k < kk++)
      {
        arr_str[i][j] += grids[kk].substr(kk, kk + k);
      }
    }
  }

  return 0;
}