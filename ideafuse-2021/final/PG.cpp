#include <bits/stdc++.h>
using namespace std;

bool coba(int n, vector<vector<int>> &pref, int d){
	for (char c='A'; c<='Z'; c++){
		for (int i=d; i<=n; i+=d){
			if ((pref[c-'A'][i] - pref[c-'A'][i-d]) != pref[c-'A'][d]){
				// cout << c << " (" << i-d+1 << "," << i << ")\n"; 
				return false;
			}
		}
	}
	return true;
}

void solve(){
	int n; string s;
	cin >> n >> s;
	vector<vector<int>> pref(26, vector<int>(n+1, 0));
	for (char c='A'; c<='Z'; c++){
		for (int j=1; j<=n; j++) pref[c-'A'][j] = pref[c-'A'][j-1] + (s[j-1] == c);
	}
	// for (char c='A'; c<='Z'; c++){
	// 	for (int j=1; j<=n; j++){
	// 		cout << pref[c-'A'][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	int ans = 0;
	for (int d=1; d*d<=n; d++){
		if (n%d == 0){
			if (coba(n, pref, d)) ans = max(ans, n/d);
			if (coba(n, pref, n/d)) ans = max(ans, d);
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		cout << "CASE #" << tc << ": ";
		solve();
	}
	return 0;
}