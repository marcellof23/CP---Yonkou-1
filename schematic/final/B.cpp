#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long mod_mul(long long a, long long b){
    return 1LL * a * b % mod;
}
long long mod_pow(long long a, long long b){
    int ret = 1;
    for (; b; b>>=1){
        if (b&1) ret = mod_mul(ret, a);
        a = mod_mul(a, a);
    }
    return ret;
}
long long mod_inv(long long a){
    return mod_pow(a, mod-2);
}
long long mod_abs(long long x){
    return ((x%mod)+mod)%mod;
}

vector<vector<long long> > iden = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
};
void init_

vector<vector<long long> > mat_mul(vector<vector<long long>> a, vector<vector<long long>> b){
	int n = a.size(), m = b[0].size(), o = a[0].size();
	vector<vector<long long>> ret(n, vector<long long>(m, 0));
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			for (int k=0; k<o; k++){
				ret[i][j] += mod_mul(a[i][k], b[k][j]);
				ret[i][j] %= mod;
			}
		}
	}
	return ret;
}

vector<vector<long long>> mat_pow(vector<vector<long long>> a, long long b){
	vector<vector<long long>> ret = iden;
	for (; b; b>>=1){
		if (b&1) ret = mat_mul(ret, a);
		a = mat_mul(a, a);
	}
	return ret;
}

long long sigma[5000];

void calc_sigma(){
    sigma[1100] = mod_abs(sigma[1000]*sigma[1000] - sigma[2000]);
    sigma[1100] = sigma[1100]*mod_inv(2)%mod;
    //cout << sigma[1100] << endl;
    sigma[2100] = mod_abs(sigma[2000]*sigma[1000] - sigma[3000]);
    //cout << sigma[2100] << endl;
    sigma[1110] = mod_abs(sigma[1000]*sigma[1100] - sigma[2100]);
    sigma[1110] = sigma[1110]*mod_inv(3)%mod;
    //cout << sigma[1110] << endl;
    sigma[3100] = mod_abs(sigma[3000]*sigma[1000] - sigma[4000]);
    //cout << sigma[3100] << endl;
    sigma[2110] = mod_abs(sigma[2000]*sigma[1100] - sigma[3100]);
    //cout << sigma[2110] << endl;
    sigma[1111] = mod_abs(sigma[1000]*sigma[1110] - sigma[2110]);
    //cout << sigma[1111] << endl;
}

vector<vector<long long> > matrixawal;
vector<long long> row;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> sigma[1000] >> sigma[2000] >> sigma[3000] >> sigma[4000];
    sigma[1000] = mod_abs(sigma[1000]);
    sigma[2000] = mod_abs(sigma[2000]);
    sigma[3000] = mod_abs(sigma[3000]);
    sigma[4000] = mod_abs(sigma[4000]);
    calc_sigma();


    row.clear();
    row.push_back(sigma[1000]);
    row.push_back(mod_abs(-sigma[1100]));
    row.push_back(sigma[1110]);
    row.push_back(mod_abs(-sigma[1111]));
    matrixawal.push_back(row);
    row.clear();
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    matrixawal.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    matrixawal.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    row.push_back(0);

    int tcs;
    cin >> tcs;
    while (tcs--){
    	cout << tcs << '\n';
    	long long n;
    	cin >> n;
    	long long ans;
    	if (n <= 4) ans = sigma[n*1000];
    	else{
    		vector<vector<long long>> res = mat_pow(matrixawal, n-4);
    		vector<vector<long long>> mul = {
    			{sigma[4000]},
    			{sigma[3000]},
    			{sigma[2000]},
    			{sigma[1000]}
    		};
    		vector<vector<long long>> res2 = mat_mul(res, mul);
    		ans = res2[0][0];
    	}
    	cout << "a^" << n << " + b^" << n << " + c^" << n << " + d^" << n << " = " << ans << '\n';
    }
}
