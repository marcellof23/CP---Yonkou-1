#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxi = 2e5 + 5;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string biner;
  cin >> biner;

  int max_one = maxi;
  for (int i = 1; i < n; i++)
  {
    if (biner[i] == '1')
    {
      max_one = i;
      break;
    }
  }

  ll total = 0;
  ll curr_n = n - 1;

  for (int i = 0; i < n - 1; i++)
  {
    if (n - i - 1 < max_one)
    {
      total += (curr_n - 1);
    }
    else
    {
      total += (curr_n);
    }
    curr_n--;
  }

  cout << total << endl;
}