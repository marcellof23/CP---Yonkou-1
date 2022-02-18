#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int neg[1005];
  int pos[1005];
  int n;
  int cnt = 0;
  cin >> n;
  memset(pos, 0, sizeof(pos));
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x < 0)
    {
      if (pos[abs(x)])
      {
        continue;
      }
      else
      {
        cnt++;
      }
    }
    else
    {
      pos[x]++;
    }
  }
  cout << cnt << endl;
}