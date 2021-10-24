#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, K;
    cin >> N >> K;
    ll arr[N];
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }
    sort(arr, arr + N, greater<ll>());
    ll tot = 0;
    ll minim = -1;
    if (K == 0)
    {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < N; i++)
    {
      tot += arr[i];
      if (tot >= K)
      {
        minim = i + 1;
        break;
      }
    }
    cout << minim << endl;
  }
}