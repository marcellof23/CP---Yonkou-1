#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int arr[10];
    for (int j = 0; j < 3; j++)
    {
      cin >> arr[j];
    }
    sort(arr, arr + 3);
    if (arr[0] + arr[1] > arr[2])
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
