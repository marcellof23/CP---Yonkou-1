#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p2[64];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  ll arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    ll cnt2 = 0;
    if (arr[i] % 2)
    {
      cout << 1 << endl;
      continue;
    }
    while (arr[i] % 2 == 0)
    {
      arr[i] /= 2;
      cnt2++;
    }
    if (cnt2 % 2)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << 1 << endl;
    }
  }
}