#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
long long mod_pow(long long a, long long b, long long m){
	long long ret = 1;
	for (; b; b>>=1){
		if (b&1) ret = ret * a % m;
		a = a * a % m;
	}
	return ret;
}

const long long mod[2] = {(long long)1e9+7, (long long)1e9+9}, base = 101;

vector<string> rotate90Clockwise(vector<string> s){
	int n = s.size(), m = s[0].size();
	vector<string> ret(m);
	for (int i=0; i<m; i++) ret[i].resize(n);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			ret[j][i] = s[i][m-1-j];
		}
	}
	return ret;
}

bool same(int n, int m, int p1, int r1, int c1, int p2, int r2, int c2, int k){
	vector<int> u(2), d(2), l(2), r(2);
	u[0] = r1;
	d[0] = r1+k-1;
	l[0] = c1;
	r[0] = c1+k-1;
	u[1] = r2;
	d[1] = r2+k-1;
	l[1] = c2;
	r[1] = c2+k-1;
	// cout << n << ' ' << m << '\n';
	while (p1 < 4){
		// cout << u[0] << ' ' << d[0] << ' ' << l[0] << ' ' << r[0] << '\n';
		int nu, nd, nl, nr;
		if (!(p1&1)){
			nu = m - 1 - r[0];
			nd = m - 1 - l[0];
		}
		else{
			nu = n - 1 - r[0];
			nd = n - 1 - l[0];
		}
		nl = u[0];
		nr = d[0];
		u[0] = nu;
		d[0] = nd;
		l[0] = nl;
		r[0] = nr;
		p1++;
	}
	// cout << u[0] << ' ' << d[0] << ' ' << l[0] << ' ' << r[0] << '\n';
	while (p2 < 4){
		int nu, nd, nl, nr;
		if (!(p2&1)){
			nu = m - 1 - r[1];
			nd = m - 1 - l[1];
		}
		else{
			nu = n - 1 - r[1];
			nd = n - 1 - l[1];
		}
		nl = u[1];
		nr = d[1];
		u[1] = nu;
		d[1] = nd;
		l[1] = nl;
		r[1] = nr;
		p2++;
	}
	// for (int i=0; i<2; i++) cout << u[i] << ' ' << d[i] << ' ' << l[i] << ' ' << r[i] << '\n';
	return (u[0] == u[1] && d[0] == d[1] && l[0] == l[1] && r[0] == r[1]); 
}

bool cek(vector<vector<vector<vector<long long>>>> &hash, long long mul, int p1, int r1, int c1, int p2, int r2, int c2, int k){
	// (r1,c1) (r2,c2) itu pojok kiri atas
	bool ret = true;
	for (int i=0; i<2; i++){
		long long s1 = ((hash[p1][i][r1+k-1][c1+k-1] - hash[p1][i][r1-1][c1+k-1] - hash[p1][i][r1+k-1][c1-1] + hash[p1][i][r1-1][c1-1]) % mod[i] + mod[i]) % mod[i];
		long long s2 = ((hash[p2][i][r2+k-1][c2+k-1] - hash[p2][i][r2-1][c2+k-1] - hash[p2][i][r2+k-1][c2-1] + hash[p2][i][r2-1][c2-1]) % mod[i] + mod[i]) % mod[i];
		// normalize
		s1 = s1 * mod_pow(base, r2*mul+c2, mod[i]) % mod[i];
		s2 = s2 * mod_pow(base, r1*mul+c1, mod[i]) % mod[i];
		if (s1 != s2) ret = false;
	}
	return ret;
}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);
	// cout << "yeyey\n";
	// cout << same(5, 4, 0, 2, 0, 1, 1, 2, 3) << '\n';
	// cout << same(3, 3, 0, 0, 0, 0, 1, 0, 2) << '\n';
	int n, m;
	cin >> n >> m;
	vector<vector<string>> s(4, vector<string>(n));
	for (int i=0; i<n; i++) cin >> s[0][i];
	for (int k=1; k<4; k++){
		// for (int i=0; i<n; i++){
		// 	for (int j=0; j<m; j++){
		// 		s[k][i][j] = s[k-1][j][m-1-i];
		// 	}
		// }
		s[k] = rotate90Clockwise(s[k-1]);
	}
	// for (int k=1; k<4; k++){
	// 	cout << '\n';
	// 	for (int i=0; i<s[k].size(); i++) cout << s[k][i] << '\n';
	// }
	vector<vector<vector<vector<long long>>>> hash(4, vector<vector<vector<long long>>>(2));
	for (int i=0; i<4; i++){
		for (int j=0; j<2; j++){
			hash[i][j].assign(s[i].size()+1, vector<long long>(s[i][0].size()+1, 0));
		}
	}
	long long mul = max(n, m);
	for (int l=0; l<4; l++){
		for (int k=0; k<2; k++){
			for (int i=1; i<hash[l][k].size(); i++){
				for (int j=1; j<hash[l][k][0].size(); j++){
					hash[l][k][i][j] = ((hash[l][k][i-1][j] + hash[l][k][i][j-1] - hash[l][k][i-1][j-1] + mod_pow(base, i*mul+j, mod[k]) * s[l][i-1][j-1]) % mod[k] + mod[k]) % mod[k];
				}
			}
		}
	}
	int l = 1, r = min(n, m), ans = min(n, m) + 1;
	while (l <= r){
		int k = (l+r)/2;
		bool ada = false;
		// cout << k << '\n';
		for (int i=0; i<4; i++){
			for (int r1=1; r1+k-1<hash[i][0].size(); r1++){
				for (int c1=1; c1+k-1<hash[i][0][0].size(); c1++){
					for (int j=0; j<4; j++){
						for (int r2=1; r2+k-1<hash[j][0].size(); r2++){
							for (int c2=1; c2+k-1<hash[j][0][0].size(); c2++){
								if (same(n, m, i, r1-1, c1-1, j, r2-1, c2-1, k)) continue;
								if (cek(hash, mul, i, r1, c1, j, r2, c2, k)){
									ada = true;
									// cout << i << ' ' << r1-1 << ' ' << c1-1 << ' ' << j << ' ' << r2-1 << ' ' << c2-1 << '\n';
								}
							}
						}
					}
				}
			}
		}
		// cout << k << ' ' << ada << '\n';
		if (ada) l = k+1;
		else{
			ans = k;
			r = k-1;
		}
	}
	cout << ans << '\n';
	return 0;
}

/*
....
....
XXX.
XXX.
XXX.

.....
..XXX
..XXX
..XXX
*/
=======