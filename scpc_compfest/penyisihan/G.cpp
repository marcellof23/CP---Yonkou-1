#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4, maxm = 1e5+4;
int n, m;
pair<int, int> edges[maxm];
map<int, vector<int>> edge_no[maxn];
vector<int> adjl[maxn];
bool vis[maxn];

int dfs1(int u){
	// cout << u << '\n';
	int ret = 0;
	vis[u] = 1;
	for (int v : adjl[u]){
		if (vis[v]) ret += edge_no[u][v].size();
		else ret += dfs1(v);
	}
	return ret;
}

void dfs2(vector<int> &ans, int u){
	vis[u] = 1;
	for (int v : adjl[u]){
		if (vis[v]){
			for (int x : edge_no[u][v]) ans.emplace_back(x);
		}
		else dfs2(ans, v);
	}
}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		edge_no[u][v].push_back(i+1);
	}
	for (int i=1; i<=n; i++){
		for (auto &p : edge_no[i]) adjl[i].push_back(p.first);
	}
	// random dfs lesgo

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	while (1){
		int s = rng()%n+1;
		// cout << s << '\n';
		for (int i=1; i<=n; i++) shuffle(adjl[i].begin(), adjl[i].end(), rng);
		memset(vis, 0, sizeof vis);
		int cost = dfs1(s);
		if (cost <= m/2){
			vector<int> ans;
			memset(vis, 0, sizeof vis);
			dfs2(ans, s);
			// cout << "yt\n";
			sort(ans.begin(), ans.end());
			cout << ans.size() << '\n';
			for (int u : ans) cout << u << '\n';
			return 0;
		}
	}
	return 0;
}

/*
2 7
1 2
1 2
1 2
1 2
2 1
2 1
2 1

3 8
2 3
2 3
2 1
2 1
1 2
1 2
3 2
3 2
*/