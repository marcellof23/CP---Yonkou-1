#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<string, ll> &l,
         pair<string, ll> &r)
{
  if (l.second != r.second)
  {
    return l.second > r.second;
  }
  return stoi(l.first) > stoi(r.first);
}

void sort(map<string, ll> &M)
{

  vector<pair<string, ll>> A;

  for (auto &it : M)
  {
    A.push_back(it);
  }

  sort(A.begin(), A.end(), cmp);

  cout << "V" << A[0].first << endl;
}

int r[6] = {1, 2, 3, 1, 2, 1};
int sz[6] = {2, 2, 2, 3, 3, 4};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  map<string, ll> mymap;
  for (int i = 0; i < T; i++)
  {
    string S;
    int K;
    cin >> S >> K;

    set<string> s;

    for (int i = 0; i < 6; i++)
    {
      string ss = S.substr(r[i], sz[i]);
      if (ss[0] == '0')
      {
        continue;
      }
      s.insert(ss);
    }
    for (auto s_ : s)
    {
      auto it = mymap.find(s_);

      if (it != mymap.end())
      {
        mymap[s_] += K;
      }
      else if (s_ != "")
      {
        mymap.insert({s_, K});
      }
    }
  }
  sort(mymap);
}