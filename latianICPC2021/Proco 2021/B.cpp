#include <bits/stdc++.h>
using namespace std;

int n;
bool check_bound(int x, int y, int dx, int dy)
{
  if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n)
  {
    return true;
  }
  return false;
}
int main()
{
  cin >> n;
  bool vis[n][n];
  int cnta = 0, cntb = 0;
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < (2 * n * n) - (2 * n); i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vis[x1][y1] = true;
    vis[x2][y2] = true;
    if (x1 > x2)
    {
      swap(x1, x2);
    }
    if (abs(x1 - x2) != 0)
    {
      if (check_bound(x1, y1, 0, 1) && check_bound(x2, y2, 0, 1))
      {
        if (vis[x1][y1 + 1])
      }
    }
    else
    {
    }
  }
}