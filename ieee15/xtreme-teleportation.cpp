#include <bits/stdc++.h>
using namespace std;

// nyampah 50

const int maxn = 1003, logn = log2(maxn) + 1;
int n, q;
vector<pair<int, long long>> adjl[maxn], adjl2[maxn];
vector<pair<long long, pair<int, int>>> edgl;
int par[maxn], sez[maxn];
int depth[maxn], anc[maxn][logn];
long long mn[maxn][logn];

int find(int x){
	while (x != par[x]) x = par[x];
	return x;
}

void unite(int u, int v){
	u = find(u); v = find(v);
	if (sez[u] > sez[v]) swap(u, v);
	par[u] = v;
	sez[v] += u;
}

void dfs(int u, int p, int d, long long c){
	depth[u] = d;
	anc[u][0] = p;
	mn[u][0] = c;
	for (int i=1; i<logn; i++){
		anc[u][i] = anc[anc[u][i-1]][i-1];
		mn[u][i] = min(mn[u][i-1], mn[anc[u][i-1]][i-1]);
	}
	for (auto per : adjl2[u]){
		int v = per.first; long long nc = per.second;
		if (v == p) continue;
		dfs(v, u, d+1, nc);
	}
}

long long binlift(int u, int v){
	long long ret = 1e18;
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for (int i=0; i<logn; i++){
		if (diff & (1<<i)){
			ret = min(ret, mn[u][i]);
			u = anc[u][i];
		}
	}
	if (u == v) return ret;
	for (int i=logn-1; i>=0; i--){
		if (anc[u][i] != anc[v][i]){
			ret = min(ret, mn[u][i]);
			ret = min(ret, mn[v][i]);
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	ret = min(ret, mn[u][0]);
	ret = min(ret, mn[v][0]);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; i++){
		int a, b; long long c;
		cin >> a >> b >> c;
		adjl[a].emplace_back(b, c);
		adjl[b].emplace_back(a, c);
	}
	for (int i=1; i<=n; i++){
		queue<pair<pair<int, int>, long long>> q;
		q.push({{i, 0}, 0});
		while (!q.empty()){
			int u = q.front().first.first, p = q.front().first.second;
			long long d = q.front().second;
			q.pop();
			edgl.push_back({d, {i, u}});
			for (auto per : adjl[u]){
				int v = per.first; long long c = per.second;
				if (v == p) continue;
				q.push({{v, u}, d + c});
			}
		}
	}
	sort(edgl.rbegin(), edgl.rend());
	for (int i=1; i<=n; i++){
		par[i] = i;
		sez[i] = 1;
	}
	for (auto &e : edgl){
		int u = e.second.first, v = e.second.second;
		if (find(u) != find(v)){
			adjl2[u].emplace_back(v, e.first);
			adjl2[v].emplace_back(u, e.first);
			unite(u, v);
		}
	}
	for (int i=0; i<maxn; i++){
		for (int j=0; j<logn; j++){
			mn[i][j] = 1e18+3;
		}
	}
	dfs(1, 0, 0, 0); // init lca adjl2
	while (q--){
		int u, v;
		cin >> u >> v;
		cout << binlift(u, v) << '\n';
	}
	return 0;
}