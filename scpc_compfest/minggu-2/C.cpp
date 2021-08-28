#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n + 1];
  memset(arr, 0, sizeof(arr));
  int cumul = 0;
  int total;
  cout << "? " << 1 << " " << n << endl;
  cin >> total;
  for (int i = 2; i < n; i++)
  {
    int juri;
    cout << "? " << i << " " << n << endl;
    cin >> juri;
    arr[i - 1] = total - juri - cumul;
    cumul += arr[i - 1];
  }
  int pref;
  cout << "? " << 1 << " " << n - 1 << endl;
  cin >> pref;
  arr[n] = total - pref;
  arr[n - 1] = total - cumul - arr[n];
  cout << "! ";
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}