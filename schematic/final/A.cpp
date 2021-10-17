#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NMAX = 1e6 + 5;
int N;

void solve(vector<int> v)
{
  int n = v.size();
  bool subs[n][14];

  for (int i = 0; i <= n; i++)
  {
    subs[i][0] = true;
  }
  for (int i = 1; i <= N; i++)
  {
    subs[0][i] = false;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= 13; j++)
    {
      if (j < v[i - 1])
      {
        subs[i][j] = subs[i - 1][j];
      }
      else
      {
        subs[i][j] = subs[i - 1][j] || subs[i - 1][j - v[i - 1]];
      }
    }
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= 13; j++)
    {
      cout << subs[i][j] << " ";
    }
    cout << endl;
  }
}
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    cout << "oi";
    cin >> N;
    vector<int> v(13);
    for (int i = 2; i <= 13; i++)
    {
      if (i > N)
      {
        break;
      }
      if (N % i == 0)
      {
        v.push_back(i);
      }
    }
    cout << "oi";
    solve(v);
  }
}