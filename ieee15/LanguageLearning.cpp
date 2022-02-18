#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int t, n, k;
int a[100069], dp[200069], sumdp[200069], last[100069];

int main() {
    cin >> t;
    while(t--){
        cin >> n >> k;
        map<string, int> msi;
        int id = 0;
        for (int i=0; i<n; i++){
            string s;
            cin >> s;
            if (!msi.count(s)){
                msi[s] = id;
                last[id] = 0;
                id++;
            }
            a[i] = msi[s];
        }
        sumdp[0] = 0;
        dp[0] = 1;
        sumdp[1] = 1;
        for(int i=1; i<=k; i++){
            dp[i] = 0;
            sumdp[i+1] = 1;
        }
        for(int i=0; i<n; i++){
            dp[k+1+i] = (sumdp[i+1] - sumdp[last[a[i]]] + mod)%mod;
            last[a[i]] = i+1;
            sumdp[k+2+i] = (sumdp[k+1+i] + dp[k+1+i])%mod;
        }
        cout << (sumdp[n+k+1]+mod-1)%mod << endl;
    }
}
