#include <bits/stdc++.h>
using namespace std;

long long k, n, a, mod = 1e9+7;
long long dp[2][5050];

int main(){
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a;
        dp[i%2][0] = 1;
        if(i == 1){
            for(int j=1; j<5050; j++){
                dp[i%2][j] = 0;
            }
        }else{
            for(int j=1; j<5050; j++){
                dp[i%2][j] = (i-j)*dp[(i+1)%2][j-1]%mod + (j+1)*dp[(i+1)%2][j]%mod;
                dp[i%2][j] %= mod;
            }
        }
    }
    /*
    for(int i=1; i<5; i++){
        for(int j=0; j<5; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    */
    cout << dp[n%2][k] << endl;
}
