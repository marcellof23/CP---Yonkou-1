#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxN 50

ll fib[maxN];

string encode_fib(ll n)
{
  fib[0] = 1;
  fib[1] = 2;
  ll id;
  for (id = 2; fib[id - 1] <= n; id++)
  {
    fib[id] = fib[id - 1] + fib[id - 2];
  }

  ll idx = id - 2;
  char *str = (char *)malloc(sizeof(char) * (idx + 5));
  ll i = idx;

  while (n)
  {
    str[i] = '1';

    n -= fib[i];

    i = i - 1;
    while (i >= 0 && fib[i] > n)
    {
      str[i] = '0';
      i = i - 1;
    }
  }

  str[idx + 1] = '\0';
  string s = str;
  reverse(s.begin(), s.end());
  return s;
}

int main()
{
  ll n = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    cout << encode_fib(x) << endl;
  }
  return 0;
}