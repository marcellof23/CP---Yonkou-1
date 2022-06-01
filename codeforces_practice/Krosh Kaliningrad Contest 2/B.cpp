#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long mod = 1e9 + 7;

long long pangkat(long long a, long long b){
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    long long pre[n];
    pre[0] = 1;
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] * (k + i) % mod * inv(i) % mod;
    }
    long long ans = 0, x;
    for(int i=0; i<n; i++){
        cin >> x;
        ans += x * pre[i] % mod * pre[n-1-i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
