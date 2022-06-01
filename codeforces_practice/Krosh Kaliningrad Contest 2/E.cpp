#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long mod = 1e9+7;
long long dp[25][300069], pre[300069];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=0; i<300069; i++){
        dp[1][i] = 1;
    }
    long long n, mul = 3;
    cin >> n;
    for(int i=2; i<25; i++){
        for(int j=0; j<300069; j++){
            if(j<mul){
                pre[j] = dp[i-1][j];
            }else{
                pre[j] = (pre[j-mul] + dp[i-1][j])%mod;
            }
        }
        for(int j=0; j<300069; j++){
            dp[i][j] = pre[j];
        }
        mul = mul*2 + 1;
    }
    cout << dp[24][n] << endl;
}
