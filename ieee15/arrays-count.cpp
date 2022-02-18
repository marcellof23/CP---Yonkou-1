#include <bits/stdc++.h>
using namespace std;

int ans[20][20];

bool on(int a, int i){
	return (a&(1<<i)) > 0;
}

void brute(){
	for (int n=2; n<=10; n++){
		for (int k=n+2; k<=10; k++){
			ans[n][k] = 0;
			for (int mas1=0; mas1<(1<<k); mas1++){
				for (int mas2=0; mas2<(1<<(k-1)); mas2++){
					bool has_leading_zero = false;
					for (int l=0; l<k; ){
						if (!on(mas1, l)) has_leading_zero = true;
						int r = l;
						while (r < k && on(mas2, r) == on(mas2, l)) r++;
						l = r;
					}
					if (has_leading_zero) continue;
					bool valid = false;
					for (int s=0; s<=k-n; s++){
						int mask1 = (mas1 >> s);
						int mask2 = (mas2 >> s);
						if (!on(mask1, 0)) continue;
						int res = 0;
						for (int l=0; l<k-s; ){
							int r = l;
							while (r < k-s && on(mask2, l) == on(mask2, r)) r++;
							for (int i=l; i<r; i++){
								if (on(mask1, i)) res |= (1 << (r-i-1)); 
							}
							l = r;
						}
						if (mas2 == 0){
							// cout << bitset<10>(mas1) << ' ' << bitset<10>(mas2) << ' ' << res << '\n';			
						}
						if (res == ((1 << n) - 1)) valid = true;
					}
					if (valid){
						// cout << bitset<10>(mas1) << ' ' << bitset<10>(mas2) << '\n';
						ans[n][k]++;
					}
				}
			}
			// cout << n << ' ' << k << ' ' << ans[n][k] << '\n';
			// ans[n][k] >>= 1;
		}
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	if (n > k) cout << "0\n";
	else cout << ans[n][k] % 4 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	brute();
	int tcs;
	cin >> tcs;
	while (tcs--){
		solve();
	}
	return 0;
}