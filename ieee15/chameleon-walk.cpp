#include <bits/stdc++.h>
using namespace std;

bool relax_check(int n, long long k, vector<vector<pair<int, pair<long long, char>>>> &adjl){
	vector<long long> dist(n+1, 1e18);
	dist[1] = 0;
	vector<bool> vis(n+1, false);
	priority_queue<pair<long long, int>> pq;
	pq.emplace(-dist[1], 1);
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e : adjl[u]){
			if (e.second.second != 'a') continue;
			int v = e.first; long long c = e.second.first;
			if (dist[u] + c < dist[v]){
				dist[v] = dist[u] + c;
				pq.emplace(-dist[v], v);
			}
		}
	}
	return dist[n] <= k;
}

bool check(int n, long long k, vector<vector<pair<int, pair<long long, char>>>> &adjl, long long mid){
	vector<vector<long long>> dist(n+1, vector<long long>(5, 1e18));
	dist[1][0] = 0;
	vector<vector<bool>> vis(n+1, vector<bool>(5, false));
	priority_queue<pair<long long, pair<int, char>>> pq;
	pq.push({-dist[1][0], {1, 'a'}});
	while (!pq.empty()){
		int u = pq.top().second.first; char c = pq.top().second.second;
		pq.pop();
		if (vis[u][c-'a']) continue;
		vis[u][c-'a'] = 1;
		for (auto e : adjl[u]){
			int v = e.first; long long d = e.second.first; char nc = e.second.second;
			if (nc != c) d += mid;
			if (dist[u][c-'a'] + d < dist[v][nc-'a']){
				dist[v][nc-'a'] = dist[u][c-'a'] + d;
				pq.push({-dist[v][nc-'a'], {v, nc}});
			}
		}
	}
	long long mn = 1e18;
	for (int i=0; i<5; i++) mn = min(mn, dist[n][i]);
	return mn <= k;
}

void solve(){
	int n, m; long long k;
	cin >> n >> m >> k;
	vector<vector<pair<int, pair<long long, char>>>> adjl(n+1);
	for (int i=0; i<m; i++){
		int u, v; long long d; char c;
		cin >> u >> v >> d >> c;
		adjl[u].push_back({v, {d, c}});
		adjl[v].push_back({u, {d, c}});
	}
	if (relax_check(n, k, adjl)){
		cout << "relaxing\n";
		return;
	}
	long long l = 1, r = k, ans = -1;
	while (l <= r){
		long long mid = (l+r)/2;
		if (check(n, k, adjl, mid)){
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	if (ans == -1) cout << "impossible\n";
	else cout << ans << '\n';
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