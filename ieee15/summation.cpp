#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll binpow(ll a, ll b, ll m)
{
  a %= m;
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main()
{
  int p, q, n, m;
  cin >> p >> q >> n >> m;
  ll total = 0;
  for (int i = 1; i <= n; i++)
  {
    total = total + (binpow(p, i, m) * binpow(i, q, m) % m);
    total %= m;
  }
  cout << total << endl;
}
