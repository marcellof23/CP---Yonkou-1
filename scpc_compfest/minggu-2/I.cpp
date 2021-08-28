#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18 + 7;

vector<ll> d(105);

void dijkstra(ll s, ll n, vector<pair<ll, ll>> adj[205])
{

  d.assign(n, INF);

  d[s] = 0;
  using pii = pair<ll, ll>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty())
  {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : adj[v])
    {
      ll to = edge.first;
      ll len = edge.second;

      if (d[v] + len < d[to])
      {
        d[to] = d[v] + len;
        q.push({d[to], to});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--)
  {
    vector<pair<ll, ll>> adj[205];
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    for (int i = 0; i < M; i++)
    {
      ll u, v, w1, w2;
      cin >> u >> v >> w1 >> w2;
      --u, --v;
      ll totw = A * w1 + B * w2;
      adj[u].push_back({v, totw});
      adj[v].push_back({u, totw});
    }
    ll arriv, dest;
    cin >> arriv >> dest;
    dijkstra(arriv - 1, N, adj);

    cout << d[dest - 1] << endl;
  }
}