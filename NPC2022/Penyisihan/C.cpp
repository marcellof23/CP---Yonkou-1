#include <bits/stdc++.h>
using namespace std;

const int maxn = 1069;
bitset<maxn> ans[maxn];
set<int> st[3];

void init() {
	for (int i=0; i<maxn; i++) {
		for (int j=0; j<maxn; j++) {
			if (i == 0 && j == 0) {
				ans[0][0] = 1;
				st[0].insert(0);
				st[1].insert(0);
				st[2].insert(0);
			} else {
				if (!st[0].count(i) && !st[1].count(j) && !st[2].count(i-j)) {
					ans[i][j] = 1;
					st[0].insert(i);
					st[1].insert(j);
					st[2].insert(i-j);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
        init();
        for(int i=0; i<=50; i++){
            for(int j=0; j<=50; j++){
                cout << ans[i][j] << " ";
            }cout << endl;
        }
        int tcs;
        cin >> tcs;
	while (tcs--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		if (x == 0 && y == 0) cout << "Draw\n";
		else if (max(x-n, y-m) >= 0) cout << "Draw\n";
		else if (ans[x][y]) cout << "Eva\n";
		else cout << "Pisi\n";
	}
	return 0;
}
