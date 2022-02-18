#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

const long long oo = 2e18+7, mo = 19880830;
using namespace std;
vector<long long> stack;
map<long long, long long> Map;
long long nexts[2000000], sora[2000000], cost[2000000], st[500000], u[500000], tail[500000], b[2000000];
long long v[500000], col[500000], d[500000], rt[3][500000];
long long ss, n, m, m1, s, t, q;
struct dist
{
  long long m;
  long long c;
} D[3][500000], ans[500000];
void origin()
{
  ss = n;
  for (long long i = 1; i <= n; i++)
    tail[i] = i, nexts[i] = 0;
  for (m1 = 1; m1 <= n + 2; m1 <<= 1)
    ;
  for (long long i = 1; i <= m1 + m1; i++)
    b[i] = 0;
  for (long long i = 1; i <= n; i++)
    b[i + m1] = i, d[i] = oo;
  for (long long i = 1; i <= n; i++)
  {
    v[i] = col[i] = 0;
    for (long long j = 0; j <= 2; j++)
      D[j][i].m = oo, D[j][i].c = 0, rt[j][i] = 0;
    ans[i].m = oo, ans[i].c = 0;
  }
  Map.clear(), stack.clear();
}
void link(long long x, long long y, long long z)
{
  ++ss, nexts[tail[x]] = ss, tail[x] = ss, sora[ss] = y, cost[ss] = z, nexts[ss] = 0;
  ++ss, nexts[tail[y]] = ss, tail[y] = ss, sora[ss] = x, cost[ss] = z, nexts[ss] = 0;
}
long long mind(long long x, long long y)
{
  return (d[x] < d[y]) ? x : y;
}
void change(long long x, long long w)
{
  d[x] =
      w;
  for (x = ((x + m1) >> 1); x; x >>= 1)
    b[x] =
        mind(b[x << 1], b[(x << 1) + 1]);
}
void dij(long long e, long long &r)
{
  for (; d[b[1]] != oo;)
  {
    long long x = b[1], cos = d[x];
    st[++r] = x, D[e][x].m = cos;
    change(x, oo);
    for (long long i = x, ne; nexts[i];)
    {
      i = nexts[i],
      ne = sora[i];
      if (d[ne] != oo && cos + cost[i] < d[ne] && v[x] == v[ne])
      {
        rt[e][ne] = x;
        change(ne, cos + cost[i]);
      }
    }
  }
}
void spfa(long long s, long long e)
{
  for (long long i = 0; i <= n; i++)
    change(i, oo + 1);
  change(s, 0);
  long long r = 0;
  dij(e, r);
  D[e][st[1]].c = 1;
  for (long long i = 1; i <= r; i++)
  {
    long long x = st[i];
    for (long long i = x, ne; nexts[i];)
    {
      i = nexts[i],
      ne = sora[i];
      if (D[e][x].m + cost[i] == D[e][ne].m)
        (D[e][ne].c += D[e][x].c) %= mo;
    }
  }
}
void dfs(long long x, long long level)
{
  stack.push_back(x);
  v[x] = level;
  for (long long i = x, ne; nexts[i];)
  {
    i = nexts[i],
    ne = sora[i];
    if (D[0][x].m + cost[i] == D[0][ne].m && !v[ne] && !col[ne])
      dfs(ne, level);
  }
}
bool cmp(long long i, long long j)
{
  if (v[i] != v[j])
    return v[i] > v[j];
  return col[i] < col[j];
}
void updata(long long w, long long c)
{
  map<long long, long long>::iterator it = Map.find(w);
  if (it == Map.end())
  {
    Map[w] = c;
    return;
  }
  it->second = ((it->second + c) % mo + mo) % mo;
  if (!(it->second))
    Map.erase(it);
}
void add_o_d(long long x, long long e)
{
  for (long long i = x, ne; nexts[i];)
  {
    i = nexts[i], ne = sora[i];
    if (v[ne] < v[x])
    {
      long long cos = D[2][x].m + cost[i] + D[1][ne].m;
      long long tmp = (D[2][x].c * D[1][ne].c) % mo;
      if (!tmp)
        return;
      updata(cos, tmp * e);
    }
  }
}
void add_u_d(long long x, long long e)
{
  for (long long i = x, ne; nexts[i];)
  {
    i = nexts[i], ne = sora[i];
    if (e * v[ne] > e * v[x])
    {
      long long cos;
      long long tmp;
      if (e == 1)
      {
        cos = D[0][ne].m + cost[i] + D[1][x].m;
        tmp = (D[0][ne].c * D[1][x].c) % mo;
      }
      else
      {
        cos = D[0][x].m + cost[i] + D[1][ne].m;
        tmp = (D[0][x].c * D[1][ne].c) % mo;
      }
      if (!tmp)
        return;
      updata(cos, -tmp * e);
    }
  }
}
int main(){
  scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
  origin();
  for (long long i = 1; i <= m; i++)
  {
    long long x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    link(x, y, z);
  }
  spfa(s, 0);
  spfa(t, 1);
  for (long long i = t; i; i = rt[0][i])
    col[i] =
        1;
  for (long long i = t, cnt = 1; i; i = rt[0][i], ++cnt)
  {
    stack.clear();
    dfs(i, cnt);
    for (long long i = 1; i < (long long)stack.size(); i++)
    {
      long long x = stack[i];
      d[x] = oo + 1;
      for (long long i = x, ne; nexts[i];)
      {
        i = nexts[i],
        ne = sora[i];
        if (!v[ne] && D[0][ne].m + cost[i] < d[x])
          change(x, D[0][ne].m + cost[i]);
      }
    }
    long long r = 0;
    dij(2, r);
    for (long long i = 1; i <= r; i++)
    {
      long long x = st[i];
      for (long long i = x, ne; nexts[i];)
      {
        i = nexts[i],
        ne = sora[i];
        if (!v[ne])
        {
          if (D[0][ne].m + cost[i] == D[2][x].m)
            (D[2][x].c += D[0][ne].c) %= mo;
        }
      }
      for (long long i = x, ne; nexts[i];)
      {
        i = nexts[i],
        ne = sora[i];
        if (v[ne] == v[x] && !col[ne])
        {
          if (D[2][x].m + cost[i] == D[2][ne].m)
            (D[2][ne].c += D[2][x].c) %= mo;
        }
      }
    }
  }
  for (long long i = 1; i <= n; i++)
    u[i] = i;
  sort(u + 1, u + n + 1, cmp);
  for (long long i = 1; i <= n; i++)
  {
    long long x = u[i];
    add_u_d(x, 1);
    if (!col[x])
    {
      add_o_d(x, 1);
    }
    else
    {
      if (Map.empty())
        ans[x].m = oo, ans[x].c = 0;
      else
      {
        map<long long, long long>::iterator it;
        it = Map.begin();
        if (it != Map.end())
          ans[x].m = it->first,
          ans[x].c = it->second;
      }
      for (long long j = i - 1; j >= 1 && v[u[j]] == v[u[i]]; j--)
        add_o_d(u[j], -1);
      for (long long j = i; j >= 1 && v[u[j]] == v[u[i]]; j--)
        add_u_d(u[j], -1);
    }
  }
  long long Ans = 0, X = 1;
  long long node = -1;
  for (long long j = 1; j <= n; j++)
  {
    if (ans[j].m == oo)
    {
      if (col[j])
        ans[j].m = 0, ans[j].c = 0;
      else
      {
        ans[j].m = D[0][t].m,
        ans[j].c = D[0][t].c;
        long long x = j;
        for (long long i = x, ne; nexts[i];)
        {
          i = nexts[i],
          ne = sora[i];
          if (D[0][x].m + cost[i] + D[1][ne].m == D[0][t].m)
            ans[j].c = ((ans[j].c - D[0][x].c * D[1][ne].c) % mo + mo) % mo;
        }
        if (ans[j].m == oo)
          ans[j].m = 0, ans[j].c = 0;
      }
    }
    if (ans[j].m > Ans){
      Ans = ans[j].m;
      node = j;
    }
  }
  printf("%lld", node);
  return 0;
}

/*
5 4 1 5
1 2 1
2 3 1
3 4 1
4 5 1
*/
