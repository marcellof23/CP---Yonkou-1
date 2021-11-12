#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  string a, b;
  cin >> a >> b;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (isdigit(a[i]))
    {
      cnt1++;
    }
  }
  for (int i = 0; i < b.size(); i++)
  {
    if (isdigit(b[i]))
    {
      cnt2++;
    }
  }
  if (cnt1 == a.size() && cnt2 == b.size())
  {
    cout << stoi(a) - stoi(b) << endl;
  }
  else
  {
    cout << "NaN" << endl;
  }
}
