#include <bits/stdc++.h>
using namespace std;

int n, x = 1, cnt = 1, ans = 0;
int arr[300069];
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 2; i <= n; ++i)
  {
    if (arr[i] == arr[i - 1])
      continue;
    int y;
    if (arr[i] > arr[i - 1])
    {
      y = 1;
    }
    else
    {
      y = -1;
    }
    if (x != y)
    {
      cnt++;
      x = y;
    }
  }
  int c = 1;
  while (c < cnt)
  {
    c *= 2;
    ++ans;
  }

  cout << ans << endl;
  return 0;
}