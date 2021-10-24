#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    vector<int> fact;
    for (int i = 1; i <= 13; i++)
    {
      if (N % i == 0)
      {
        fact.push_back(i);
      }
    }
    int fsize = fact.size();
    int nmax = 2 << (fsize - 1);
    bool yes = false;
    for (int i = nmax - 1; i >= 0; i--)
    {
      vector<int> ans;
      int tot = 0;
      for (int j = 0; j < fsize; j++)
      {
        if ((i & (1 << (fsize - j - 1))) != 0)
        {
          ans.push_back(fact[j]);
          tot += fact[j];
        }
      }
      if (tot == 13)
      {
        yes = true;
        for (auto a : ans)
        {
          cout << a << " ";
        }
        cout << endl;
        break;
      }
    }
    if (yes)
    {
      continue;
    }
    else
    {
      cout << -1 << endl;
    }
  }
}