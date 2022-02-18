#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int A, B;
  cin >> A >> B;
  if (A == 0)
  {
    cout << "Ya" << endl;
  }
  else if (B >= 2 * A)
  {
    cout << "Ya" << endl;
  }
  else
  {
    cout << "Tidak" << endl;
  }
  return 0;
}