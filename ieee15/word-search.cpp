#include <bits/stdc++.h>
using namespace std;

int n, m, q;
string grid[103];

const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int r, int c){
	return (r >= 0 && c >= 0 && r < n && c < m);
}

void cek(string s){
	int l = s.length();
	for (int r1=0; r1<n; r1++){
		for (int c1=0; c1<m; c1++){
			for (int d=0; d<8; d++){
				int i, r2 = r1, c2 = c1;
				for (i=0; i<l; i++){
					if (!valid(r2, c2) || grid[r2][c2] != s[i]) break;
					r2 += dr[d];
					c2 += dc[d];
				}
				if (i == l){
					cout << r1 << ' ' << c1 << ' ' << r2 - dr[d] << ' ' << c2 - dc[d] << '\n';
					return;
				}
			}
		}
	}
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	for (int i=0; i<n; i++) cin >> grid[i];
	while (q--){
		string s;
		cin >> s;
		cek(s);
	}
	return 0;
}