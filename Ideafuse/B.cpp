#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct word
{
  string key;
  int search;
  int occ;
};

bool comparefn(word a, word b)
{
  if (a.search > b.search)
    return true;
  else if (a.occ > b.occ)
    return true;
  else
    return a.key < b.key;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int N;
    multimap<string, int> mpOcc, mpSearch;
    map<string, int> m;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      int M;
      cin >> M;
      map<string, int> m1;
      for (int i = 0; i < M; i++)
      {
        string s;
        cin >> s;
        m.insert({s, 1});
        m1.insert({s, 1});
        mpOcc.insert({s, 1});
      }
      for (auto mm : m1)
      {
        mpSearch.insert({mm.first, 1});
      }
    }
    int msize = m.size();
    word wArr[msize];
    int curr = 0;
    for (auto mm : m)
    {
      wArr[curr].key = mm.first;
      wArr[curr].occ = mpOcc.count(wArr[curr].key);
      wArr[curr].search = mpSearch.count(wArr[curr].key);
      ++curr;
    }
    sort(wArr, wArr + msize, comparefn);

    cout << "Case #" << t << ": ";
    for (int j = 0; j < min(5, msize); j++)
    {
      cout << wArr[j].key << " ";
    }
    cout << endl;
  }
}