#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, maxk = 1003;
int n, k;
int dp[maxk], tmp[maxk];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		memset(tmp, 0, sizeof tmp);
		for (int j=0; j<=k; j++) tmp[j] = (dp[j] + (j >= b ? tmp[j-b] : 0)) % mod;
		for (int j=b; j<=k; j++){
			dp[j] += ((tmp[j - b] - (j - a*b - b >= 0 ? tmp[j - a*b - b] : 0)) % mod + mod) % mod;
			dp[j] %= mod;
		}
	}
	cout << dp[k] << '\n';
	return 0;
}