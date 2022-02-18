#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct medal
{
  int g;
  int s;
  int c;
  string country;
};

bool cmp(medal x, medal y)
{
  if (x.g != y.g)
    return x.g > y.g;
  else if (x.s != y.s)
    return x.s > y.s;
  else if (x.c != y.c)
    return x.c > y.c;
  else
    return x.country > y.country;
}

int main()
{
  int n;
  cin >> n;
  cin.ignore();
  vector<medal> v(n);
  for (int i = 0; i < n; i++)
  {
    int g, s, c;
    string str;
    getline(cin, str);
    vector<string> res;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' '))
    {
      res.push_back(token);
    }

    string cnt("");
    int sz = res.size();
    for (int j = 3; j < sz; j++)
    {
      cnt.append(res[j]);
      if (j < sz - 1)
      {
        cnt.append(" ");
      }
    }

    v.push_back({stoi(res[0]), stoi(res[1]), stoi(res[2]), cnt});
  }
  sort(v.begin(), v.end(), cmp);

  cout << v[0].country;
  cout << endl;
}
