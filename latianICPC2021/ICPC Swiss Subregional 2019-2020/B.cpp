#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long mod = 1000000007;
long long inv2 = 500000004, inv24 = 41666667;
long long forganjil[100069], forgenap[100069];

long long c2(long long x){
    return x*(x-1)/2%mod;
}
long long c3(long long x){
    return x*(x-1)*(x-2)%mod;
}
long long c4(long long x){
    return (x*(x-1)%mod) * ((x-2)*(x-3)%mod) % mod * inv24 % mod;
}

void init(){
    forganjil[0] = 1;
    forgenap[0] = 1;
    for(int i=1; i<100069; i++){
        if(i>=4){
            forgenap[i] = forgenap[i-4] * c3(i-1) % mod;
        }else{
            forgenap[i] = 0;
        }
        forganjil[i] = forganjil[i-1];
        if(i>=2){
            forganjil[i] = (forganjil[i] + forganjil[i-2] * (i-1)) % mod;
        }
        if(i>=4){
            forganjil[i] = (forganjil[i] + forganjil[i-4] * c3(i-1)) % mod;
        }
        /*
        if(i<10){
            cout << forganjil[i] << ' ' << forgenap[i] << endl;
        }
        */
    }
}
long long n, a[100069], cyclen[100069];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    init();
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        cyclen[i+1] = 0;
    }
    long long cur, len, next;
    for(int i=0; i<n; i++){
        if(a[i]>=0){
            cur = i;
            next = a[i];
            len = 1;
            while(next != i){
                a[cur] = -1;
                cur = next;
                next =  a[cur];
                len++;
            }
            a[cur] = -1;
            cyclen[len]++;
        }
    }
    long long ans = 1;
    for(int i=1; i<=n; i++){
        // cout << cyclen[i] << endl;
        if(i%2){
            ans = ans * forganjil[cyclen[i]] % mod;
        }else{
            ans = ans * forgenap[cyclen[i]] % mod;
        }
    }
    cout << ans << endl;
}
