#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 4;
int n;
vector<pair<int, long long>> adjl[maxn];
map<int, long long> dp[maxn];
long long ans;

void dfs1(int u, int p)
{
  dp[u][0] = 1;
  for (auto &[v, w] : adjl[u])
  {
    if (v == p)
      continue;
    dfs1(v, u);
    for (auto &[cw, val] : dp[v])
    {
      if (w > cw)
        dp[u][w] += val;
    }
  }
}

void dfs2(int u, int p)
{
  for (auto &[cw, val] : dp[u])
    ans += val;
  for (auto &[v, w] : adjl[u])
  {
    if (v == p)
      continue;
    map<int, long long> save = dp[u];
    for (auto &[cw, val] : dp[v])
    {
      if (w > cw)
        dp[u][w] -= val;
    }
    for (auto &[cw, val] : dp[v])
    {
      if (w < cw)
        val += dp[u][w];
    }
    dfs2(v, u);
    dp[u] = save;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    adjl[u].emplace_back(v, w);
    adjl[v].emplace_back(u, w);
  }
  dfs1(1, 0);
  ans = 0;
  dfs2(1, 0);
  cout << ans << '\n';
  return 0;
}