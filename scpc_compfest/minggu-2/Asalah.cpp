#include <bits/stdc++.h>
using namespace std;

long long dp[8069][16], point[8069][5];

void init(){
    for(int i=0; i<2; i++){
        for(int j=0; j<16; j++){
            dp[i][j] = 0;
        }
        for(int j=0; j<5; j++){
            point[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t, n, a, b, c, d, e;
    cin >> t;
    while(t--){
        init();
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> point[i+2][0] >> point[i+2][1] >> point[i+2][2] >> point[i+2][3] >> point[i+2][4];
            for(int j=0; j<16; j++){
                if(j%2){
                    dp[i+2][j] = point[i+2][((j&4)>0) + ((j&2)>0)];
                    if((j&2)>0){
                        dp[i+2][j] += point[i+1][((j&8)>0) + ((j&4)>0) + 1] - point[i+1][((j&8)>0) + ((j&4)>0)];
                    }
                    long long com1 = dp[i+1][j/2];
                    long long com2 = dp[i+1][j/2 + 8];
                    if((j&4)>0){
                        com1 += point[i][((j&8)>0) + ((j&2)>0)+1] - point[i][((j&8)>0) + ((j&2)>0)];
                        com2 += point[i][((j&8)>0) + ((j&2)>0)+2] - point[i][((j&8)>0) + ((j&2)>0)+1];
                    }
                    dp[i+2][j] += max(com1, com2);

                }else{
                    dp[i+2][j] = max(dp[i+1][j/2], dp[i+1][j/2 + 8]);
                }
            }
        }
        long long ans=0;
        for(int i=0; i<16; i++){
            ans = max(ans, dp[n+1][i]);
        }
        cout << ans << endl;
    }
}
