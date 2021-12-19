#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll L, R;
  ll cnt = 0;

  cin >> L >> R;

  ll i = ceil(sqrt(L));

  while (i * i <= R)
  {
    ll inhabit = i * i;
    ll native = 0, remainder = 0;

    if (i % 10 == 0)
    {
      i++;
      continue;
    }
    while (inhabit != 0)
    {
      remainder = inhabit % 10;
      native = native * 10 + remainder;
      inhabit /= 10;
    }

    long double sqr = sqrt((long double)native);

    if (sqr - floor(sqr) == 0)
    {
      cnt++;
    }
    i++;
  }

  cout << cnt << endl;
  return 0;
}