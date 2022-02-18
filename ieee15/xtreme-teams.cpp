#include <bits/stdc++.h>
using namespace std;

int inv(int a, int m){
	return (~a) & ((1 << m) - 1);
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	vector<int> cnt(1<<m, 0);
	for (int i=0; i<n; i++){
		string s;
		cin >> s;
		for (int j=0; j<m; j++){
			if (s[j] == 'y') a[i] += (1<<j);
		}
		cnt[a[i]]++;
	}
	// precompute superset sum
	vector<long long> sup_sum(1<<m, 0);
	for(int i=0; i<(1<<m); i++){
		sup_sum[inv(i, m)] = cnt[i];
	}
	for(int i=0; i<m; i++){
		for(int mask=0; mask<(1<<m); mask++){
			if(mask & (1<<i)){
				sup_sum[mask] += sup_sum[mask^(1<<i)];
			}
		}
	}
	long long ans = 0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			int o = (a[i] | a[j]);
			long long add = sup_sum[o];
			if ((inv(a[i], m) & o) == inv(a[i], m)) add--;
			if ((inv(a[j], m) & o) == inv(a[j], m)) add--;
			ans += add;
		}
	}
	cout << ans/3 << '\n';
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

/*
1
3 1
y
y
y
*/