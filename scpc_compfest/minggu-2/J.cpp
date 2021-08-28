#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long dp[2069][569];

void calc(){
    dp[0][0] = 1;
    for(int i=1; i<569; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<2069; i++){
        dp[i][0] = 0;
        for(int j=1; j<569; j++){
            dp[i][j] = 0;
            for(int k=1; k<10; k++){
                if(i-k>=0){dp[i][j] += dp[i-k][j-1];}
            }
            dp[i][j] %= mod;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t, n, m;
    cin >> t;
    calc();
    while(t--){
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
}
