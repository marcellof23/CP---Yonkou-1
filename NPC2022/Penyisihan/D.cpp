#include <bits/stdc++.h>
using namespace std;

int t;
long long n, ans, pw;
long long sisa, pw10[19];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw10[0] = 1;
	for(int i=1; i<19; i++){
        pw10[i] = 10 * pw10[i-1];
	}
	cin >> t;
	while(t--){
        cin >> n; n++;
        ans = max((n-16)/3, 0ll);
        pw = n - 3*ans;
        ans *= 10;

        sisa = (pw10[pw] - (9*n+1))/27;
        while(sisa > 0){
            ans += sisa%10;
            sisa /= 10;
        }
        cout << ans << '\n';
	}
	return 0;
}
