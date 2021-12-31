#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, m;
    cin >> m >> n;
    if (m == 1)
    {
      if (n == 0)
      {
        cout << 1 << endl;
      }
      else
      {
        cout << 2 << endl;
      }
      continue;
    }

    if (n == 0)
      cout << ((ll)1 << m) << endl;
    else
      cout << (((ll)1 << m) - 1) << endl;
  }
}