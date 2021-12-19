#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long k, l, n, p, mod = 1000000007;
long long dif[2][1000], t[1000][1000];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> k >> l;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cin >> t[i][j];
        }
    }
    cin >> n;
    dif[0][0] = 1;
    for(int i=1; i<k; i++){
        dif[0][i] = 0;
    }
    dif[0][k] = -1;
    long long cur, lo, hi, mid;
    for(int i=1; i<n; i++){
        for(int j=0; j<k; j++){
            dif[i%2][j] = 0;
        }
        cin >> p;
        cur = 0;
        for(int j=0; j<k; j++){
            //cout << dif[(i+1)%2][j] << ' ';
            cur += dif[(i+1)%2][j];
            cur %= mod;
            lo = -1; hi = k-1;
            while(hi-lo>1){
                mid = (hi+lo+1)/2;
                if(t[j][mid] < p-l){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            if(t[j][hi] < p-l){
                hi++;
            }
            //cout << hi << ' ';
            dif[i%2][hi] += cur;
            dif[i%2][hi] %= mod;
            lo = 0; hi = k;
            while(hi-lo>1){
                mid = (hi+lo)/2;
                if(t[j][mid] <= p+l){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            if(t[j][lo] > p+l){
                hi--;
            }
            //cout << hi << endl;
            dif[i%2][hi] += mod-cur;
            dif[i%2][hi] %= mod;
        }
        //cout << endl;
    }
    long long ans = 0; cur = 0;
    for(int i=0; i<k; i++){
        cur += dif[(n-1)%2][i];
        cur %= mod;
        ans += cur;
        ans %= mod;
    }
    cout << ans << endl;
}
