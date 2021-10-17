#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int T;
  cin >> T;
  string S[T];
  int N[T], R[T];
  pair<double, int> p[T];
  for (int i = 0; i < T; i++)
  {
    cin >> S[i] >> N[i] >> R[i];
    double juring_part = (((double)180 * ((double)N[i] - 2)) / (double)N[i]) / (double)360;
    ll total = R[i] * R[i] * N[i];
    // cout << (double)1 / (double)3 * 4 << " " << total << endl;
    cout << (double)juring_part * (double)total << endl;
    p[i] = {abs((((double)1 - juring_part) * (double)total) - (double)juring_part * (double)total), i};
  }
  if (T == 1)
  {
    cout << S[0] << endl;
    return 0;
  }
  sort(p, p + T);
  if (p[T - 1].first == p[T - 2].first)
  {
    cout << "SERI" << endl;
  }
  else
  {
    // cout << p[T - 1].first << endl;
    cout << S[p[T - 1].second] << endl;
  }
}
