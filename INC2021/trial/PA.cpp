#include <bits/stdc++.h>
using namespace std;

int alp[26];

#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;

  memset(alp, 0, sizeof(alp));

  for (int i = 0; i < n; i++)
  {
    if (s1[i] != s2[i])
    {
      alp[s1[i] - 'a']++;
      alp[s2[i] - 'a']++;
    }
    else
    {
      alp[s1[i] - 'a']++;
    }
  }

  int maks = -1;
  for (int i = 0; i < 26; i++)
  {
    // cout << alp[i] << " ";
    maks = max(maks, alp[i]);
  }
  cout << maks << endl;
}