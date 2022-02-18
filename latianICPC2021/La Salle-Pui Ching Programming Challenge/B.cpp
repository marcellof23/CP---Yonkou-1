#include <bits/stdc++.h>
using namespace std;

long long pecahan[100069][2];
long long h[1000069];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cout << __gcd(1ll, 0ll) << endl;
    long long n, tot=0, ans=0;
    cin >> n;
    for(int sum=1; tot+sum<=n; sum++){
        for(int bil=0; bil<=sum && tot+sum<=n; bil++){
            if(abs(__gcd(bil, sum-bil) == 1)){
                tot += sum;
                pecahan[ans][0] = bil;
                pecahan[ans][1] = sum-bil;
                ans++;
            }
        }
    }
    cout << ans << endl;
    // cout << pecahan[1][0] << pecahan[1][1] << endl;
    pair<double, int> pdi[ans];
    for(int i=1; i<ans; i++){
        pdi[i] = {(double) pecahan[i][1]/pecahan[i][0], i};
    }
    sort(pdi+1, pdi+ans);
    h[0] = 0;
    long long cur = 0, idx = 1;
    for(int i=1; i<ans; i++){
        //cout << pecahan[pdi[i].second][0] << ' ' << pecahan[pdi[i].second][1] << endl;
        for(int j=0; j<pecahan[pdi[i].second][1]; j++){
            h[idx] = cur;
            idx++;
        }
        for(int j=0; j<pecahan[pdi[i].second][0]; j++){
            cur++;
            h[idx] = cur;
            idx++;
        }
    }
    for(int i=idx; i<=n; i++){
        h[i] = cur;
    }
    for(int i=n; i>=0; i--){
        cout << h[i] << ' ';
    }cout << endl;
}
