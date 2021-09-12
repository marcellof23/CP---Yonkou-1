#include <bits/stdc++.h>
using namespace std;

/**
 * Author: Simon Lindholm
 * Date: 2015-02-24
 * License: CC0
 * Source: Wikipedia, tinyKACTL
 * Description: Push-relabel using the highest label selection rule and the gap heuristic. Quite fast in practice.
 *  To obtain the actual flow, look at positive values only.
 * Time: $O(V^2\sqrt E)$
 * Status: Tested on Kattis and SPOJ, and stress-tested
 */
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

const int INF = 1e9+4;
const int maxn = 1e5+4, maxe = 102;
int n;
int v[maxn];
int cnt[2][maxe];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> v[i];
	memset(cnt, 0, sizeof cnt);
	for (int i=0; i<n; i++){
		int e;
		cin >> e;
		cnt[v[i]][e]++;
	}
	PushRelabel mf(404);
	// source = 0, sink = 401
	// pasang edge dari source ke v = 0
	for (int i=1; i<=100; i++) mf.addEdge(0, i, INF);
	// pasang edge internal v = 0
	for (int i=1; i<=100; i++) mf.addEdge(i, i+100, cnt[0][i]);
	// pasang edge antara v = 0 dan v = 1
	for (int i=1; i<=100; i++){
		for (int j=1; j<=100; j++){
			if (__gcd(i, j) > 1) mf.addEdge(100+i, 200+j, INF);
		}
	}
	// pasang edge internal v = 1
	for (int i=1; i<=100; i++) mf.addEdge(i+200, i+300, cnt[1][i]);
	// pasang edge dari v = 1 ke sink
	for (int i=301; i<=400; i++) mf.addEdge(i, 401, INF);
	cout << mf.calc(0, 401) << '\n';
	return 0;
}