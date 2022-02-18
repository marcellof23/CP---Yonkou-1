#include <bits/stdc++.h>
using namespace std;

const int maxnm = 404;
int tcs;
long long a[maxnm][maxnm];
long long pr[maxnm][maxnm];


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	for (int tc=1; tc<=tcs; tc++){
		solve(tc);
	}
	return 0;
}