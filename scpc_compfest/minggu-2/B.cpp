#include <bits/stdc++.h>
using namespace std;

const int maxw = 1e9+4, logw = log2(maxw) + 1;

bool on(int a, int b){
	return (a&(1<<b)) > 0;
}

void bfs(vector<vector<pair<int, int>>> &adjl, vector<vector<bool>> &vis, vector<int> &cnt, int &i, int s){
	queue<pair<int, bool>> q;
	q.emplace(s, 0);
	while (!q.empty()){
		int u = q.front().first; bool p = q.front().second;
		q.pop();
		if (vis[u][p]) continue;
		vis[u][p] = 1;
		cnt[p]++;
		for (auto per : adjl[u]){
			int v = per.first, w = per.second;
			q.emplace(v, p^on(w, i));
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adjl(n+1);
	for (int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adjl[u].emplace_back(v, w);
		adjl[v].emplace_back(u, w);
	}
	long long ans = 0;
	for (int i=0; i<logw; i++){
		vector<vector<bool>> vis(n+1, vector<bool>(2, 0));
		long long mul = 0;
		for (int u=1; u<=n; u++){
			if (vis[u][0] | vis[u][1]) continue;
			vector<int> cnt(2, 0);
			bfs(adjl, vis, cnt, i, u);
			if (vis[u][0] && vis[u][1]) mul += 1LL * cnt[0] * (cnt[0] - 1) / 2;
			else mul += 1LL * cnt[0] * cnt[1];
		}
		// cout << i << ' ' << mul << '\n';
		ans += mul * (1LL << i);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	while (tcs--){
		solve();
	}
	return 0;
}

