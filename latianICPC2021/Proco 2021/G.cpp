#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define pii pair<pair<int, int>, pair<int, int>>

const int NMAX = 200069;
const int INF = 1e9 + 7;
int n, st[4 * NMAX], lz[4 * NMAX];

int N, M, K;
vector<pi> grid;
map<int, int> x, y;

void update(int v, int tl, int tr, int l, int r, int x)
{
  if (lz[v] != 0)
  {
    st[v] += lz[v];
    if (tl != tr)
    {
      lz[2 * v] += lz[v];
      lz[2 * v + 1] += lz[v];
    }
    lz[v] = 0;
  }

  if (l > r || tl > r || tr < l)
  {
    return;
  }

  if (tl >= l && tr <= r)
  {
    st[v] += x;
    if (tl != tr)
    {
      lz[2 * v] += x;
      lz[2 * v + 1] += x;
    }
    return;
  }
  int mid = (tl + tr) / 2;
  update(2 * v, tl, mid, l, r, x);
  update(2 * v + 1, mid + 1, tr, l, r, x);
  st[v] = max(st[2 * v], st[2 * v + 1]);
}

int query(int v, int tl, int tr, int l, int r)
{
  if (l > r || tl > r || tr < l)
  {
    return -INF;
  }
  if (lz[v] != 0)
  {
    st[v] += lz[v];
    if (tl != tr)
    {
      lz[2 * v] += lz[v];
      lz[2 * v + 1] += lz[v];
    }
    lz[v] = 0;
  }

  if (tl >= l && tr <= r)
    return st[v];

  int mid = (tl + tr) / 2;
  int q1 = query(2 * v, tl, mid, l, r);
  int q2 = query(2 * v + 1, mid + 1, tr, l, r);
  return max(q1, q2);
}

map<int, int> xcm, ycm;
set<int> xcs, ycs;
int xtot = 0, ytot = 0, maks = 0;

int main()
{
  cin >> N >> M >> K;
  grid.resize(M);
  for (int i = 0; i < M; i++)
  {
    cin >> grid[i].first >> grid[i].second;
  }

  for (int i = 0; i < M; i++)
  {
    xcs.insert(grid[i].first);
    ycs.insert(grid[i].second);
    xcs.insert(grid[i].first + K);
    ycs.insert(grid[i].second + K - 1);
  }

  for (int x : xcs)
  {
    xcm[x] = xtot;
    xtot++;
  }

  for (int y : ycs)
  {
    ycm[y] = ytot;
    ytot++;
  }

  vector<pii> sg(2 * M);
  for (int i = 0; i < M; i++)
  {
    sg[2 * i] = {{xcm[grid[i].first], ycm[grid[i].second]}, {ycm[grid[i].second + K - 1], 1}};
    sg[2 * i + 1] = {{xcm[grid[i].first + K], ycm[grid[i].second]}, {ycm[grid[i].second + K - 1], -1}};
  }

  sort(sg.begin(), sg.end());

  for (int i = 0; i < 2 * M; i++)
  {
    if (i != 0)
    {
      if (sg[i].first.first != sg[i - 1].first.first)
      {
        maks = max(maks, query(1, 0, ytot, 0, ytot));
      }
    }
    update(1, 0, ytot, sg[i].first.second, sg[i].second.first, sg[i].second.second);
  }

  cout << maks << endl;
}