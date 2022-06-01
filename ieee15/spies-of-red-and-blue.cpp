#include <bits/stdc++.h>
using namespace std;

const int maxx = 1e9+69;

void solve(){
	int nr, nb, e;
	cin >> nr >> nb >> e;
	int n = nr + nb;
	vector<int> par(n); // 0 root r, 1 root b
	for (int i=1; i<nr; i++){
		string s;
		cin >> s;
		int id = stoi(s.substr(1, s.length()-1));
		if (s[0] == 'R') par[i] = (id-1);
		else par[i] = (nr+id-1);
	}
	for (int i=1; i<nb; i++){
		string s;
		cin >> s;
		int id = stoi(s.substr(1, s.length()-1));
		if (s[0] == 'R') par[nr+i] = (id-1);
		else par[nr+i] = (nr+id-1);
	}
	while (e--){
		char type;
		cin >> type;
		if (type == 'c'){
			string x, y;
			cin >> x >> y;
			int idx = stoi(x.substr(1, x.length()-1)), idy = stoi(y.substr(1, y.length()-1));
			int ux = idx-1 + (x[0] == 'R' ? 0 : nr), uy = idy-1 + (y[0] == 'R' ? 0 : nr);
			par[ux] = uy;
		}
		else{
			string x, y;
			cin >> x >> y;
			int idx = stoi(x.substr(1, x.length()-1)), idy = stoi(y.substr(1, y.length()-1));
			int ux = idx-1 + (x[0] == 'R' ? 0 : nr), uy = idy-1 + (y[0] == 'R' ? 0 : nr);
			int dx = 0, dy = 0;
			vector<bool> vis;
			vis.assign(n, false);
			while (ux != 0 && ux != nr){
				if (vis[ux]) break;
				vis[ux] = true;
				ux = par[ux];
				dx++;
			}
			vis.assign(n, false);
			while (uy != 0 && uy != nr){
				if (vis[uy]) break;
				vis[uy] = true;
				uy = par[uy];
				dy++;
			}
			int dr = maxx, db = maxx;
			if (ux == 0) dr = min(dr, dx);
			if (ux == nr) db = min(db, dx);
			if (uy == 0) dr = min(dr, dy);
			if (uy == nr) db = min(db, dy);

			if (dr == maxx && db == maxx) cout << "NONE\n";
			else if (dr == db) cout << "TIE " << dr << '\n';
			else if (dr < db) cout << "RED " << dr << '\n';
			else cout << "BLUE " << db << '\n';
		}
	}
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