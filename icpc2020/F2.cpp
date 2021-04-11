#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

pair<vector<int>,long long> countinversion(int l, int r, vector<int> &c){
	if (l==r) return {{c[l]},0};
	else{
		int mid = (l+r)/2;
		auto tmpl = countinversion(l,mid,c);
		auto tmpr = countinversion(mid+1,r,c);
		vector<int> ret1;
		long long ret2 = tmpl.second + tmpr.second;
		for (int u : tmpl.first){
			ret2 += upper_bound(tmpr.first.begin(),tmpr.first.end(),u-1)-tmpr.first.begin();
		}
		int pl = 0, pr = 0;
		while (pl<tmpl.first.size() && pr<tmpr.first.size()){
			if (tmpl.first[pl] < tmpr.first[pr]){
				ret1.push_back(tmpl.first[pl]);
				pl++;
			}
			else if (tmpl.first[pl] > tmpr.first[pr]){
				ret1.push_back(tmpr.first[pr]);
				pr++;
			}
			else{
				ret1.push_back(tmpr.first[pr]);
				pr++;	
				ret1.push_back(tmpl.first[pl]);
				pl++;
			}
		}
		while (pl<tmpl.first.size()){
			ret1.push_back(tmpl.first[pl]);
			pl++;
		}
		while (pr<tmpr.first.size()){
			ret1.push_back(tmpr.first[pr]);
			pr++;
		}
		return make_pair(ret1,ret2);
	}
}

const int maxn = 1e5+6, maxx = 3e5+6;
int n, m;
vector<int>c;
vector<int>w[maxn];
long long invc = 0;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	c.resize(n);
	for (int i=0; i<n; i++){
		cin >> c[i];
	}
	// ngitung inversion c
	pair<vector<int>,long long> hasil = countinversion(0,n-1,c);
	invc = hasil.second;
	c = hasil.first;
	for (int i=0; i<m; i++){
		int L;
		cin >> L;
		w[i].resize(L);
		for (int j=0; j<L; j++){
			cin >> w[i][j];
		}
	}
	for (int i=0; i<m; i++){
		int L = w[i].size();
		vector<int> invl(L), invr(L);
		for (int j=0; j<L; j++){
			invr[j] = c.end()-lower_bound(c.begin(),c.end(),w[i][j]+1);
			invl[j] = upper_bound(c.begin(),c.end(),w[i][j]-1)-c.begin();
		}
		long long ans = 1e18;
		long long pref = 0, suf = 0;
		for (int j=0; j<L; j++) suf += invr[j];
		for (int j=0; j<L; j++){
			ans = min(ans,pref+suf);
			pref += invl[j];
			suf -= invr[j];
		}
		ans = min(ans,pref+suf);
		auto tmp = countinversion(0,L-1,w[i]);
		ans += tmp.second;
		ans += invc;
		cout << ans << "\n";
	}
	return 0;
}
