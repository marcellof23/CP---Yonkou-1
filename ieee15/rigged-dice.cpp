#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> cnt6(2, 0);
	vector<int> sum(2, 0); // 0 alice, 1 bob
	int dice_num = 0;
	for (int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		sum[0] += a;
		sum[1] += b;
		cnt6[dice_num] += (a == 6);
		cnt6[dice_num^1] += (b == 6);
		if (sum[0] != sum[1]) dice_num ^= 1;
	}
	cout << (cnt6[0] > cnt6[1] ? '1' : '2') << '\n';
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