//#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
using namespace std;

const long long maxn = 252144;
long long segtree[2*maxn];

void build(){
    for(int i=1; i<2*maxn; i++){
        segtree[i] = 0;
    }
}
void update(long long idx, long long val){
    idx += maxn;
    while(idx>0){
        segtree[idx] += val;
        idx /= 2;
    }
}
long long query(long long lo, long long hi){
    lo += maxn; hi += maxn;
    long long ret = 0;
    while(hi>=lo){
        if(lo%2){
            ret += segtree[lo];
        }
        if(hi%2==0){
            ret += segtree[hi];
        }
        lo = (lo+1)/2;
        hi = (hi-1)/2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    build();
    long long n, p, ans;
    cin >> n;
    ans = 0;
    while(n--){
        cin >> p;
        ans += query(p+1, maxn-1);
        update(p, 1);
    }
    cout << ans << endl;
}
