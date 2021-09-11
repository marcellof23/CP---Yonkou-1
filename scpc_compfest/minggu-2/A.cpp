#include <bits/stdc++.h>
using namespace std;

long long dp[8069][24], point[8069][5], fortopermi[256];

void init(){
    for(int i=0; i<2; i++){
        for(int j=0; j<24; j++){
            dp[i][j] = 0;
        }
        for(int j=0; j<5; j++){
            point[i][j] = 0;
        }
    }
    long long perm[4] = {0,1,2,3};
    for(int i=0; i<24; i++){
        fortopermi[64*perm[0] + 16*perm[1] + 4*perm[2] + perm[3]] = i;
        next_permutation(perm, perm+4);
    }
}
long long getpermi(long long a, long long b, long long c, long long d){
    return fortopermi[64*a + 16*b + 4*c + d];
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
            long long perm[4] = {0,1,2,3};
            for(int j=0; j<24; j++){
                //Ngitung poin yg didapet di taneman terakhir
                dp[i+2][j] = point[i+2][(int) ((i>1)&&(perm[1]<perm[3])) + ((i>0)&&(perm[2]<perm[3]))];
                //Ngitung perubahan poin dari taneman ke terakhir-1
                if((i>0) && (perm[3]<perm[2])){
                    dp[i+2][j] += point[i+1][(int) ((i>2)&&(perm[0]<perm[2])) + ((i>1)&&(perm[1]<perm[2])) + 1];
                    dp[i+2][j] -= point[i+1][(int) ((i>2)&&(perm[0]<perm[2])) + ((i>1)&&(perm[1]<perm[2]))];
                }
                //melihat tanaman terakhir-2
                long long prev[4], toAdd = 0, cur;
                for(int k=0; k<4; k++){
                    prev[0] = k;
                    for(int l=0; l<3; l++){
                        long long temp = perm[l] - (int)(perm[l]>perm[3]);
                        prev[l+1] = temp + (int)(temp>=k);
                    }
                    cur = dp[i+1][getpermi(prev[0], prev[1], prev[2], prev[3])];

                    //Pengen tahu update terakhir-2 = perm[1] atau prev[2]
                    if((i>1) && (perm[3]<perm[1])){
                        cur += point[i][(int) ((i>3)&&(prev[0]<prev[2])) + ((i>2)&&(prev[1]<prev[2])) + (perm[2] < perm[1]) + 1];
                        cur -= point[i][(int) ((i>3)&&(prev[0]<prev[2])) + ((i>2)&&(prev[1]<prev[2])) + (perm[2] < perm[1])];
                    }
                    toAdd = max(toAdd, cur);
                }
                dp[i+2][j]+=toAdd;
                //cout << perm[0] << perm[1] << perm[2] << perm[3] << " " << dp[i+2][j] << endl;
                next_permutation(perm, perm+4);
            }
        }
        long long ans=0;
        for(int i=0; i<24; i++){
            ans = max(ans, dp[n+1][i]);
        }
        cout << ans << endl;
    }
}
