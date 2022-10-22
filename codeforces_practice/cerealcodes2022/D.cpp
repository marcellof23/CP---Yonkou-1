#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1048576;
long long n, ans=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; ans = 0;
	for(int i=1; i<n; i++){
        ans = 1 + i*ans + (i-1)*(i-1);
	}
	cout << ans << endl;
}
