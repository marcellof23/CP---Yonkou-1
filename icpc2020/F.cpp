#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+6, maxx = 3e5+6;
int n, m;
vector<int>c;
vector<int>w[maxn];
set<int>semua;
map<int,int>compress;
long long invc = 0;
long long bit[maxx];

long long query(int pos){
	long long ret = 0;
	while (pos>0){
		ret += bit[pos];
		pos -= pos&-pos;
	}
	return ret;
}

void update(int pos){
	while (pos<maxx){
		bit[pos]++;
		pos += pos&-pos;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	c.resize(n);
	w.resize(m);
	for (int i=0; i<n; i++){
		cin >> c[i];
		semua.insert(c[i]);
	}
	sort(c.begin(),c.end());
	for (int i=0; i<m; i++){
		int L;
		cin >> L;
		w[i].resize(L);
		for (int j=0; j<m; j++){
			cin >> w[i][j];
			semua.insert(w[i][j]);
		}
	}
	// compress
	int id = 0;
	for (int u : semua){
		compress[u] = id;
		id++;
	}
	for (int i=0; i<n; i++) c[i] = compress[c[i]];
	for (int i=0; i<m; i++){
		for (int j=0; j<(int)w[i].size(); j++){
			w[i][j] = compress[w[i][j]];
		}
	}
	memset(bit,0,sizeof bit);
	for (int i=0; i<n; i++){
		invc += sum(maxx)-sum(c[i]);
		update(c[i]);
	}
	for (int i=0; i<m; i++){
		int L = w[i].size();
		vector<int> invl(), invr(L);
		for (int j=0; j<L; i++){
			invr[i] = c.end()-lower_bound(c.begin(),c.end(),w[i][j]+1);
			invl[i] = upper_bound(c.begin(),c.end(),w[i][j]-1)-c.begin();
		}
		int ans = 1e9;
		int pref = 0, suf = 0;
		for (int i=0; i<L; i++) suf += invr[i];
		for (int i=0; i<L; i++){
			cout << "taruh di antara " << i-1 << " dan " << i << " costnya " << pref << "+" << suf << "=" << pref+suf << "\n";
			ans = min(ans,pref+suf);
			pref += invl[i];
			suf -= invr[i];
		}
		ans = min(ans,pref+suf) + invc;
		
		// cout << ans << "\n";

	}
}