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
    int x;
    cin >> x;
    arr[i] = x;
  }

  sort(arr, arr + n);

  int gabung = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (gabung == n - 2 && i == n - 2)
    {
      break;
    }
    if (arr[i] == arr[i + 1])
    {
      arr[i + 1] = arr[i] + 1;
      arr[i] = 0;
      gabung++;
    }
  }

  int valid = 0;
  int nol = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
      valid++;
  }

  if (valid == 2)
  {
    cout << "Y" << endl;
  }
  else
  {
    cout << "N" << endl;
  }
}