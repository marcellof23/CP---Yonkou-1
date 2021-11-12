#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, S, K;
  cin >> K >> S >> N;
  if (S * K > N)
  {
    cout << "NO" << endl;
    return 0;
  }
  if ((N - S * K) % 2 != 0 && S == 1)
  {
    if (N > 2 * K - 2)
    {
      cout << "NO" << endl;
    }
    return 0;
  }
  cout << "YES" << endl;
}