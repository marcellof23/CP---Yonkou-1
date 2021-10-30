#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool comp1(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first != p2.first)
    {
        return p1.first <= p2.first;
    }
  return p1.second < p2.second;
}

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
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      v.push_back({x, y});
    }
    sort(v.begin(), v.end(), comp1);
     
    vector<int> ans;
    int cnt = 0;
    while (cnt < n)
    {
      if ((cnt + 1) >= v[cnt].first && (cnt + 1) <= v[cnt].second)
      {
        ans.push_back(cnt + 1);
      }
      else
      {
        break;
      }
      cnt++;
    }
    if (cnt == n)
    {
      for (auto a : ans)
      {
        cout << a << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "impossible" << endl;
    }
  }
}