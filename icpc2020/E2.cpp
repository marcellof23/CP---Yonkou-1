#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+6;
int n;
bool a[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for (int i=1; i<n; i++) cin >> a[i];
	a[0] = 0;
	if (a[n-1]){
		int prev0 = -1, maxdist0 = 0;
		for (int i=0; i<n; i++){
			if (!a[i]){
				if (prev0!=-1) maxdist0 = max(maxdist0, i-prev0);
				if (prev0==-1) prev0 = i;
			}
		}
		if (maxdist0 > 1){
			cout << 2 << "\n";
			return 0;
		}
	}
	a[0] = 1;
	for (int i=n-1; i>0; i--){
		if (a[i]){
			cout << n-i << "\n";
			return 0;
		}
	}
	cout << n-1 << "\n";
	return 0;
}