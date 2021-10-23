#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, ans;
    long long t, n, r, mx=0, nb=0;
    cin >> t;
    while(t--){
        cin >> s >> n >> r;
        if(r>mx){
            ans = s;
            mx = r;
            nb = 1;
        }else if(r == mx){
            nb++;
        }
    }
    if(nb>1){
        cout << "SERI" << endl;
    }else{
        cout << ans << endl;
    }
}
