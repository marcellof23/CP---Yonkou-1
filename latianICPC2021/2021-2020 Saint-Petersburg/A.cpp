#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, rook;
  cin >> n >> m >> rook;
  int maks = min(n, m);
  if (maks < rook)
  {
    cout << "Impossible" << endl;
  }
  else
  {
    cout << "Possible" << endl;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (j == i && rook != 0)
        {
          cout << "*";
          rook--;
        }
        else
        {
          cout << ".";
        }
      }
      cout << endl;
    }
  }

  return 0;
}