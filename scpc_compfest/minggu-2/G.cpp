#include <bits/stdc++.h>
using namespace std;

long long divc(long long bil, long long but){
    return (bil + but - 1)/but;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin >> t;
    long long a, b, p, m, x, y, xp, ans;
    while(t--){
        cin >> a >> b >> p >> m;
        cin >> x >> y;
        ans = divc(x, a);
        xp = x*p/100;
        for(long long i=1; i<=x/a; i++){
            long long ysisa = max(0ll, y-i*b);
            if(b>0) {ans = min(ans, i + divc(x-i*a, (y-ysisa)*m));}
            if(x-i*a <= xp){
                ans = min(ans, i+1);
            }else if(b>0){
                ans = min(ans, i + divc(x-i*a-xp, (y-ysisa)*m) + 1);
            }
        }
        cout << ans << endl;
    }
}
