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

long long ans=0;
long long n, a[8], b, ex[8];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<8; i++){
        cin >> a[i];
        ex[i] = 0;
    }
    for(int i=0; i<4; i++){
        cin >> b;
        ex[b-1] = 1;
    }
    long long tiga = 3*mod_inv(4);
    long long satu = mod_inv(4);
    while(n--){
        for(int i=0; i<8; i++){
            ans = (ans + a[i]*ex[i])%mod;
        }
        for(int i=0; i<8; i++){
            long long t = ex[i];
            ex[i] = (t*tiga%mod + (mod+1-t)*satu%mod)%mod;
        }
    }
    cout << ans*satu%mod << endl;
}
