#include <bits/stdc++.h>
using namespace std;

void solve(){
	double n, m;
	cin >> n >> m;
	cout << fixed << setprecision(9) << m * m / n << '\n';
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