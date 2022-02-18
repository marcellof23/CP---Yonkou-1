#include <bits/stdc++.h>
using namespace std;

// WA, code AC nya ada di TLX

const int maxx = 1e9+3;
const int maxn = 4003, maxq = 3e5+3;
long long wx, wy, wr;
long long n;
pair<pair<long long, long long>, pair<long long, long long>> cranes[maxn];// m r x y
long long q;
pair<pair<long long, long long>, pair<long long, long long>> items[maxq]; // m i x y
vector<long long> adjl[maxn];
long long dist[maxn];
long long ans[maxq];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> cranes[0].second.first >> cranes[0].second.second >> cranes[0].first.second;
	cranes[0].first.first = -1e9;
	cin >> n;
	assert(n <= 100000);
	for (long long i=1; i<=n; i++){
		cin >> cranes[i].second.first >> cranes[i].second.second >> cranes[i].first.second >> cranes[i].first.first;
		cranes[i].first.first *= -1; 
	}
	cin >> q;
	assert(q <= 2000);
	for (long long i=0; i<q; i++){
		cin >> items[i].second.first >> items[i].second.second >> items[i].first.first;
		items[i].first.second = i;
		items[i].first.first *= -1;
	}
	sort(cranes, cranes+n+1);
	sort(items, items+q);
	// memset(ans, -1, sizeof ans);
	for (int i=0; i<q; i++) ans[i] = maxx;
	long long ci = 0;
	for (long long cl=0; cl<=n; ){
		long long cr = cl;
		while (cr <= n && cranes[cr].first.first == cranes[cl].first.first) cr++;
		for (long long i=cl; i<cr; i++){
			for (long long j=0; j<=i; j++){
				long long dx = cranes[i].second.first - cranes[j].second.first;
				long long dy = cranes[i].second.second - cranes[j].second.second;
				long long d = dx*dx + dy*dy;
				long long rsum = cranes[i].first.second + cranes[j].first.second;
				if (d <= rsum*rsum){
					adjl[i].push_back(j);
					adjl[j].push_back(i);
				}
			}
		}
		// bfs
		// memset(dist, -1, sizeof dist);
		for (long long i=0; i<cr; i++) dist[i] = maxx;
		dist[0] = 1;
		queue<long long> qu;
		qu.push(0);
		while (!qu.empty()){
			long long u = qu.front();
			qu.pop();
			for (long long v : adjl[u]){
				if (dist[v] != maxx) continue;
				dist[v] = dist[u] + 1;
				qu.push(v);
			}
		}
		while (ci < q && (cr > n || -cranes[cr].first.first < -items[ci].first.first)){
			long long qi = items[ci].first.second;
			for (long long i=0; i<cr; i++){
				long long dx = cranes[i].second.first - items[ci].second.first;
				long long dy = cranes[i].second.second - items[ci].second.second;
				long long d = dx*dx + dy*dy;
				long long rsum = cranes[i].first.second;
				if (d <= rsum*rsum) ans[qi] = min(ans[qi], dist[i]);
			}
			ci++;
		}
		cl = cr;
	}
	for (long long i=0; i<q; i++) cout << (ans[i] == maxx ? -1 : ans[i]) << '\n';
	return 0;
}

/*
30 13 4
6
4 9 3 10
8 13 3 5
16 9 7 10
24 14 3 2
25 5 4 15
30 7 2 5
4
14 7 1
3 7 16
3 7 4
32 13 100

0 0 10
3
0 0 10 10
0 0 10 10
0 0 10 10
1
0 10 1

0 0 1
1
0 0 1000000 1000
1
0 1 1
*/