#include <bits/stdc++.h>
using namespace std;


int main(){
	long long n;
	cin >> n;
	long long a[n], b[n], dpa[n][2], dpb[n][2];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		cin >> b[i];
	}
	dpa[0][0] = a[0];
	dpa[0][1] = b[0]+a[0];
	dpb[0][0] = 0;
	dpb[0][1] = b[0];
	for(int i=1; i<n; i++){
		dpb[i][0] = dpb[i-1][1];
		dpb[i][1] = min(dpb[i-1][0], dpb[i-1][1]) + b[i];
		dpa[i][0] = dpa[i-1][1] + a[i];
		dpa[i][1] = max(dpb[i][1], dpa[i-1][1]) + a[i];
	}
	cout << dpa[n-1][1] << endl;
	return 0;
}