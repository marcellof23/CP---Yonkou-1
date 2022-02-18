#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector<int> tree[4 * MAXN], trees[4 * MAXN];
bool centroidMarked[4 * MAXN];

int best;
int node;

void DFS(int src, bool visited[], int subtree_size[], int *n)
{
  visited[src] = true;
  *n += 1;
  subtree_size[src] = 1;

  vector<int>::iterator it;

  for (it = tree[src].begin(); it != tree[src].end(); it++)
    if (!visited[*it] && !centroidMarked[*it])
    {
      DFS(*it, visited, subtree_size, n);
      subtree_size[src] += subtree_size[*it];
    }
}

int getCentroid(int src, bool visited[], int subtree_size[], int n)
{
  bool is_centroid = true;

  visited[src] = true;

  int heaviest_child = 0;

  vector<int>::iterator it;

  for (it = tree[src].begin(); it != tree[src].end(); it++)
    if (!visited[*it] && !centroidMarked[*it])
    {
      if (subtree_size[*it] > n / 2)
        is_centroid = false;

      if (heaviest_child == 0 ||
          subtree_size[*it] > subtree_size[heaviest_child])
        heaviest_child = *it;
    }
  if (is_centroid && n - subtree_size[src] <= n / 2)
    return src;
  return getCentroid(heaviest_child, visited, subtree_size, n);
}

int getCentroid(int src)
{
  bool visited[MAXN];

  int subtree_size[MAXN];

  memset(visited, false, sizeof visited);
  memset(subtree_size, 0, sizeof subtree_size);

  int n = 0;

  DFS(src, visited, subtree_size, &n);

  for (int i = 1; i < MAXN; i++)
    visited[i] = false;

  int centroid = getCentroid(src, visited, subtree_size, n);

  centroidMarked[centroid] = true;

  return centroid;
}

int dfs(int v, bool *visited, vector<int> graph[], int c = 0)
{
  visited[v] = true;
  int ans = 0;
  for (int i = 0; i < graph[v].size(); i++)
  {
    if (!visited[graph[v][i]])
      ans = max(ans, dfs(graph[v][i], visited, graph, c + 1));
  }
  if (c > best)
  {
    best = c;
    node = v;
  }
  visited[v] = false;
  return max(c, ans);
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    int cent1;

    for (auto &v : trees)
    {
      v.clear();
    }

    for (auto &v : tree)
    {
      v.clear();
    }

    memset(centroidMarked, false, sizeof(centroidMarked));

    for (int i = 0; i < n - 1; i++)
    {
      int u, v;
      cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
      trees[u].push_back(v);
      trees[v].push_back(u);
    }

    cent1 = getCentroid(1);

    for (auto &v : tree)
    {
      v.clear();
    }

    memset(centroidMarked, false, sizeof(centroidMarked));

    int m;
    cin >> m;
    int cent2;
    for (int i = 0; i < m - 1; i++)
    {
      int u, v;
      cin >> u >> v;
      tree[u + n].push_back(v + n);
      tree[v + n].push_back(u + n);
      trees[u + n].push_back(v + n);
      trees[v + n].push_back(u + n);
    }

    cent2 = getCentroid(n + 1);

    trees[cent1].push_back(cent2);
    trees[cent2].push_back(cent1);

    bool *visited = new bool[n + m + 1]();
    best = 0;
    node = 1;
    dfs(1, visited, trees);
    bool *visited2 = new bool[n + m + 1]();
    cout << dfs(node, visited2, trees) << endl;
    cout << cent1 << " " << cent2 - n << endl;
  }
}