#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string s;
    cin >> s;
    int maks = -1;
    for (int i = 0; i < s.size(); i++)
    {
      int x = s[i] - '0';
      if (x <= 9)
      {
        maks = max(maks, s[i] - '0' + 1);
      }
      else if (x <= 42)
      {
        maks = max(maks, s[i] - 'A' + 37);
      }
      else
      {
        maks = max(maks, s[i] - 'a' + 11);
      }
      // cout << x << " ";
    }
    cout << maks << " " << 62 << endl;
  }
}