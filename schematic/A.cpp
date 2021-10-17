#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
long long dp[1069][1069];

void pre(){
    for(int i=0; i<1069; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<1069; i++){
        for(int j=0; j<1069; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=i){
                dp[i][j] += dp[i][j-i];
                dp[i][j] %= mod;
            }
        }
    }
}

int main()
{
    pre();
    int T, M, N;
    cin >> T;
    while(T--){
        cin >> M >> N;
        cout << dp[N][M] << endl;
    }
}
