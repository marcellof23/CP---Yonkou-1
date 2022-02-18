#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NMAX 200069

int N, d[NMAX];

int main()
{
  cin >> N;
  memset(d, 0, sizeof(d));
  for (int i = 0; i < N; i++)
  {
    int t;
    cin >> t;
    while (d[t])
    {
      d[t++] = 0;
    }
    d[t] = 1;
  }
  int cc = 0;
  for (int i = 0; i < NMAX; i++)
    if (d[i])
      cc++;
  if (cc == 2 || cc == 1 && N != 1)
    cout << "Y" << endl;
  else
    cout << "N" << endl;
  return 0;
}
