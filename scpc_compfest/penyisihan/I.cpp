#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 5;
int V[MAXN];
vector<int> nol, satu;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> V[i];
  }
  for (int i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    if (V[i] == 0)
    {
      nol.push_back(x);
    }
    else
    {
      satu.push_back(x);
    }
  }
  return 0;
}