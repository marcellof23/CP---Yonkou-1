#include <bits/stdc++.h>
using namespace std;

multiset<int> ms;

void add_edge(vector<pair<int, int>> adj[],
              int src, int dest, int w)
{
  adj[src].push_back({dest, w});
  adj[dest].push_back({src, w});
}

void find_paths(vector<vector<int>> &paths,
                vector<int> &path,
                vector<int> parent[],
                int n, int u)
{
  if (u == -1)
  {
    paths.push_back(path);
    return;
  }

  for (int par : parent[u])
  {
    path.push_back(u);

    find_paths(paths, path, parent,
               n, par);

    path.pop_back();
  }
}

void bfs(vector<pair<int, int>> adj[],
         vector<int> parent[],
         int n, int start)
{
  vector<int> dist(n, INT_MAX);

  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;

  q.push({0, start});
  parent[start] = {-1};
  dist[start] = 0;

  while (!q.empty())
  {
    int vv = q.top().second;
    int dvv = q.top().first;
    q.pop();

    for (auto v : adj[vv])
    {
      if (dist[v.first] > dist[vv] + v.second)
      {

        dist[v.first] = dist[vv] + v.second;
        q.push({dist[v.first], v.first});
        parent[v.first].clear();
        parent[v.first].push_back(vv);
      }
      else if (dist[v.first] == dist[vv] + v.second)
      {
        parent[v.first].push_back(vv);
      }
    }
  }
}

void print_paths(vector<pair<int, int>> adj[],
                 int n, int start, int end)
{
  vector<vector<int>> paths;
  vector<int> path;
  vector<int> parent[n];

  bfs(adj, parent, n, start);

  find_paths(paths, path, parent, n, end);

  for (auto v : paths)
  {

    reverse(v.begin(), v.end());

    for (int u : v)
      cout << u << " ";
    cout << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, src, dest;
  cin >> n >> m >> src >> dest;
  --src, --dest;
  vector<pair<int, int>> adj[n];

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> --u >> --v >> w;
    add_edge(adj, u, v, w);
  }

  print_paths(adj, n, src, dest);

  return 0;
}