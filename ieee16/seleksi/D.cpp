#include <bits/stdc++.h>

using namespace std;

const long long maxn = 131072, mod = 998244353;
long long n, a[2*maxn], pw2[2*maxn];
long long segtree[4*maxn], q, t, x;

void build(){
    for(int i=0; i<4*maxn; i++){
        segtree[i] = 0;
    }
}
void update(long long idx, long long val){
    idx += 2*maxn;
    segtree[idx] += val;
    idx /= 2;
    while(idx > 0){
        segtree[idx] += val;
        idx /= 2;
    }
}
long long query(long long lo, long long hi){
    lo += 2*maxn; hi += 2*maxn;
    long long toReturn = 0;
    while(lo <= hi){
        //cout << lo << " " << hi << " ";
        if(lo%2){
            toReturn += segtree[lo];
        } lo = (lo+1)/2;
        if(!(hi%2)){
            toReturn += segtree[hi];
        } hi = (hi-1)/2;
        //cout << toReturn << endl;
    }
    return toReturn;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pw2[0] = 1;
	for(int i=1; i<2*maxn; i++){
        pw2[i] = pw2[i-1] * 2 % mod;
	}
	cin >> n;
	for(int i=0; i<2*n; i++){
        cin >> a[i];
        a[i] = (a[i] % mod + mod) % mod;
	}
	build();
	cin >> q;
	while(q--){
        cin >> t >> x; t--;
        if(t){
            //cout << n-x << " " << n+x << endl;
            update(n-x, 1); update(n+x, -1);
        }else{
            x--;
            t = query(0, x);
            //cout << "t: " << t << endl;
            if(t%2){
                cout << pw2[t] * a[2*n-1-x] % mod << endl;
            }else{
                cout << pw2[t] * a[x] % mod << endl;
            }
        }
	}
}
