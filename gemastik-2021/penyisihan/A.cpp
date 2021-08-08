#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, X;
  cin >> N >> X;
  vector<pair<int, string>> v;
  for (int i = 0; i < N; i++)
  {
    string x;
    cin >> x;
    int cvrt = stoi(x);
    v.push_back({abs(cvrt - X), x});
  }
  sort(v.begin(), v.end());
  int mins = v[0].first;
  int i = 0;
  vector<int> ans;
  while (i < N && v[i].first == mins)
  {
    cout << v[i].second << endl;
    i++;
  }

  return 0;
}