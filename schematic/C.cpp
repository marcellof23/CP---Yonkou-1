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

int r[8] = {1, 2, 3, 1, 2, 1};
int l[8] = {2, 2, 2, 3, 3, 4};

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
    for (int i = 0; i < 8; i++)
    {
      string ss = S.substr(r[i], l[i]);
      //cout << ss << " ";
      auto it = mymap.find(ss);
      if (it != mymap.end())
      {
        mymap[ss] = mymap[ss] + K;
      }
      else if (ss != "")
      {
        mymap.insert({ss, K});
      }
    }
  }
  sort(mymap);
}