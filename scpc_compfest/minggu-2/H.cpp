#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4;
int n, k;
long long a[maxn], d[maxn], ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> d[i];
	ans = 0;
	if (k == 0){
		long long suf = 0;
		for (int i=n-1; i>=0; i--){
			suf += a[i];
			ans = max(ans, suf - d[i]);
		}
	}
	else if (k == 1){
		vector<long long> suf(n+1, 0);
		vector<long long> best(n+1, 0);
		for (int i=n-1; i>=0; i--){
			suf[i] = suf[i+1] + a[i];
			best[i] = max(best[i+1], suf[i] - d[i]);
		}
		long long mn = 1e18, pref = 0;
		for (int i=0; i+1<n; i++){
			pref += a[i];
			mn = min(mn, d[i]);
			ans = max(ans, max(0LL, pref - mn) + max(0LL, best[i+1]));
		}
		long long tmp = suf[0] - d[0];
		sort(a, a+n-1);
		ans = max(ans, tmp - a[0]);
	}
	else{
		ans = max(ans, a[n-1] - d[n-1]);
		sort(d, d+n-1);
		long long sum = 0;
		for (int i=0; i<n; i++) sum += a[i];
		ans = max(ans, sum - d[0]);
	}
	cout << ans << '\n';
	return 0;
}