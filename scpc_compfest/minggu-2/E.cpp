#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string S;
    cin >> S;
    int maks = -1;
    int ptr = -1;
    for (int i = 0; i < S.size(); i++)
    {
      int x = S[i] - '0';
      cout << x << " ";
      if (x <= 9)
      {
        if (maks <= S[i] - '0' && ptr != 1 && ptr != 2)
        {
          maks = S[i] - '0';
          ptr = 0;
        }
      }
      else if (x <= 42)
      {

        if (maks <= S[i] - 'A')
        {
          maks = S[i] - 'A';
          ptr = 1;
        }
      }
      else
      {
        if (maks <= S[i] - 'a' && ptr != 1)
        {
          maks = S[i] - 'a';
          ptr = 2;
        }
      }
    }
    if (ptr == 0)
    {
      cout << maks + 1 << " " << 62 << endl;
    }
    else if (ptr == 1)
    {
      cout << maks + 37 << " " << 62 << endl;
    }
    else
    {
      cout << maks + 11 << " " << 62 << endl;
    }
  }
}