#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n, greater<int>());
  bool pass = false;
  for (int i = 0; i < n - 6; i++)
  {
    if (arr[i] < ((ll)arr[i + 1] + arr[i + 2]) && ((ll)arr[i + 1] + arr[i + 2]) < ((ll)arr[i + 3] + arr[i + 4] + arr[i + 5] + arr[i + 6]))
    {
      cout << (ll)arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] + arr[i + 4] + arr[i + 5] + arr[i + 6] << endl;
      pass = true;
      break;
    }
    else
    {
      continue;
    }
  }

  if (!pass)
  {
    cout << -1 << endl;
  }
  return 0;
}