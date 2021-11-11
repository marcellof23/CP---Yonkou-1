#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5 + 5;

vector<pair<int, pair<int, pair<int, int>>>> v;

const int INF = 1000000000;
vector<pair<int, int>> adj[maxN];

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
  int n = adj.size();
  d.assign(n, INF);
  p.assign(n, -1);

  d[s] = 0;
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty())
  {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : adj[v])
    {
      int to = edge.first;
      int len = edge.second;

      if (d[v] + len < d[to])
      {
        d[to] = d[v] + len;
        p[to] = v;
        q.push({d[to], to});
      }
    }
  }
}

int main()
{
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int A, B, P, T;
    cin >> A >> B >> P >> T;
    pair<int, int> p1 = {P, T};
    pair<int, pair<int, int>> p2 = {B, p1};
    pair<int, pair<int, pair<int, int>>> p3 = {A, p2};
    v.push_back(p3);
  }
  sort(v.begin(), v.end());

  int i = 1;
  pair<int, int> curr = {v[0].first, v[0].second.first};
  while (i < M)
  {
    while (v[i].first == curr.first && v[i].second.first == curr.second)
    {
      i++;
    }
    i++;
  }
}