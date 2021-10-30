#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define piii pair<pii, int>
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<piii> v;
    for (int i = 0; i < n; i++)
    {
      int l, r;
      v[i].first.first = l;
      v[i].first.second = r;
      v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    priority_queue<piii> pq;
    }
}