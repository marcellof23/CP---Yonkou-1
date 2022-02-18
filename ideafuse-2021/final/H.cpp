#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
int tcs;
int n, s, b, m;
string g[maxn];
bool vis[maxn][maxn][maxn][maxn];
const int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};

bool valid(int r, int c){
	return (r >= 0 && r < n && c >= 0 && c < m && g[r][c] != '*');
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		cin >> n >> s >> b >> m;
		for (int i=0; i<n; i++) cin >> g[i];
		pair<int, int> ps, pt;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (g[i][j] == 'S') ps = {i, j};
				if (g[i][j] == 'T') pt = {i, j};
			}
		}
		memset(vis, 0, sizeof vis);
		queue<pair<pair<int, int>, pair<int, int>>> q; // r, c, s, b
		q.push({ps, {s, b}});
		while (!q.empty()){
			int r = q.front().first.first, c = q.front().first.second, cs = q.front().second.first, cb = q.front().second.second;
			q.pop();
			if (vis[r][c][cs][cb]) continue;
			vis[r][c][cs][cb] = 1;
			for (int i=0; i<4; i++){
				int nr = r+dr[i], nc = c+dc[i];
				if (valid(nr, nc)){
					if (cs > 0){ // ngepedal
						int nb = ((g[nr][nc] == '1' ? min(m, cb+1) : cb));
						q.push({{nr, nc}, {cs-1, nb}});
					}
					if (cb > 0){ // vroom
						q.push({{nr, nc}, {cs, cb-1}});
					}
				}
			}
		}
		bool ans = false;
		for (int i=0; i<=maxn; i++){
			for (int j=0; j<=maxn; j++){
				if (vis[pt.first][pt.second][i][j]) ans = true;
			}
		}
		cout << "Case #" << tc << ": " << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}