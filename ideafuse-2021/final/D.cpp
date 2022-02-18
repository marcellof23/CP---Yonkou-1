#include <bits/stdc++.h>
using namespace std;

int board[500][500];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m, k;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n >> m >> k;
        for(int j=0; j<m; j++){
            board[0][j] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<m; j++){
                cin >> board[i][j];
                board[i][j] += board[i-1][j];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n; j++){
                int k1=0, k2=0, sum=0;
                while(k2 < m){
                    if(sum + board[j][k2] - board[i][k2] <= k){
                        sum += board[j][k2] - board[i][k2];
                        k2++;
                        ans = max(ans, (k2-k1)*(j-i));
                    }else{
                        sum -= (board[j][k1] - board[i][k1]);
                        k1++;
                    }
                }
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
	return 0;
}
