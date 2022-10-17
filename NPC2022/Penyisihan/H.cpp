#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
long long t, n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
        cin >> n;
        cout << (n*(n-2) + 2) % mod << "\n";
	}
	return 0;
}
