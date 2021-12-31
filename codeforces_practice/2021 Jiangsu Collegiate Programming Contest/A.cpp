#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s1[n], s2[n];
    for (int i = 0; i < n; i++)
    {
      cin >> s1[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> s2[i];
    }

    bool bener = true;

    for (int i = 0; i < n - 1; i++)
    {
      bool lvl = false, obl = false;
      if (s1[i][s1[i].size() - 1] - '0' < 3)
      {
        lvl = true;
      }
      else
      {
        obl = true;
      }

      if (s2[i][s2[i].size() - 1] - '0' < 3)
      {
        lvl = true;
      }
      else
      {
        obl = true;
      }

      if (lvl && obl)
      {
        // cout << s1[i][s1[i].size() - 1] - '0' << " " << s2[i] << endl;
        continue;
      }
      else
      {
        bener = false;
        break;
      }
    }

    if (!(s1[n - 1][s1[n - 1].size() - 1] - '0' >= 3 && s2[n - 1][s2[n - 1].size() - 1] - '0' < 3))
    {
      bener = false;
    }

    if (bener)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}