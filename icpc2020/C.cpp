#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+6;
int n;
vector<pair<int,long long>>adjl[maxn];
long long dp[maxn][2]; // 0 gak ambil parent, 1 ambil parent

void dfs(int u, int par){
	dp[u][0] = dp[u][1] = 0;
	if (adjl[u].size()%2==1){
		for (auto p : adjl[u]){
			if (p.first == par) continue;
			dfs(p.first,u);
			dp[u][1] += max(dp[p.first][0],dp[p.first][1]+p.second);
		}
		long long mxdiff = -1e18;
		for (auto p : adjl[u]){
			if (p.first == par) continue;
			dfs(p.first,u);
			mxdiff = max(mxdiff,dp[p.first][0]-(dp[p.first][1]+p.second));
		}
		for (auto p : adjl[u]){
			if (p.first == par) continue;
			dp[u][0] += max;
		}
		dp[u][1] += mxdiff;
	}
	else{
		// 1. pasangin semua anak
		for (auto p : adjl[u]) dp[u][0] += dp[p.first][1];
		// 2. buang satu anak, pasangin ke parent
		long long mxdiff = -1e18;
		for (auto p : adjl[u]) mxdiff = max(mxdiff,dp[p.first][0]-(dp[p.first][1]+p.second));
		for (auto p : adjl[u]) dp[u][1] += dp[p.first][1];
		dp[u][1] += mxdiff;
	}
}

int main(){
	cin >> n;
	for (int i=1;i<n;i++){
		int u, v; long long w;
		cin >> u >> v >> w;
		adjl[u].emplace_back(v,w);
		adjl[v].emplace_back(u,w);
	}
	dp[1][1] = 0;
	dfs(1,1);
	cout << dp[1][0] << "\n";
}