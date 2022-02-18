#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int n, m;
bool comparefn(pair<string, int> a, pair<string, int> b)
{
  cout << m;
  for (int i = 1; i <= a.first.size(); i++)
  {

    if (a.first[i - 1] != b.first[i - 1])
    {

      if (i % 2)
      {
        return a.first[i - 1] <= b.first[i - 1];
      }
      else
      {
        return a.first[i - 1] >= b.first[i - 1];
      }
    }
    else
    {
      if (i < m && (i + 1) % 2)
      {
        return a.first[i] <= b.first[i];
      }
      else if (i < m)
      {
        return a.first[i] >= b.first[i];
      }
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> v;
  for (int i = 0; i < n; i++)
  {
    string x;
    cin >> x;
    v.push_back({x, i + 1});
  }

  sort(v.begin(), v.end(), comparefn);

  for (auto a : v)
  {
    cout << a.second << " ";
  }
  return 0;
}