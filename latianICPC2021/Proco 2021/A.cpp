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
  long long tot1 = arr[0], tot2 = arr[0];
  for (int i = 1; i < n; i++)
  {
    tot1 += arr[i];
    tot2 ^= arr[i];
  }
  cout << tot1 - tot2 << endl;
}
