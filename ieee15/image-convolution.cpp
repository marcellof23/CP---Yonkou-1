#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n1, m1;
	cin >> n1 >> m1;
	vector<string> s1(n1);
	for (int i=0; i<n1; i++) cin >> s1[i];
	int n2, m2;
	cin >> n2 >> m2;
	vector<string> s2(n2);
	for (int i=0; i<n2; i++) cin >> s2[i];
	int ans = 0;
	for (int r1=0; r1+n2-1<n1; r1++){
		for (int c1=0; c1+m2-1<m1; c1++){
			bool ok = true;
			for (int r2=0; r2<n2; r2++){
				for (int c2=0; c2<m2; c2++){
					if (s2[r2][c2] != '?' && s2[r2][c2] != s1[r1+r2][c1+c2]) ok = false;
				}
			}
			if (ok) ans ++;
		}
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