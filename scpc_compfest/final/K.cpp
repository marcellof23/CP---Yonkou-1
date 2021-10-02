#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
long long pangkat(long long a, long long b){
    b %= (mod-1);
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
    long long n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    long long ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    long long iris = 0;
    if(max(ax, bx) < min(ax, bx) + r){
        if(max(ay, by) < min(ay, by) + c){
            iris = (min(ax, bx) + r - max(ax, bx)) * (min(ay, by) + c - max(ay, by));
        }
    }
    if(ax == bx && ay == by){
        cout << pangkat(k, n*m) << endl;
    }else{
        cout << pangkat(k, r*c-iris) * pangkat(k, n*m - 2*r*c + iris) % mod << endl;
    }
	return 0;
}
