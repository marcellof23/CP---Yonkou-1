#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int n;
vector<int> adj[maxn];
vector<int> adj2[maxn];
int subtree_size[maxn];

vector<int> visited;
vector<int> depth;
void dfs(int u)
{
  visited[u] = 1;
  for (auto i : adj[u])
  {
    if (visited[i] == 0)
    {
      depth[i] = max(depth[i], depth[u] + 1);
      dfs(i);
    }
  }
}

int get_subtree_size(int node, int par = -1)
{
  int &res = subtree_size[node];
  res = 1;
  for (int i : adj[node])
  {
    if (i == par)
      continue;
    res += get_subtree_size(i, node);
  }
  return res;
}

int get_centroid(int node, int par = -1)
{
  for (int i : adj[node])
  {
    if (i == par)
      continue;

    if (subtree_size[i] * 2 > n)
    {
      return get_centroid(i, node);
    }
  }
  return node;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    for (auto &v : adj)
    {
      v.clear();
    }
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    visited.assign(n, 0);
    depth.assign(n, 0);

    dfs(0);
    sort(depth.begin(), depth.end());
    int dep1 = depth[depth.size() - 1] - 1;

    get_subtree_size(0);
    int cent1 = get_centroid(0) + 1;

    for (auto &v : adj)
    {
      v.clear();
    }

    int m;
    cin >> m;
    n = m;
    for (int i = 0; i < m - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    visited.assign(m, 0);
    depth.assign(m, 0);

    dfs(0);
    sort(depth.begin(), depth.end());
    int dep2 = depth[depth.size() - 1] - 1;

    get_subtree_size(0);
    int cent2 = get_centroid(0) + 1;

    cout << dep1 + dep2 + 1 << endl;
    cout << cent1 << " " << cent2 << endl;
  }
}
