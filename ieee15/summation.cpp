#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
    if (b & 1)
        res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long p, q, n, m;
long long freq[1000009];
long long powpm[1000009];
int main(){
    cin >> p >> q >> n >> m;
    long long ans = 0;
    if(m<=1e6){
        long long mul = 1;
        long long temp = 0;
        for(int i=1; i<=m; i++){
            mul = (mul*p)%m;
            temp = (temp + mul*binpow(i,q,m))%m;
        }
        // mau itung 1 + mul + mul**2 + mul**3, yakni mul1
        for(int i=0; i<m; i++){
            freq[i] = -1;
        }
        long long mul2 = (mul*mul)%m;
        long long period=1, sumperiod=mul;
        while(mul2!=mul){
            sumperiod = (sumperiod+mul2)%m;
            mul2 = mul2*mul%m;
            period++;
        }// yey nemu
        long long totsuku = n/m;
        long long totperiod = (n/m-1)/period;
        long long totmul = (totperiod*sumperiod)%m;
        mul2 = 1;
        for(int i=0; i<totsuku - totperiod*period; i++){
            totmul = (totmul + mul2)%m;
            mul2 = mul2*mul%m;
        }

        ans = (totmul*temp)%m;

        mul = binpow(p, n/m*m, m);
        for(int i=n/m*m+1; i<=n; i++){
            mul = mul*p%m;
            ans = (ans + mul*binpow(i%m, q, m))%m;
        }
    }else{//n<=1e6
        long long mul = 1;
        for(int i=1; i<=n; i++){
            mul = (mul*p)%m;
            ans += mul*binpow(i,q,m)%m;
            ans %= m;
        }
    }
    cout << ans << endl;
}
